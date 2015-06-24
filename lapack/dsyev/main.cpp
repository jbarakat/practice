/* This file uses the DSYEV subroutine in LAPACK to compute all eigenvalues and, optionally,
 * eigenvectors of a real symmetric matrix A.
 */

#include <stdio.h>
#include <stdlib.h>
#include <lapacke.h>
#include <cblas.h>

int main(){
	char jobz, uplo;
	int n, lda, info;
	double *a, *w;

	n = 2;
	lda = 2;
	jobz = 'V'; // compute eigenvalues and eigenvectors
	uplo = 'U'; // upper triangular matrix is stored
	a = (double*) malloc(sizeof(double)*n*lda);
	w = (double*) malloc(sizeof(double)*n);
	
	// initialize a
	for (int i = 0; i < n*n; i++){
		a[i] = (double) random()/RAND_MAX;
	//	printf("A[%i] = %1.6f\n", i, a[i]);
	}
	printf("A = %1.6f, %1.6f, %1.6f, %1.6f\n",a[0],a[1],a[2],a[3]);

	// get worktime information
	info = LAPACKE_dsyev(LAPACK_ROW_MAJOR, jobz, uplo, n, a, lda, w);
	// NOTE: the handling of work arrays is done inside LAPACK

	// get time
	printf("LAPACKE, n=%d: info=%d time=%lf\n", n, info, 0.0);
	printf("A = %1.6f, %1.6f, %1.6f, %1.6f\n",a[0],a[1],a[2],a[3]);
	printf("W = %1.6f, %1.6f, %1.6f, %1.6f\n",w[0],w[1],w[2],w[3]);
}
