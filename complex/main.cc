#include <iostream>
using namespace std;

class complex {
public:
  double re;
  double im;
};

int main(){
  complex a;

  cout << "Enter Re and Im\n";
  cin >> a.re >> a.im;
  cout << "Your number is " << a.re << " + I * " << a.im << "\n";
}
