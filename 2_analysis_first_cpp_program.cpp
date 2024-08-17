// https://modoocode.com/136

#include <iostream>

namespace header1 {
  void foo(){};
  void bar(){};
}
namespace header2 {
  void foo(){};
  void bar(){};
}

int func() {
  using namespace header1; // header1의 모든것을 현재스콥에 추가
  // 현재 스콥에 foo()는 header1에만 있으므로 header1::foo()를 호출
  // 하지만 어느 namespace에 속한 함수인지 확인할 수 없으므로 권장하지 않음.
  foo();
  header2::foo(); // 명시적으로 headr2의 foo()를 호출. 권장
}


int main() {
  std::cout << "hi" << std::endl
            << "my name is "
            << "Psi" << std::endl;
  return 0;
}