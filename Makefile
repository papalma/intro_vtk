CPP = clang++
ifdef VTKVER
	VTKVER := $(VTKVER)
else
	VTKVER := 8.1
endif

INCDIR = -I $(VTKDIR)/include/vtk-$(VTKVER)
LIBDIR = -L $(VTKDIR)/lib

VTKLIB = \
-l vtksys-$(VTKVER) \
-l vtkCommonCore-$(VTKVER) \
-l vtkCommonSystem-$(VTKVER) \
-l vtkCommonDataModel-$(VTKVER) \
-l vtkCommonExecutionModel-$(VTKVER) \
-l vtkRenderingCore-$(VTKVER) \
-l vtkRenderingOpenGL2-$(VTKVER) \
-l vtkFiltersCore-$(VTKVER) \
-l vtkFiltersSources-$(VTKVER) \
-l vtkIOLegacy-$(VTKVER) \
-l vtkFiltersGeometry-$(VTKVER) \
-l vtkInteractionStyle-$(VTKVER)

CPPFLAGS += -std=c++11 -Wall $(INCDIR) 
LDFLAGS += -l stdc++ $(LIBDIR) $(VTKLIB) 

%.o: %.cxx
	$(CPP) -c $(CPPFLAGS) $< -o $@

.PHONY:
all: lesson1 lesson2 lesson3 lesson4 lesson5

lesson1: lesson1.o

lesson2: lesson2.o util.o

lesson3: lesson3.o util.o

lesson4: lesson4.o util.o

lesson5: lesson5.o util.o

util.o: util.cxx util.h

.PHONY:
clean:
	rm -f *.o lesson[12345]