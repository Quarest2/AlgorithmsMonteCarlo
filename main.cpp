#include <iostream>

double Left_bound;
double Top_bound;
double Right_bound;
double Low_bound;

double X1;
double Y1;
double R1;
double X2;
double Y2;
double R2;
double X3;
double Y3;
double R3;

double dist (double x1, double y1, double x2, double y2) {
  return std::sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

bool isInCircle (double x1, double y1, double r, double x2, double y2) {
  return dist(x1, y1, x2, y2) < r;
}

double monteCarlo (int n){
  double M = 0;
  for (int i = 0; i < n; ++i) {
    double xR = (double)std::rand() / (double)RAND_MAX * (Right_bound - Left_bound) + Left_bound;
    double yR = (double)std::rand() / (double)RAND_MAX * (Top_bound - Low_bound) + Low_bound;
    if (isInCircle(X1, Y1, R1, xR, yR) && isInCircle(X2, Y2, R2, xR, yR) && isInCircle(X3, Y3, R3, xR, yR)) {
      M++;
    }
  }

  return M/n;
}

double square () {
  double s = (Right_bound-Left_bound)*(Top_bound-Low_bound);
  return s;
}

int main() {
  std::cin >> X1 >> Y1 >> R1;
  std::cin >> X2 >> Y2 >> R2;
  std::cin >> X3 >> Y3 >> R3;
  Left_bound = std::min(X1-R1, X2-R2);
  Left_bound = std::min(Left_bound, X3-R3);
  Top_bound = std::max(Y1+R1, Y2+R2);
  Top_bound = std::max(Top_bound, Y3+R3);
  Right_bound = std::max(X1+R1, X2+R2);
  Right_bound = std::max(Right_bound, X3+R3);
  Low_bound = std::max(Y1-R1, Y2-R2);
  Low_bound = std::max(Low_bound, Y3-R3);
//  Для вычисления площади, используя уменьшенную область
//  Left_bound = 0.75;
//  Top_bound = 2.25;
//  Right_bound = 2.25;
//  Low_bound = 0.75;

  double s;
  double m;
  for (int i = 100; i <= 100100; i+=500) {
    s = square();
    m = monteCarlo(i);
    std::cout << s*m << std::endl;
  }
  return 0;
}
