#include <iostream>
#include <cmath>
using namespace std;

// Compute roots of quadratic equation

int main()
{
  double a, b, c, x1, x2;
  double s, d, signb;

  // Get a, b, and c
  cout << "Enter a, b, and c: ";
  cin >> a >> b >> c;

  d = b*b - 4*a*c;
  signb = 1;
  if(b < 0) signb  = -1;
  s = -(b + sqrt(d)*signb)/2;
  x1 = s/a;
  x2 = c/s;

  cout << "Roots are \n" << x1 << " " << x2 << "\n";
}
