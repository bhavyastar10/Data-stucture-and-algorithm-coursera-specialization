#include <iostream>

int gcd_naive(int a, int b) {
  if(b==0) return a;

  else{
	int x=a%b;
	return gcd_naive(b,x); 	}
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_naive(a, b) << std::endl;
  return 0;
}

/*3   -   Greatest Common Divisor*/
