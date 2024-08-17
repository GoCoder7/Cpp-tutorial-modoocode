// https://modoocode.com/169
#include <iostream>
#include <format>
using std::string;

void new_array() {
  int ARRAY_SIZE = 3;
  int* arr = new int[ARRAY_SIZE];
  for (int i = 1; i <= ARRAY_SIZE; i++) {
    arr[i] = i;
  }
  string msg = "";
  for (int i = 0; i < ARRAY_SIZE; i++) {
    msg = std::format("{}arr[{}]: {}, ", msg, i, arr[i]);
  }
  msg = msg.substr(0, msg.length() - 2);
  std::cout << msg << std::endl;
  delete[] arr;
}

struct Animal{
  string name;
  int age;
  int health;
  int food;
  int clean;
};
void create_animal(Animal& animal) {
  std::cout << "동물의 이름? ";
  std::cin >> animal.name;

  std::cout << "동물의 나이? ";
  std::cin >> animal.age;

  animal.health = 100;
  animal.food = 100;
  animal.clean = 100;
}
void play(Animal* animal) {
  animal->health += 10;
  animal->food -= 20;
  animal->clean -= 30;
}
void one_day_pass(Animal* animal) {
  animal->health -= 10;
  animal->food -= 30;
  animal->clean -= 20;
}
void show_stat(Animal* animal) {
  std::cout << animal->name << "의 상태" << std::endl;
  std::cout << std::format("체력: {}\n", animal->health) << std::endl;
  std::cout << std::format("배부름: {}\n", animal->food) << std::endl;
  std::cout << std::format("청결: {}\n", animal->clean) << std::endl;
}
void limitation_of_struct() {
  Animal* list[10];
  int animal_count = 0;

  while (true) {
    std::cout << "1. 동물 추가하기" << std::endl;
    std::cout << "2. 놀기" << std::endl;
    std::cout << "3. 상태 보기" << std::endl;
    std::cout << "0. 종료하기" << std::endl;

    std::cout << "선택(번호만 입력): ";
    int input;
    std::cin >> input;

    switch (input) {
      case 1: {
        if (animal_count < 10) {
          Animal* animal = new Animal;
          create_animal(*animal);
          list[animal_count] = animal;
          animal_count++;
        }
        break;
      }
      case 2: {
        std::cout << "누구랑 놀게?" << std::endl;
        for (int i = 0; i < animal_count; i++) {
          std::cout << i << ". " << list[i]->name << std::endl;
        }
        int input;
        std::cin >> input;
        play(list[input]);
        std::cout << list[input]->name << "과 놀았습니다" << std::endl;
        break;
      }
      case 3: {
        std::cout << "누구껄 보게?" << std::endl;
        for (int i = 0; i < animal_count; i++) {
          std::cout << i << ". " << list[i]->name << std::endl;
        }
        for (int i = 0; i < animal_count; i++) {
          show_stat(list[i]);
        }
        break;
      }
      case 0: {
        for (int i = 0; i < animal_count; i++) {
          delete list[i];
        }
        std::cout << "종료합니다" << std::endl;
        return;
      }
    }
    for (int i = 0; i < animal_count; i++) {
      one_day_pass(list[i]);
    }
    std::cout << "========== 하루가 지났음 ==========" << std::endl;
  }
  for (int i = 0; i < animal_count; i++) {
    delete list[i];
  }
}


int main() {
  new_array();
  limitation_of_struct();
  return 0;
}