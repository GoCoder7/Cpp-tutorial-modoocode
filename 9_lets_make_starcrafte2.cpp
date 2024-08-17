// https://modoocode.com/188
#include <iostream>
using std::string;

class Marine {
  static int total_marine_num;
  int hp;                // 마린 체력
  int coord_x, coord_y;  // 마린 위치
  int damage;            // 공격력
  bool is_dead;
  string name;

 public:
  Marine();              // 기본 생성자
  Marine(int x, int y, string name); 
  ~Marine() {
    std::cout << name << " 의 소멸자 호출 !" << std::endl;
    total_marine_num--;
  }

  int attack();                       // 데미지를 리턴한다.
  void be_attacked(int damage_earn);  // 입는 데미지
  void move(int x, int y);            // 새로운 위치

  void show_status();  // 상태를 보여준다.
};
int Marine::total_marine_num = 0;
Marine::Marine(): hp(50), coord_x(0), coord_y(0), damage(5), is_dead(false), name("") {total_marine_num++;}
  
Marine::Marine(int x, int y, string name=""): coord_x(x), coord_y(y), hp(50), damage(5), is_dead(false), name(name) {total_marine_num++;}
void Marine::move(int x, int y) {
  coord_x = x;
  coord_y = y;
}
int Marine::attack() { return damage; }
void Marine::be_attacked(int damage_earn) {
  hp -= damage_earn;
  if (hp <= 0) is_dead = true;
}
void Marine::show_status() {
  std::cout << " *** Marine : " << name << " ***" << std::endl;
  std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
            << std::endl;
  std::cout << " HP : " << hp << std::endl;
  std::cout << "현재 총 마린 수: " << total_marine_num << std::endl;
}
void each_marine(){
  Marine marine0(2, 3, "Marine 0");
  Marine marine1(3, 5);

  marine0.show_status();
  marine1.show_status();

  std::cout << std::endl << "마린 0 이 마린 1 를 공격! " << std::endl;
  marine1.be_attacked(marine0.attack());

  marine0.show_status();
  marine1.show_status();
}

void marin_array() {
  Marine* marines[100];

  marines[0] = new Marine(2, 3, "Marine 0");
  marines[1] = new Marine(3, 5, "Marine 1");

  marines[0]->show_status();
  marines[1]->show_status();

  std::cout << std::endl << "마린 0 이 마린 1 를 공격! " << std::endl;
  marines[1]->be_attacked(marines[0]->attack());

  marines[0]->show_status();
  marines[1]->show_status();

  delete marines[0];
  delete marines[1];
}

int main() {
  each_marine();
  marin_array();
  return 0;
}