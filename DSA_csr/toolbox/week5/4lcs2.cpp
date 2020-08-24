#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using std::vector;

int lcs2(vector<int> &a, vector<int> &b) {
  //write your code here
  //return std::min(std::min(a.size(), b.size()), c.size());
  int n=a.size()+1,m=b.size()+1;
  int d[n][m];
  for(int k=0;k<n;k++)  d[k][0]=0;
  for(int k=0;k<m;k++)  d[0][k]=0;
  for(int j=1;j<m;j++){
	for(int i=1;i<n;i++){
		int in=d[i][j-1];
		int de=d[i-1][j];
		int ma=d[i-1][j-1]+1;
		int mi=d[i-1][j-1];
		if(a[i-1]==b[j-1])  d[i][j]=max({in,de,ma});
		else d[i][j]=max({in,de,mi}); 
		
	}
  }
  return d[n-1][m-1];
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
