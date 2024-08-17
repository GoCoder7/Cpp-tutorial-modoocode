// https://modoocode.com/172

#include <iostream>
class Date {
  int year_;
  int month_; // 1 to 12
  int day_; // 1 to 31

  public:
    void SetDate(unsigned int year, unsigned int month, unsigned int day);
    void AddDay(int inc);
    void AddMonth(int inc);
    void AddYear(int inc);

    void ShowDate();
};
void Date::SetDate(unsigned int year, unsigned int month, unsigned int day) {
  year_ = year;
  month_ = month;
  day_ = day;
}
void Date::AddDay(int inc) {
  
  day_ += inc;
  switch (month_) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
      if (day_ > 31) {
        AddMonth(day_ / 31);
        day_ %= 31;
      }
    break;
    case 4: case 6: case 9: case 11:
      if (day_ > 30) {
        AddMonth(day_ / 30);
        day_ %= 30;
      }
    break;
    case 2:
      // 더해진 날짜의 년도를 기준으로 해야하는데, 현재 년도를 기준으로 하고 있으므로 수정이 필요
      if (year_ % 4 == 0 && year_ % 100 != 0 || year_ % 400 == 0) {
        if (day_ > 29) {
          AddMonth(day_ / 29);
          day_ %= 29;
        }
      } else {
        if (day_ > 28) {
          AddMonth(day_ / 28);
          day_ %= 28;
        }
      }
  }
  if (month_ > 12) {
    AddYear(month_ / 12);
    month_ %= 12;
  }
}
void Date::AddMonth(int inc) {
  month_ += inc;
  if (month_ > 12) {
    AddYear(month_ / 12);
    month_ %= 12;
  }
}
void Date::AddYear(int inc) {
  year_ += inc;
}
void Date::ShowDate() {
  std::cout << year_ << "년 " << month_ << "월 " << day_ << "일" << std::endl;
}

void task() {
  Date date;
  date.SetDate(2021, 1, 1);
  date.AddDay(50);
  date.ShowDate();
}

int main() {
  task();
  return 0;
}