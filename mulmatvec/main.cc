#include <iostream>
using namespace std;
#define MAX 50

/* Program to perform matrix-vector multiplication:
    A*x = b
*/

void mulmatvec(int m, int n, double a[][MAX], double *x, double *b){
  int i,j;

  for(i = 0; i < m; i++){
    b[i] = 0.;
    for(j = 0; j < n; j++){
      b[i] += a[i][j]*x[j];
    }
  }
  return;
}

/* Alternatively, we could have written
    void mulmatvec(int m, int n, double a[MAX][MAX], double x[MAX], double b[MAX]){
*/

int main(){
  int i,j,m,n;
  double a[MAX][MAX], x[MAX], b[MAX];

  cout << "Enter the number of rows in the matrix \n";
  cin >> m;
  cout << "Enter the number of columns in the matrix \n";
  cin >> n;

  cout << "Enter the matrix by rows \n";
  for(i = 0; i < m; i++)
    for(j = 0; j < n; j++)
      cin >> a[i][j];

  cout << "Enter the vector \n";
  for(j = 0; j < n; j++)
    cin >> x[j];

  mulmatvec(m,n,a,x,b);

  cout << "\nA*x = \n";
  for(i = 0; i < m; i++)
    cout << b[i] << "\n";
}
