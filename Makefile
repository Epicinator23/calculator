# Target executable
all: main

# Rule to create the executable from object files
main: main.o calculations.o ActionData.o MenuData.o Matrix.o user_io.o
	g++ -o main main.o calculations.o ActionData.o MenuData.o Matrix.o user_io.o

# Rule to compile main.c into main.o
main.o: main.cpp functions.h
	g++ -c main.cpp

# Rule to compile calculations.c into calculations.o
calculations.o: calculations.cpp functions.h ActionData.h
	g++ -c calculations.cpp

ActionData.o: ActionData.cpp ActionData.h
	g++ -c ActionData.cpp

MenuData.o: MenuData.cpp MenuData.h
	g++ -c MenuData.cpp

Matrix.o: Matrix.cpp Matrix.h
	g++ -c Matrix.cpp

user_io.o: user_io.cpp functions.h
	g++ -c user_io.cpp

# Clean up object files and executable
clean:
	rm -f main *.o
