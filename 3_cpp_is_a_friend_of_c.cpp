// https://modoocode.com/138

#include <iostream>
#include <array>

void naming_convention() {
  int my_int_var = 0; // snake case OK
  int myIntVar = 0; // camel case OK
  int myInt_var = 0; // NG
}

void for_loop() {
  std::cout << std::endl;
  int sum = 0;
  for (int i=1; i<=100; i++) {
    sum += i;
  };
  std::cout << "\nsum: " << sum << std::endl;
}

void while_loop() {
  std::cout << std::endl;
  int i = 0;
  int sum = 0;
  while (++i <= 100) {
    sum += i;
  };
  std::cout << "\nsum: " << sum << std::endl;
}

void if_else() {
  std::cout << std::endl;
  int i = 57;
  if (i < 50) {
    std::cout << "i < 50" << std::endl;
  } else if (i < 100) {
    std::cout << "50 <= i < 100" << std::endl;
  } else {
    std::cout << "i >= 100" << std::endl;
  }
}

void switch_case() {
  std::cout << std::endl;
  int i = 57;
  switch (i) {
    case 50:
      std::cout << "i == 50" << std::endl;
      break;
    case 57:
      std::cout << "i == 57" << std::endl;
      break;
    default:
      std::cout << "i != 50 && i != 57" << std::endl;
  }
}

int main() {
  naming_convention();
  for_loop();
  while_loop();
  if_else();

  return 0;
}