#include <iostream>
#include <vector>
using namespace std;
using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    int disp=0,i=0,count=0;
    while(disp+tank<dist && i<stops.size()){
	if(disp+tank<stops[i]) return -1;
	else {
		while(stops[i]-disp<=tank && i<stops.size()) i++;
		count++;
		disp=stops[i-1];
	}
     }
     if(disp+tank<dist)  return -1;
     return count;		
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
