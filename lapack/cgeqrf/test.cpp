#include <stdio.h>
#include <stdlib.h>
#include <lapacke.h>
#include <cblas.h>

int main(){
	lapack_complex_float one;
	one = lapack_make_complex_float(1.0,0.0);
	return(0);
}
