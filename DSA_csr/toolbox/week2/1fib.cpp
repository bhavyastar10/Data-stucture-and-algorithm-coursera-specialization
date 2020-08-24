#include <iostream>
#include <cassert>
using namespace std;

long fibonacci_fast(int n) {
    long a[n];
    a[-1]=0;
    a[0]=1;
    a[1]=1;
    for(int i=2;i<n;i++)
	a[i]=a[i-1]+a[i-2];
	
    return (long)a[n-1];
}

int main() {
    int n = 0;
    std::cin >> n;

    std::cout << fibonacci_fast(n) << '\n';
    return 0;
}

/* 1  -  Fibonacci Number*/

