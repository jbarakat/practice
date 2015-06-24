/* Solve the least squares problem min_x || B - Ax || for two right-hand sides using the LAPACK
 * routine DGELS. For input we will use the 5 x 3 matrix,
 *	    ( 1  1  1 )
 *	    ( 2  3  4 )
 *	A = ( 3  5  2 )
 *	    ( 4  2  5 )
 *	    ( 5  4  3 )
 * and the 5 x 2 matrix,
 *	    ( -10 -3 )
 *	    (  12 14 )
 *	B = (  14 12 )
 *	    (  16 16 )
 *	    (  18 16 )
 * The arrays are represented using row-major order. Thus, lda = 3 and ldb = 2. The output for
 * each right hand side is stored in b as consecutive vectors of length 3. The correct answer for
 * this problem is the 3 x 2 matrix,
 *	    ( 2 1 )
 *	    ( 1 1 )
 *	    ( 1 2 )
 */

#include <stdio.h>
#include <stdlib.h>
#include <lapacke.h>
#include <cblas.h>

//int main(int argc, const char * argv[]){
int main(){
	double a[5][3] = {1,1,1,
			  2,3,4,
			  3,5,2,
			  4,2,5,
			  5,4,3};
	double b[5][2] = {-10,-3,
			  12,14,
			  14,12,
			  16,16,
			  18,16};
	int info, m, n, lda, ldb, nrhs;

	m = 5;
	n = 3;
	nrhs = 2;
	lda = 3;
	ldb = 2;

	info = LAPACKE_dgels(LAPACK_ROW_MAJOR, 'N', m, n, nrhs, *a, lda, *b, ldb);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < nrhs; j++){
			printf("%lf ",b[i][j]);
		}
		printf("\n");
	}
	return(info);
}
