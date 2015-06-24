include $(HOME)/Downloads/lapack-3.5.0/make.inc

all: main

CBLASLIB = /usr/local/atlas/lib/libcblas.a
ATLASLIB = /usr/local/atlas/lib/libatlas.a

LIBRARIES= $(LAPACKELIB) $(LAPACKLIB) $(BLASLIB) $(CBLASLIB) $(ATLASLIB)

# executable
main: main.o $(LIBRARIES)
	$(LOADER) $(LOADOPTS)  main.o \
	$(LIBRARIES) -o $@
	./$@

# addition by preyas: similar to his makefile
#main: main.o
#	$(CC) -o $@ main.o

# dependencies
.cpp.o:
	$(CC) -c $(CFLAGS) -I $(LAPACKE_DIR)/include -o $@ $<

# clean
clean:
	rm -f *.o main


