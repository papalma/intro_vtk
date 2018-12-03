// Based on https://www.vtk.org/Wiki/VTK/Tutorials/TriangleGeometryLines
#include <vtkCellArray.h>
#include <vtkLine.h>
#include <vtkPoints.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkSmartPointer.h>

#include "util.h"

int main()
{
    // Setup geometry (points)
    auto points = vtkSmartPointer<vtkPoints>::New();
    points->InsertNextPoint ( 1.0, 0.0, 0.0 );
    points->InsertNextPoint ( 0.0, 0.0, 1.0 );
    points->InsertNextPoint ( 0.0, 0.0, 0.0 );

    // Create a line cell (topology) between each pair of points
    auto line0 = vtkSmartPointer<vtkLine>::New();
    line0->GetPointIds()->SetId ( 0,0 );
    line0->GetPointIds()->SetId ( 1,1 );

    auto line1 = vtkSmartPointer<vtkLine>::New();
    line1->GetPointIds()->SetId ( 0,1 );
    line1->GetPointIds()->SetId ( 1,2 );

    auto line2 = vtkSmartPointer<vtkLine>::New();
    line2->GetPointIds()->SetId ( 0,2 );
    line2->GetPointIds()->SetId ( 1,0 );

    // create a cell array to store the line in
    auto  lines = vtkSmartPointer<vtkCellArray>::New();
    lines->InsertNextCell ( line0 );
    lines->InsertNextCell ( line1 );
    lines->InsertNextCell ( line2 );

    //create a polydata to store everything in
    auto polydata = vtkSmartPointer<vtkPolyData>::New();

    //add the points and lines to the polydata
    polydata->SetPoints( points );
    polydata->SetLines( lines );

    // finish polydata pipeline
    auto mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputData(polydata);

    auto actor = vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);

    // displaying section
    auto renderer = vtkSmartPointer<vtkRenderer>::New();
    renderer->AddActor(actor);

    CreateWindow(renderer);

    return EXIT_SUCCESS;
}