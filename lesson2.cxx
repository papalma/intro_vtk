// Based in code presented at https://www.vtk.org/Wiki/VTK/Tutorials/TriangleGeometryVertices

// This program will draw three points (triangle corners) on screen. They are
// really tiny.

#include <vtkActor.h>
#include <vtkCellArray.h>
#include <vtkPoints.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkRenderer.h>
#include <vtkSmartPointer.h>

#include "util.h"

int main(int argc, char *argv[])
{
    // Setup point coordinates
    double X[3] = {1.0, 0.0, 0.0};
    double Y[3] = {0.0, 0.0, 1.0};
    double Z[3] = {0.0, 0.0, 0.0};

    // Create points and add a vertex cell at each point
    auto points = vtkSmartPointer<vtkPoints>::New();
    auto vertices = vtkSmartPointer<vtkCellArray>::New();

    for ( unsigned int i = 0; i < 3; ++i ) {
        // Declare a variable to store the index of the point that gets added. 
        vtkIdType pid;
        
        // Add a point to the polydata and save its index, which we will use to 
        // create the vertex on that point.
        pid = points->InsertNextPoint(X[i], Y[i], Z[i]);
        
        // Create a vertex cell on the point that was just added.
        vertices->InsertNextCell(1, &pid);
    }

    // Create a polydata object
    auto polydata = vtkSmartPointer<vtkPolyData>::New();

    // Set the points and vertices we created as the geometry and topology of
    // the polydata
    polydata->SetPoints( points );
    polydata->SetVerts( vertices );

    // Construct pipeline to display polydata
    auto mapper = vtkSmartPointer<vtkPolyDataMapper>::New();

    // IMPORTANT: notice that when using a DataObject directly you have to pass
    // it. This is different when data is generated from a source or produced
    // from a filter, in that cases use SetInputConnection() and GetOutputPort()
    mapper->SetInputData(polydata);

    auto actor = vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);

    // Create and configure a Renderer
    auto renderer = vtkSmartPointer<vtkRenderer>::New();
    renderer->AddActor(actor);              

    CreateWindow(renderer);

    return EXIT_SUCCESS;
}