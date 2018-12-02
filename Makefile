CPP = clang++
INCDIR = -I $(VTKDIR)/include/vtk-8.1
LIBDIR = -L $(VTKDIR)/lib
VTKLIB = \
-l vtksys-8.1 \
-l vtkCommonCore-8.1 \
-l vtkCommonSystem-8.1 \
-l vtkCommonDataModel-8.1 \
-l vtkCommonExecutionModel-8.1 \
-l vtkRenderingCore-8.1 \
-l vtkRenderingOpenGL2-8.1 \
-l vtkFiltersCore-8.1 \
-l vtkFiltersSources-8.1 \
-l vtkInteractionStyle-8.1

CPPFLAGS += -std=c++11 -Wall $(INCDIR) 
LDFLAGS += -l stdc++ $(LIBDIR) $(VTKLIB) 

%.o: %.cxx
	$(CPP) -c $(CPPFLAGS) $< -o $@

.PHONY:
all: lesson1 lesson2 lesson3

lesson1: lesson1.o

lesson2: lesson2.o util.o

lesson3: lesson3.o util.o

.PHONY:
clean:
	rm -f *.o lesson1 lesson2 lesson3