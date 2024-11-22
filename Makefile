# Target executable
all: main

# Rule to create the executable from object files
main: main.o calculations.o ActionData.o
	g++ -o main main.o calculations.o ActionData.o

# Rule to compile main.c into main.o
main.o: main.cpp calculations.h
	g++ -c main.cpp

# Rule to compile calculations.c into calculations.o
calculations.o: calculations.cpp calculations.h ActionData.h
	g++ -c calculations.cpp

ActionData.o: ActionData.cpp ActionData.h
	g++ -c ActionData.cpp

# Clean up object files and executable
clean:
	rm -f main *.o
