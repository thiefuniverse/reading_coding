#include <iostream>

class A {

 private:
  int value;
 public:
  A();
  A(int n) { value = n;}
  // compilation error below
  A(A other) { value = other.value;}
};


int main() {
  A a;
  return 0;
}
