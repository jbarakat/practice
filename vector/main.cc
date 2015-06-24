#include <iostream>
#include "vector.h"
using namespace std;

int main(){
  int i, n;

  cout << "Enter size of vector: \n";
  cin >> n;
  vector a(n);
  cout << "Enter the components: \n";
  for(i = 0; i < n; i++)
    cin >> a[i];
  cout << "Your vector is \n";
  for (i = 0; i < n; i++)
    cout << a[i] << "\n";

  return 0;
}
