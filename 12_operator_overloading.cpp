// https://modoocode.com/202
#include <iostream>
#include <string>
class Person {
		std::string name;
		int age;
		
		public:
    Person(std::string name, int age): name(name), age(age) {};
			bool operator==(Person& person);
	};
	bool Person::operator==(Person& person) { 
		return (name == person.name) && (age == person.age); // 각 필드가 모두 같은지 비교
	}

int main() {
  Person p1("David", 10);
  Person p2("David", 10);
  Person p3("David", 20);
  Person p4("John", 10);
  
  if(p1 == p2) {
    std::cout << "p1 and p2 are same" << std::endl;
  } else {
    std::cout << "p1 and p2 are different" << std::endl;
  }
  
  if(p1 == p3) {
    std::cout << "p1 and p3 are same" << std::endl;
  } else {
    std::cout << "p1 and p3 are different" << std::endl;
  }

  if(p1 == p4) {
    std::cout << "p1 and p4 are same" << std::endl;
  } else {
    std::cout << "p1 and p4 are different" << std::endl;
  }
  
  return 0;
}