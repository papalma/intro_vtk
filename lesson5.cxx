// This is a .vtk file viewer
// Test files can be found at https://www.vtk.org/vtk-textbook-examples-and-data/
#include <vtkDataObject.h>
#include <vtkDataSetMapper.h>
#include <vtkGenericDataObjectReader.h>
#include <vtkImageDataGeometryFilter.h>
#include <vtkPolyDataMapper.h>
#include <vtkSmartPointer.h>

#include "util.h"

int main(int argc, char* argv[])
{
    if(argc!=2) {
        std::cout << "Provide a vtk data file.\n";
        return EXIT_FAILURE;
    }

    auto reader = vtkSmartPointer<vtkGenericDataObjectReader>::New();

    if(argv[1]==nullptr) {
        std::cout << "No input file.\n";
        return EXIT_FAILURE;
    }

    reader->SetFileName(argv[1]);
    reader->Update();

    auto actor = vtkSmartPointer<vtkActor>::New();

    if( reader->IsFilePolyData() ) {
        auto mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
        mapper->SetInputConnection(reader->GetOutputPort());
        actor->SetMapper(mapper);
    }
    else if( reader->IsFileStructuredPoints() ) {
        auto filter = vtkSmartPointer<vtkImageDataGeometryFilter>::New();
        filter->SetInputConnection(reader->GetOutputPort());

        auto mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
        mapper->SetInputConnection(filter->GetOutputPort());

        actor->SetMapper(mapper);
    }
    else if( reader->IsFileStructuredGrid() ) {
        auto mapper = vtkSmartPointer<vtkDataSetMapper>::New();
        mapper->SetInputConnection(reader->GetOutputPort());

        actor->SetMapper(mapper);
    }
    else {
        auto data = reader->GetOutput();
        std::cout << data->GetClassName() << '\n';
        std::cout << "Support for this file has not been implemented yet.\n";
        return EXIT_FAILURE;
    }

    // displaying section
    auto renderer = vtkSmartPointer<vtkRenderer>::New();
    renderer->AddActor(actor);

    CreateWindow(renderer);

    return EXIT_SUCCESS;
}