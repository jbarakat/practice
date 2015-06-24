/*Primitive code for finding roots of
    4*x = cos(x)
  using the Newton-Raphson method.
  This version of the code uses a subfunction to evaluate f and dfdx, and 
  passes the output to pointers.
*/

#include <iostream>
#include <cmath>
using namespace std;
#define N 100 // maximum number of iterations

/* The definition of the subroutine
 * NOTE: the second and third arguments are intended to be the output values.
 * They are passed as pointers; hence, there is no return statement.
 */
void f_and_df(double x, double *fp, double *dfdxp){
  *fp = 4*x - cos(x); /* the * dereferences the pointer 
                       * (i.e., accesses the value stored at a pointer */
  *dfdxp = 4 + sin(x);
}

int main(){
  double p, pnew;
  double f, dfdx; /* define f and dfdx of type "double" to receive the output 
                   * from the subprogram name and its arguments */
  double tol;
  int i;

  cout << "Enter tolerance: ";
  cin >> tol;
  cout << "Enter the starting value x: ";
  cin >> pnew;

  // Main loop
  for(i = 0; i < N; i++){
    p = pnew;
    
    // get f and dfdx
    f_and_df(p, &f, &dfdx); // arguments 2 and 3 are pointers to doubles

    // the newton-raphson step
    pnew = p - f/dfdx;

    // check for convergence and quit if done
    if(abs(p-pnew) < tol){
      cout << "Root is " << pnew << " to within "
           << tol << "\n";
      return 0;
    }
  }
  // we reach this point only if the iteration failed to converge
  cerr << "Failed to converge after " << N << " iterations.\n";
  return 1;
}
