#include <iostream>
using namespace std;

long long lcm_naive(int a, int b) {
  long long lcm=1;
  int p=(a>b?b:a);
  int i=2;
  while((a!=1) && (b!=1) && i<=p){
	while((a%i==0) && (b%i==0)) {  lcm*=i;  a=a/i;  b=b/i;   }
	i++;  }

  return lcm*b*a;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_naive(a, b) << std::endl;
  return 0;
}

/*4   -   Least Common Multiple*/
