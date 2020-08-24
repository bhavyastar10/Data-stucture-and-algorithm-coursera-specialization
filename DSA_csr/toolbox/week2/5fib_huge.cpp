#include <iostream>
#include <vector>
#include<list>
using namespace std;

long long get_fibonacci_huge_naive(long long n, long long m) {
   vector<int> a;
   a.push_back(0);
   a.push_back(1);
   a.push_back(1);
   int k=0;
   for(int i=3;;i++){
		if(a[i-1]==1 && a[i-2]==0) {  k=i-2;  break;  }
		a.push_back((a[i-1]+a[i-2])%m); 
   }
   int key=n%k; 
   return a[key];	
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout <<get_fibonacci_huge_naive(n, m) << '\n';
}
