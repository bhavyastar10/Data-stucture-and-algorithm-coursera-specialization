#include <iostream>
#include<vector>
using namespace std;

int fibonacci_sum_squares_naive(long long n) {
   vector<int> a;
   a.push_back(0);
   a.push_back(1);
   a.push_back(1);
   int k=0,key2=n+1,key1=n;
   for(int i=3;i<n+2;i++){
		if(a[i-1]==1 && a[i-2]==0) {  k=i-2;  break;  }
		a.push_back((a[i-1]+a[i-2])%10); 
   }
   if(k!=0) { key2=(n+1)%k; key1=n%k;  }
 
   return (a[key1]*a[key2])%10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_naive(n)<<endl;
}

/*8   -   Last Digit of the Sum of Squares of Fibonacci Numbers*/
