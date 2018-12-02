#include <vtkConeSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSmartPointer.h>

// Since version 6, VTK has modules which requires initialzation. This is 
// performed automatically by CMake when used to build applications. If you do 
// not use CMake you have to #include and call VTK_MODULE_INIT in any compilation
// unit in order to avoid errors (i.e.: "Error: no override found for something")
#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL2);   // init rendering module
VTK_MODULE_INIT(vtkInteractionStyle);   // init interaction module

// In the following lessons, this code will be included in util.cxx

int main() {

    // 1. Create a pipeline for a prop to display on screen
    // A pipeline is:
    //      Data -> Filter1 ... FilterN -> Mapper -> Actor
    // In this case, we do not have data, for that reason we use a Source to
    // generate it. No filters will be used so the pepeline will be:
    //      Source -> Mapper -> Actor
    auto coneSource = vtkSmartPointer<vtkConeSource>::New();    // Creates a Source

    auto pdMapper = vtkSmartPointer<vtkPolyDataMapper>::New();

    // Connects Source to Mapper
    pdMapper->SetInputConnection(coneSource->GetOutputPort());  

    auto actor = vtkSmartPointer<vtkActor>::New();

    // Connects Mapper to Actor
    actor->SetMapper(pdMapper);             

    // 2. The VTK window is a RenderWindow with at least one Renderer object.
    // To provide interaction with the prop on screen, you can create a 
    // RenderWindowInteractor and set its RenderWindow.
    // It looks like:
    //      (Interactor->) Window -> Renderer1 ... RendererN
    auto renderer = vtkSmartPointer<vtkRenderer>::New();

    // Configure the Renderer as you like
    renderer->SetBackground(.1, .2, .3);

    // Add your actor(s) to Renderer  
    renderer->AddActor(actor);              

    auto window = vtkSmartPointer<vtkRenderWindow>::New();

    // Add Renderer to Window
    window->AddRenderer(renderer);          

    auto intereactor = vtkSmartPointer<vtkRenderWindowInteractor>::New();

    // Set WindowInteractor window to our window
    intereactor->SetRenderWindow(window);

    // Starts events processing and rendering  
    intereactor->Start();                   
    
    return EXIT_SUCCESS;
}