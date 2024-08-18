#include <iostream>
#include <string>
using std::string;

class MyString {
  char* string_content;  // 문자열 데이터를 가리키는 포인터
  int string_length;     // 문자열 길이

  int memory_capacity;

 public:
  // capacity 만큼 미리 할당함.
  explicit MyString(int capacity); // explicit 키워드로 암시적 생성자 호출 불가

  // 문자열로 부터 생성
  MyString(const char* str);

  // 복사 생성자
  MyString(const MyString& str);

  ~MyString();

  int length() const;
};

MyString::MyString(int capacity) {
  string_content = new char[capacity];
  string_length = 0;
  memory_capacity = capacity;
  std::cout << "Capacity : " << capacity << std::endl;
}

MyString::MyString(const char* str) {
  string_length = 0;
  while (str[string_length++]) {
  }

  string_content = new char[string_length];
  memory_capacity = string_length;

  for (int i = 0; i != string_length; i++) string_content[i] = str[i];
}
MyString::MyString(const MyString& str) {
  string_length = str.string_length;
  string_content = new char[string_length];

  for (int i = 0; i != string_length; i++)
    string_content[i] = str.string_content[i];
}
MyString::~MyString() { delete[] string_content; }
int MyString::length() const { return string_length; }

void do_something_with_my_string(MyString str) {
  //
}

void explicit_example() {
  do_something_with_my_string("Hello World"); // do_something_with_my_string(MyString("Hello World"));
  do_something_with_my_string(MyString(3)); // 명시적으로 생성자 호출
 // do_something_with_my_string(3); // explicit 키워드로 인해, 암시적 생성자 호출 불가
}
//=================================================================================================
class Person {
  mutable string name;
  int age;
  public:
    Person(string name, int age): name(name), age(age) {};
    void print() const;
    void change_name(string name) const;
};
void Person::print() const {
  std::cout << "name: " << name << ", age: " << age << std::endl;
}
void Person::change_name(string name) const {
  this->name = name;
}

void mutable_example() {
  Person p("JohnDoe", 30);
  p.print();
  p.change_name("JaneDoe");
  p.print();
}

//=================================================================================================
int main() {
  explicit_example();
  mutable_example();

  return 0;  
}