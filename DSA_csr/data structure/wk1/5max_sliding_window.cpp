#include <iostream>
#include <vector>
#include <deque>
using namespace std;
using std::cin;
using std::cout;
using std::vector;
using std::max;

void max_sliding_window_naive(vector<int> const & A, int w) {
    deque<int> a(A.size());
    for (int i = 0; i < w ; ++i) {
        while((!a.empty()) && A[a.back()]<=A[i] ) a.pop_back();
	a.push_back(i);
    }
    for(int i=w;i<A.size();++i){
	cout<<A[a.front()]<<" ";
	while(!(a.empty()) && (a.front()<=i-w))  
		a.pop_front();
	while((!a.empty()) && A[a.back()]<=A[i] ) 
		a.pop_back();
	a.push_back(i);
    }
    cout<<A[a.front()]<<endl;	

    return;
}


int main() {
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;

    max_sliding_window_naive(A, w);

    return 0;
}
