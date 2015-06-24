# All object files that must be linked into final executable.
OBJ=  vector.o main.o

# Rule for building executable from object files
# $@ is shorthand for the target of the rule
# use -o option to specify another name
main: ${OBJ}
	c++ -o $@ ${OBJ}

# Rule for compiling individual source files into object files
# $< is shorthand for the first prerequisite
# use -c option to only create an object file which has a .o extension
${OBJ}: %.o: %.cc
	c++ -c $<

# Rule to clean up all output files
clean:
	rm -f main ${OBJ}


