#include "main.hpp"

stl_reader::StlMesh<float, unsigned int>* load_mesh(std::string filename)
{
	stl_reader::StlMesh<float, unsigned int>* mesh{new stl_reader::StlMesh{filename}};
	if(mesh->num_solids() > 1)
	{
		std::cerr << "Only STL files with 1 solid are supported" << std::endl;
	}
	return mesh;
}

void write_lattice(std::vector<std::pair<vec, vec>>& output)
{
	vtkSmartPointer<vtkPoints> points{vtkSmartPointer<vtkPoints>::New()};
	vtkSmartPointer<vtkCellArray> lines{vtkSmartPointer<vtkCellArray>::New()};
	unsigned int pointCounter{0};
	for(auto arrow: output)
	{
		points->InsertNextPoint(arrow.first[0], arrow.first[1], arrow.first[2]);
		points->InsertNextPoint(arrow.second[0], arrow.second[1], arrow.second[2]);

		vtkSmartPointer<vtkLine> line{vtkSmartPointer<vtkLine>::New()};
		line->GetPointIds()->SetId(0, pointCounter);
		line->GetPointIds()->SetId(1, pointCounter + 1);
		lines->InsertNextCell(line);
		pointCounter += 2;
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
}

std::pair<vec, vec> find_aabb(stl_reader::StlMesh<float, unsigned int>* mesh, size_t ti)
{
	vec corner0{stlToVec(mesh->tri_corner_coords(ti, 0))};
	vec corner1{stlToVec(mesh->tri_corner_coords(ti, 1))};
	vec corner2{stlToVec(mesh->tri_corner_coords(ti, 2))};

	vec minimum{std::min(std::min(corner0[0], corner1[0]), corner2[0]), std::min(std::min(corner0[1], corner1[1]), corner2[1]), std::min(std::min(corner0[2], corner1[2]), corner2[2])};
	vec maximum{std::max(std::max(corner0[0], corner1[0]), corner2[0]), std::max(std::max(corner0[1], corner1[1]), corner2[1]), std::max(std::max(corner0[2], corner1[2]), corner2[2])};

	return {minimum, maximum};
}

int main()
{
	stl_reader::StlMesh<float, unsigned int>* mesh{load_mesh("teapot.stl")};
	const Lattice lattice{-10, 10, -10, 10, -10, 10, 1};

	std::vector<std::pair<vec, vec>> output{};
	output.reserve(lattice.getNumRows() * lattice.getNumCols() * lattice.getNumLayers() * 26);

	//std::vector<std::thread> threads{};
	//std::mutex m{};
	//for(int threadId{0}; threadId < std::thread::hardware_concurrency(); ++threadId)
	//{
		//threads.push_back(std::thread{[&lattice, threadId, &mesh, &output, &m] ()
		//{
	for(size_t ti{1}; ti < mesh->num_tris(); ++ti)
	{
		std::pair<vec, vec> aabb = find_aabb(mesh, ti);
			SubLattice* subLattice{lattice.intersect(aabb)};
			for(auto layer: *subLattice)
			{
				for(auto column : layer)
				{
					for(auto tile : column)
					{
						for(auto direction : tile)
						{
							direction.intersect(mesh, ti);
							//m.lock();
							direction.write(output);
							//m.unlock();
						}
					}
				}
			}
	}

		//}});
	//}
	//for(auto thread{threads.begin()}; thread < threads.end(); ++thread)
	//{
		//thread->join();
	//}

	write_lattice(output);
    return 0;
}