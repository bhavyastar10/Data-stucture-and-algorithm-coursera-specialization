#include <iostream>
#include <vector>
using namespace std;
using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  int sum=0,i=1;
  while(sum!=n){
	if(n-(sum+i)==0 || n-(sum+i) > i)  {   summands.push_back(i);   sum+=i;   }
	i++;
	}
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
  printf("\n");
}
