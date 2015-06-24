#include  <iostream> 
#include <lapacke.h>

using namespace std;

int main()
{
   complex<double> Matrix[1]={1};
   complex<double> Vector[1]={.5};
   int Nmatrix=1;
   int nrhs = 1;
   int lda = Nmatrix;
   int ldb = Nmatrix;
   int ipvt[Nmatrix];
   int info;


//CALL ZGESV( N, NRHS, A, LDA, IPIV, B, LDB, INFO )
   info = LAPACKE_zgesv(LAPACK_ROW_MAJOR, Nmatrix, nrhs, Matrix, lda, ipvt, Vector, ldb);

   cout << "Info = "<< info << "\n";

if (info ==0)
{
   cout << "Solution: \n";
   for (int i=0; i<Nmatrix; i++) cout << "X["<< i <<"] = " << Vector[i];
   cout << std::endl;
}

return(info);
}
