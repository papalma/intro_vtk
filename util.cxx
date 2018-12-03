// Based in code presented at https://www.vtk.org/Wiki/VTK/Tutorials/TriangleGeometryVertices
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSmartPointer.h>

// Check lesson1.cxx to know why this code is here and only here
#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL2);   // init rendering module
VTK_MODULE_INIT(vtkInteractionStyle);   // init interaction module

void CreateWindow(vtkSmartPointer<vtkRenderer> renderer) {
    
    renderer->SetBackground(.4, .4, 1.0);

    // Create and configure window and interactor
    auto window = vtkSmartPointer<vtkRenderWindow>::New();
    window->AddRenderer(renderer);  
            
    auto intereactor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
    intereactor->SetRenderWindow(window);

    // Starts events processing and rendering  
    intereactor->Start();   
}