#include "vector.h"

// constructors
vector::vector(int n){
  size = n;
  vec = new double[size];
}

vector::vector(const double *a, int n){
  size = n;
  vec = new double[size];

  // if the allocation failed, vec is returned NULL
  if(vec == NULL){
    std::cerr << "FATAL: vector::vector(const double *, int) cannot allocate vector("
         << n << ")\n";
    exit(1);
  }

  for(int i = 0; i < size; i++){
    vec[i] = a[i];
  }
}

vector::vector(const vector &v){
  size = v.size;
  vec = new double[size];

  // if the allocation failed, vec is returned NULL
  if(vec == NULL){
    std::cerr << "FATAL: vector::vector(const double *, int) cannot allocate vector("
         << v.size << ")\n";
    exit(1);
  }
  
  for(int i = 0; i < size; i++)
    vec[i] = v.vec[i];
}

// destructor
vector::~vector(){
  delete [] vec;
}

// accessor
double &vector::operator[](int i){
  return vec[i];
}

// assignment
vector &vector::operator=(const vector &v){
  if(size != v.size){
    std::cerr << "FATAL vector::operator(const vector &) size mismatch: " <<
      size << " " << v.size << "\n";
    exit(1);
  }

  for(int i = 0; i < size; i++)
    vec[i] = v.vec[i];

  return *this;
}

// auxiliary function for internal range checking
int vector::range(int i){
  if (i < 0 || i >= size){
    std::cerr << "FATAL vector::range(" << i << ") out of bounds [0,"
              << size - 1 << "]\n";
    exit(1);
  }
  return i;
}

// add and assign (overload the += operator)
vector vector::operator+=(const vector &v){
  if(size != v.size){
    std::cerr << "FATAL vector::operator+=(const vector &) size mismatch: "
              << size << " " << " != " << v.size << "\n";
    exit(1);
  }
  
  for(int i = 0; i < size; i++)
    vec[i] += v.vec[i];

  return *this;
}
