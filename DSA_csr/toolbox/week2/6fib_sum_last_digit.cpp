#include <iostream>
#include<vector>
using namespace std;

int fibonacci_sum_naive(long long n) {
    vector<int> a;
   a.push_back(0);
   a.push_back(1);
   a.push_back(1);
   int k=0,key=n+2;
   for(int i=3;i<n+3;i++){
		if(a[i-1]==1 && a[i-2]==0) {  k=i-2;  break;  }
		a.push_back((a[i-1]+a[i-2])%10); 
   }
   if(k!=0)  key=(n+2)%k;
   if(a[key]-1 < 0) return 9;
    return a[key]-1;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_naive(n)<<endl;
}
