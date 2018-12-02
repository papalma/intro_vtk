// Based in code presented at https://www.vtk.org/Wiki/VTK/Tutorials/TriangleGeometryVertices
#include <vtkActor.h>
#include <vtkCellArray.h>
#include <vtkPoints.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSmartPointer.h>

#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL2);   // init rendering module
VTK_MODULE_INIT(vtkInteractionStyle);   // init interaction module

void CreateWindow(vtkSmartPointer<vtkRenderer> renderer) {
    
    renderer->SetBackground(.1, .2, .3);

    // Create and configure window and interactor
    auto window = vtkSmartPointer<vtkRenderWindow>::New();
    window->AddRenderer(renderer);          
    auto intereactor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
    intereactor->SetRenderWindow(window);

    // Starts events processing and rendering  
    intereactor->Start();   
}