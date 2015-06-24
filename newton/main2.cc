/*Primitive code for finding roots of
    4*x = cos(x)
  using the Newton-Raphson method.
  This version of the code uses separate functions "f" and "dfdx" to evaluate 
  the function and its derivative.
*/

#include <iostream>
#include <cmath>
using namespace std;
#define N 100 // maximum number of iterations

double f(double x){
  return 4*x - cos(x);
}

double dfdx(double x){
  return 4 + sin(x);
}

int main(){
  double p, pnew;
  double tol;
  int i;

  cout << "Enter tolerance: ";
  cin >> tol;
  cout << "Enter the starting value x: ";
  cin >> pnew;

  // Main loop
  for(i = 0; i < N; i++){
    p = pnew;
    
    // the newton-raphson step
    pnew = p - f(p)/dfdx(p);

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
