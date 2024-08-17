// https://modoocode.com/173

#include <iostream>
using std::string;

void print(int integer) {
  std::cout << integer << std::endl;
}
void print(double real) {
  std::cout << real << std::endl;
}
void print(string str) {
  std::cout << str << std::endl;
}
void overload() {
  print(10);
  print(0.123);
  print("Hello, world!");
}

class Point {
  public:
    int x, y;
    Point(int pos_x, int pos_y);
};
Point::Point(int pos_x, int pos_y): x(pos_x), y(pos_y) {}

class Geometry {
  // 점 100 개를 보관하는 배열.
  Point* point_array[100];
  int num_points;

  public:
    Geometry() {
      num_points = 0;
    }
    void AddPoint(const Point &point) {
      point_array[num_points ++] = new Point(point.x, point.y);
    }

    // 두 점 사이의 거리를 계산하는 함수
    double GetDistance(const Point& p1, const Point& p2) {
      int x_diff = abs(p1.x - p2.x);
      int y_diff = abs(p1.y - p2.y);
      return sqrt(x_diff * x_diff + y_diff * y_diff);
    }
    // 모든 점들 간의 거리를 출력하는 함수 입니다.
    void PrintDistances();

    // 모든 점들을 잇는 직선들 간의 교점의 수를 출력해주는 함수 입니다.
    // 참고적으로 임의의 두 점을 잇는 직선의 방정식을 f(x,y) = ax+by+c = 0
    // 이라고 할 때 임의의 다른 두 점 (x1, y1) 과 (x2, y2) 가 f(x,y)=0 을 기준으로
    // 서로 다른 부분에 있을 조건은 f(x1, y1) * f(x2, y2) <= 0 이면 됩니다.
    void PrintNumMeets();
};
void Geometry::PrintDistances() {
  for (int i = 0; i < num_points; i++) {
    for (int j = i + 1; j < num_points; j++) {
      std::cout << "Distance between point " << i << " and point " << j << ": " << GetDistance(*point_array[i], *point_array[j]) << std::endl;
    }
  }
}
void Geometry::PrintNumMeets() {
  std::cout << "중요한 내용이 아니라서 거름" << std::endl;
}
void geometry() {
  Geometry geometry;
  geometry.AddPoint(Point(1, 1));
  geometry.AddPoint(Point(2, 2));
  geometry.AddPoint(Point(3, 3));
  geometry.PrintDistances();
  geometry.PrintNumMeets();
}


int main() {
  overload();
  geometry();

  return 0;
}