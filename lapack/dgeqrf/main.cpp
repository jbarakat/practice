/* Compute the QR factorization of a double precision real rectangular matrix using the LAPACK
 * routine DGEQRF. For input we will use the 5 x 3 matrix,
 *          ( 1  1  1 )
 *          ( 2  3  4 )
 *      A = ( 3  5  2 )
 *          ( 4  2  5 )
 *          ( 5  4  3 )
 */

#include <stdio.h>
#include <stdlib.h>
#include <lapacke.h>
#include <cblas.h>

int main(){
	const int m = 5;
	const int n = 3;
	int lda = 3;
	int info;
	
	double a[m][n] = {1,1,1,
                          2,3,4,
                          3,5,2,
                          4,2,5,
                          5,4,3};
	double tau[1][n];
	
	info = LAPACKE_dgeqrf(LAPACK_ROW_MAJOR, m, n, *a, lda, *tau);
	
	printf("A = \n");
	for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                        printf("%lf ",a[i][j]);
                }   
                printf("\n");
        }
	return(info);
}
