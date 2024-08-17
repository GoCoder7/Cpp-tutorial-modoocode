#include <iostream>
#include <array>

void naming_convention() {
  int my_int_var = 0; // snake case OK
  int myIntVar = 0; // camel case OK
  int myInt_var = 0; // NG
}

void for_loop() {
  std::cout << std::endl;
  std::array<int, 100> nums;
  for (int i = 1; i<=100; i++) {
    nums[i] = i;
  };
  int sum = 0;
  for (int i: nums) {
    sum += i;
  };
  std::cout << "\nsum: " << sum << std::endl;
}

int main() {
  naming_convention();
  for_loop();

  return 0;
}