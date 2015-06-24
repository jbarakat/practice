06/22/2015 - probably won't compile as is... need to edit the directories in the Makefile

Downloaded from
http://icl.cs.utk.edu/lapack-forum/viewtopic.php?f=2&t=4425


Handling Complex Types
-------------------------------------------------------------------------------

The interface uses complex types lapack_complex_float/lapack_complex_double.
You have several options to define them:

1) C99 complex types (default):

#define lapack_complex_float float _Complex
#define lapack_complex_double double _Complex

2) C structure option (set by enabling in the configuration file):
-DHAVE_LAPACK_CONFIG_H -DLAPACK_COMPLEX_STRUCTURE

typedef struct { float real, imag; } _lapack_complex_float;
typedef struct { double real, imag; } _lapack_complex_double;
#define lapack_complex_float _lapack_complex_float
#define lapack_complex_double _lapack_complex_double

3) C++ complex types (set by enabling in the configuration file): 
-DHAVE_LAPACK_CONFIG_H -DLAPACK_COMPLEX_CPP

#define lapack_complex_float std::complex<float>
#define lapack_complex_double std::complex<double>

You have to compile the interface with C++ compiler with C++ types.

4) Custom complex types:
-DLAPACK_COMPLEX_CUSTOM

To use custom complex types, you need to:
- Define lapack_complex_float/lapack_complex_double types on your own. 
- Optionally define lapack_make_complex_float/lapack_make_complex_double_real
functions if you want to build the testing suite supplied. Use these 
functions for the testing system. Their purpose is to make a complex value of
a real part re, imaginary part im. The prototypes are as follows:

lapack_complex_float lapack_make_complex_float( float re, float im );
lapack_complex_double lapack_make_complex_double( double re, double im );
