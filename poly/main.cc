/* Function for evaluating a polynomial of degree n.
   This program makes use of an array, a, for storing the polynomial 
   coefficients.
 */

#include <iostream>
using namespace std;
#define MAX 50

void poly(int n, double a[], const double x0, double &p){
  int i;
  p = a[n];
  for(i = n - 1; i >= 0; i--){
    p = a[i] + x0*p;
  }
}

int main(){
  int i, n;
  double x0, p;
  double a[MAX+1];

  cout << "Degree of polynomial = ";
  cin >> n;
  if(n > MAX){
    cerr << "Degree must e less than or equal to " << MAX << "\n";
    return 1;
  }
  cout << "Coefficients, a[0], a[1], ..., a[" << n << "]\n";
  for(i = 0; i <= n; i++){
    cin >> a[i];
  }
  cout << "x0 = ";
  cin >> x0;
  poly(n, a, x0, p);
  cout << "P(" << x0 << ") = " << p << "\n";
  return 0;
}
