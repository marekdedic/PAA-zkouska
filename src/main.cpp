#include "main.hpp"

vec StlToVec(const float* stlVec)
{
	return {*stlVec, *(stlVec + 1), *(stlVec + 2)};
}

vec vecMinus(vec a, vec b)
{
	return {a[0] - b[0], a[1] - b[1], a[2] - b[2]};
}
float scalarProduct(vec a, vec b)
{
	return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

float intersect(vec planePoint, vec linePoint, vec planeNormal, vec lineVec)
{
	float denominator{scalarProduct(lineVec, planeNormal)};
	if(denominator == 0)
	{
		return 0;
	}
	return scalarProduct(vecMinus(planePoint, linePoint), planeNormal) / denominator;
}

int main()
{
	stl_reader::StlMesh<float, unsigned int>* mesh{new stl_reader::StlMesh{"teapot.stl"}};
	if(mesh->num_solids() > 1)
	{
		std::cerr << "Only STL files with 1 solid are supported" << std::endl;
		return -1;
	}
	vtkSmartPointer<vtkPoints> points{vtkSmartPointer<vtkPoints>::New()};
	vtkSmartPointer<vtkCellArray> lines{vtkSmartPointer<vtkCellArray>::New()};
	const Lattice lattice{-10, 10, -10, 10, -10, 10, 1};

	std::vector<std::thread> threads{};
	threads.reserve(lattice.getNumRows() * lattice.getNumCols() * lattice.getNumLayers());
	std::mutex m{};
	for(auto layer: lattice)
	{
		for(auto column : layer)
		{
			for(auto tile : column)
			{
				for(auto direction : tile)
				{
					threads.push_back(std::thread{[&direction, &points, &lines, &m] (stl_reader::StlMesh<float, unsigned int>* mesh)
					{
						direction.intersectAll(mesh);
						m.lock();
						direction.write(points, lines);
						m.unlock();
						}, mesh});

				}
			}
		}
	}
	for(auto thread{threads.begin()}; thread < threads.end(); ++thread)
	{
		thread->join();
	}
	vtkSmartPointer<vtkPolyData> linePolyData{vtkSmartPointer<vtkPolyData>::New()};
	linePolyData->SetPoints(points);
	linePolyData->SetLines(lines);

	vtkSmartPointer<vtkAppendFilter> appendFilter{vtkSmartPointer<vtkAppendFilter>::New()};
	appendFilter->AddInputData(linePolyData);
	appendFilter->Update();
	vtkSmartPointer<vtkUnstructuredGrid> grid{vtkSmartPointer<vtkUnstructuredGrid>::New()};
	grid->ShallowCopy(appendFilter->GetOutput());

	vtkSmartPointer<vtkUnstructuredGridWriter> writer{vtkSmartPointer<vtkUnstructuredGridWriter>::New()};
	writer->SetFileName("output.vtk");
	writer->SetInputData(grid);
	writer->Write();
    return 0;
}