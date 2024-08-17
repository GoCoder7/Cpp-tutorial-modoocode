// https://modoocode.com/141

#include <iostream>

int change_val(int* p, int val) {
  *p = val;
  return 0;
}
void pointer_example(){
  std::cout << std::endl;
  int num = 10;
  change_val(&num, 20);
  std::cout << "pointer num: " << num << std::endl;
}

int change_val(int& r, int val) {
  r = val;
  return 0;
}
void reference_example(){
  std::cout << std::endl;
  int num = 10;
  change_val(num, 20);
  std::cout << "reference num: " << num << std::endl;
}

void reference_array() {
  std::cout << std::endl;
  int arr[] = {1, 2, 3};
  int (&ref)[3] = arr;
  std::cout << "reference array: " << ref[0] << ref[1] << ref[2] << ref[3] << std::endl;
}

int add_one(const int& num) {
  return num + 1;
}
void const_reference() {
  const int& six = add_one(5);
  std::cout << "const reference six: " << six << std::endl;
}

int main() {
  pointer_example();
  reference_example();
  reference_array();
  const_reference();

  return 0;
}