#ifndef VECTOR_H
#define VECTOR_H

/* Could improve this class by including operators for -, *, /, -=, *=, /=.
   Currently only have functionality for + and +=.
 */

#include <iostream>

class vector {
private:
  int size;
  double *vec; // note that only a pointer is kept here

  // auxiliary function for internal range checking
  int range(int i);

public:
  // constructors
  vector(int n);
  vector(const double*, int);
  vector(const vector&);

  // desctructor is required because the constructor above uses ``new"
  ~vector();

  // accessors ([])
  double & operator[](int i);

  // assignment operator (=)
  vector & operator=(const vector &v);

  // binary addition (+)
  friend vector operator+(const vector &v1, const vector &v2);
    // NOTE: friends can access private class members

  // add and assign (overload the += operator)
  vector operator+=(const vector &v);
};

// binary addition (not a member function)
inline vector operator+(const vector &v1, const vector &v2){
  if(v1.size != v2.size){
    std::cerr << "FATAL vector::operator+(const vector &, const vector &) size mismatch: "
              << v1.size << " " << " != " << v2. size << "\n";
    exit(1);
  }

  vector v(v1.size); // construct a temporary vector to hold the sum
  for(int i = 0; i < v1.size; i++)
    v.vec[i] = v1.vec[i] + v2.vec[i];
  return v;
}

#endif
