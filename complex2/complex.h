#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

template<class T> // < > could contain "double," "float," etc.
class complex {
public:
  T re; // T specifies datatype
  T im;
  
  // constructors
  complex<T>(){
    re = 0;
    im = 0;
  }
  complex<T>(T r, T i = 0){
    re = r;
    im = i;
  }
};

template<class FLT>
complex<FLT> cadd(complex<FLT> &z1, complex<FLT> &z2){
  return complex<FLT>(z1.re + z2.re, z1.im + z2.im);
}

#endif
