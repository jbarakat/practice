/* Now we improve on the complex class by including constructors and by 
 * defining an object "cadd" which returns the sum of two complex numbers.
 */

#include <iostream>
using namespace std;

class complex {
public:
  double re;
  double im;

  // constructor #1 (no arguments given)
  complex(){
    re = 0;
    im = 0;
  }

  // constructor #2
  complex(double r, double i = 0){
    re = r;
    im = i;
  }
};

// function for complex number addition
complex cadd(complex &z1, complex &z2)
{
  return complex(z1.re + z2.re, z1.im + z2.im);
}

int main(){
  // instantiate objects of the class "complex"
  complex a, b, sum;
  //complex z1(-1), z2(3.4,-2.);
  //cout << "z1 is " <<  z1.re << " + I * " << z1.im << "\n";
  //cout << "z2 is " << z2.re << " + I * " << z2.im << "\n";

  cout << "Enter Re(a) and Im(a)\n";
  cin >> a.re >> a.im;
  cout << "Enter Re(b) and Im(b)\n";
  cin >> b.re >> b.im;
  sum = cadd(a, b);
  cout << "Your number is " << sum.re << " + I * " << sum.im << "\n";
}
