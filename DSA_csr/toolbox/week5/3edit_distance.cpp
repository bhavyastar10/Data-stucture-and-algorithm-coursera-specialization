#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
using std::string;

int edit_distance(const string &str1, const string &str2) {
  int n=str1.size()+1,m=str2.size()+1;
  int d[n][m];
  for(int k=0;k<n;k++)  d[k][0]=k;
  for(int k=0;k<m;k++)  d[0][k]=k;
  for(int j=1;j<m;j++){
	for(int i=1;i<n;i++){
		int in=d[i][j-1]+1;
		int de=d[i-1][j]+1;
		int ma=d[i-1][j-1];
		int mi=d[i-1][j-1]+1;
		if(str1[i-1]==str2[j-1]) d[i][j]=min({in,de,ma});
		else d[i][j]=min({in,de,mi}); 
		
	}
  }
  return d[n-1][m-1];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
