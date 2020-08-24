#include <iostream>
using namespace std;

int get_change(int m) {
  int a[3]={1,3,4};
  int min[m+1];
  min[0]=0;
  for(int i=1;i<m+1;i++){
	min[i]=1000000;
	for(int j=0;j<3;j++){
		if(i>=a[j]){
			int num=min[i-a[j]]+1;
			if(min[i]>num)  min[i]=num;  }
	}
  }
  return min[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
