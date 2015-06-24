#include <iostream>
#include "complex.h"
using namespace std;

int main(){
  complex<double> a;

  cout << "Enter Re and Im\n";
  cin >> a.re >> a.im;
  cout << "Your number is " << a.re << " + I * " << a.im << "\n";
}
