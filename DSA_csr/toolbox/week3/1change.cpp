#include <iostream>

int get_change(int m) {
  int res=0;
  res+=m/10;
  m=m%10;
  res+=m/5;
  m=m%5;
  res+=m;
  return res;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
