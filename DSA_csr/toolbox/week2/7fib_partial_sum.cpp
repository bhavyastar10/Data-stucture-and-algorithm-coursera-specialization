#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
     vector<int> a;
   a.push_back(0);
   a.push_back(1);
   a.push_back(1);
   int k=0,key=to+2;
   from++;
   for(int i=3;i<to+3;i++){
		if(a[i-1]==1 && a[i-2]==0) {  k=i-2;  break;  }
		a.push_back((a[i-1]+a[i-2])%10); 
   }
   if(k!=0) { key=(to+2)%k; from=(from)%k;   }
   if(a[key]-a[from] < 0) return 10+a[key]-a[from];
    return a[key]-a[from];
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
}
