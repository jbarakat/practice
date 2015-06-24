/*Primitive code for finding roots of
    4*x = cos(x)
  using the Newton-Raphson method.
*/

#include <iostream>
#include <cmath>
using namespace std;
#define N 100 // maximum number of iterations

int main(){
  double p, pnew;
  double f, dfdx;
  double tol;
  int i;

  cout << "Enter tolerance: ";
  cin >> tol;
  cout << "Enter the starting value x: ";
  cin >> pnew;

  // Main loop
  for(i = 0; i < N; i++){
    p = pnew;
    
    // evaluate the function and its derivative
    f = 4*p - cos(p);
    dfdx = 4 + sin(p);

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
