#include <stdlib.h>
#include <stdio.h>
//#include <iostream> // stdio.h is C's version of C++'s iostream
#include <string.h>
#include <math.h>
//#include <complex>
//#include <vector>
#include "lapacke.h"
//#include <clbas.h> // why would I include cblas?
using namespace std;

//typedef complex<double> dcomplex;
//complex<double> a;
lapack_complex_double a;
lapack_int b;

//extern void zheev_( char* jobz, char* uplo, int* n, dcomplex* a, int *lda, double* w, dcomplex* work, int* lwork, double* rwork, int* info);

int main(){
	int f;
	lapack_int a;
	lapack_int c;
	a = 5;
	b = 2;
	c = a + b;
	printf("a is %.i\n",c);
	printf("Test complete... file compiled.\n");
//	int i, j, n, one;
//	double coefficient;
//	cout << "Does this work?" << endl;
//	double x[] = { 1, 1, 1 };
//
//	coefficient = 4.323;
//	one = 1;
//	n = 3;
//
////	dscal_(&n, &coefficient, &x[0], &one);
//	lapack_int m, n, lda, info;
//	double *a, *tau;
//
	return 0;
}
