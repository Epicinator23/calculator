# Target executable
all: program

# Rule to create the executable from object files
program: main.o calculations.o
	gcc -o program main.o calculations.o -lm

# Rule to compile main.c into main.o
main.o: main.c calculations.h
	gcc -c main.c

# Rule to compile calculations.c into calculations.o
calculations.o: calculations.c calculations.h
	gcc -c calculations.c

# Clean up object files and executable
clean:
	rm -f program main.o calculations.o
