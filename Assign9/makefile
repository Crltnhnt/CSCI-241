# Compiler variables
CCFLAGS = -ansi -Wall -std=c++11

# Rule to link object code files to create executable file
assign9: assign9.o Shape.o Cone.o Circle.o Cylinder.o
	g++ $(CCFLAGS) -o assign9 assign9.o Shape.o Cone.o Circle.o Cylinder.o

# Rule to compile source code file to object code
assign9.o: assign9.cpp Shape.h Cone.h Circle.h Cylinder.h
	g++ $(CCFLAGS) -c assign9.cpp

# Rule to compile source code file to object code
Shape.o: Shape.cpp Shape.h
	g++ $(CCFLAGS) -c Shape.cpp

# Rule to compile source code file to object code
Cone.o: Cone.cpp Cone.h
	g++ $(CCFLAGS) -c Cone.cpp

# Rule to compile source code file to object code
Cylinder.o: Cylinder.cpp Cylinder.h
	g++ $(CCFLAGS) -c Cylinder.cpp

# Rule to compile source code file to object code
Circle.o: Circle.cpp Circle.h
	g++ $(CCFLAGS) -c Circle.cpp

# May need to add header file dependency
# something like???
#
# Cylinder.h: Shape.h Circle.h

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign9
