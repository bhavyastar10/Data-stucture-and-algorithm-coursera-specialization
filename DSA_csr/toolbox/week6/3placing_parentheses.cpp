#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
using std::vector;
using std::string;
using std::max;
using std::min;
using namespace std;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

long long get_maximum_value(const string &exp) {
  int k=(exp.size()/2)+1;

  long long m[k][k],M[k][k];
  for(int i=0;i<k;i++){
	m[i][i]=(long long)exp[2*i]-48;
	M[i][i]=(long long)exp[2*i]-48;    }

  for(int s=0;s<k-1;s++){
	for(int i=0;i<k-s-1;i++){
		int j=i+s+1;
		
		long long mn=100000,mx=-100000;
		for(int x=i;x<j;x++){
		int p=2*x+1;
		long long a=eval(M[i][x],M[x+1][j],exp[p]);
		long long b=eval(M[i][x],m[x+1][j],exp[p]);
		long long c=eval(m[i][x],M[x+1][j],exp[p]);
		long long d=eval(m[i][x],m[x+1][j],exp[p]);

		mn=min({mn,min(a,b),min(c,d)});
		mx=max({mx,max(a,b),max(c,d)});
		}
	m[i][j]=mn;
	M[i][j]=mx; 
	}
  }
  return M[0][k-1];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
