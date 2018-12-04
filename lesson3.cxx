// Based in code presented at https://www.vtk.org/Wiki/VTK/Tutorials/TriangleGeometryVertices

// This is an improved version of the previous program. This uses the same 
// points used for the previous example, but it uses a filter to draw a cube on 
// each point and make it easy to view.

#include <vtkActor.h>
#include <vtkCellArray.h>
#include <vtkCubeSource.h>
#include <vtkGlyph3D.h>
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

    // Create a polydata object and set points and vertices (geometry and topology)
    auto polydata = vtkSmartPointer<vtkPolyData>::New();
    polydata->SetPoints( points );
    polydata->SetVerts( vertices );

    // Create a Glyph filter to put cubes in each point and easily visualize 
    // each point.
    auto glyph = vtkSmartPointer<vtkGlyph3D>::New();

    // Create and configure the Glyph, in this case a cube.
    auto cube = vtkSmartPointer<vtkCubeSource>::New();
    cube->SetBounds(.0, .3, .0, .3, .0, .3);

    // Configure the Glyph filter
    glyph->SetInputData(0, polydata);
    glyph->SetInputConnection(1, cube->GetOutputPort());

    // Construct pipeline to display polydata
    auto mapper = vtkSmartPointer<vtkPolyDataMapper>::New();

    // Connects the filter to the mapper
    mapper->SetInputConnection(glyph->GetOutputPort());

    auto actor = vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);

    // Create and configure a Renderer
    auto renderer = vtkSmartPointer<vtkRenderer>::New();
    renderer->AddActor(actor);              

    CreateWindow(renderer);

    return EXIT_SUCCESS;
}