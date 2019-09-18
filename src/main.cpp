#include "main.hpp"

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
	for(auto layer: lattice)
	{
		for(auto column : layer)
		{
			for(auto tile : column)
			{
				for(auto direction : tile)
				{
					for(size_t i{1}; i < mesh->num_tris(); ++i)
					{
						direction.intersect(mesh, i);
					}
					direction.write(points, lines);
				}
			}
		}
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