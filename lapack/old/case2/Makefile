BS=-L/Users/julie/opt/mylib -llapacke -llapack -lrefcblas -lrefblas
IDIR =/Users/julie/opt/mylib
CXX=g++
CXXFLAGS=-I$(IDIR) -DHAVE_LAPACK_CONFIG_H -DLAPACK_COMPLEX_CPP
DEPS = lapacke.h
OBJ = prog.o

%.o: %.cpp $(DEPS)
$(CXX) -c -o $@ $< $(CXXFLAGS)

prog.exe: $(OBJ)
gfortran -o $@ $^ $(CXXFLAGS) $(LIBS) -lc++

run : prog.exe
./prog.exe

clean:
rm -f *.o *.exe *~ core 
