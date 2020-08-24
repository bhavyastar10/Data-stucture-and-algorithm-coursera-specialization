#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using std::vector;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  /*while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }*/
  int mn[n+1];
  mn[1]=0;
  for(int i=2;i<n+1;i++){
	int num1=1000000,num2=1000000;
		if(i%3==0)
			num1=mn[i/3]+1;
		if(i%2==0)
			num2=mn[i/2]+1;
		int num3=mn[i-1]+1;
		mn[i]=min({num1,num2,num3});
  }
  int k=n;
  while(k!=0){
	sequence.push_back(k);
	if(k==1) break;
	else if(k%3==0 && mn[k]==mn[k/3]+1) k=k/3;
	else if(k%2==0 && mn[k]==mn[k/2]+1) k=k/2;
	else k--;
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
