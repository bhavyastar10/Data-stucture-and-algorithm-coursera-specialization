#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  vector< vector<int> > v(w.size()+1, vector<int>(W+1));
  for (int i = 0; i <= w.size(); i++) {
  	v[i][0] = 0;
  }
  for (int i = 0; i <= W; i++) {
    v[0][i] = 0;
  }

  for (int i = 1; i <= w.size(); i++) {
  	for (int j = 1; j <= W; j++) {
  	  if (j - w[i - 1] >= 0) 
  	  	v[i][j] = max(v[i - 1][j], v[i - 1][j - w[i - 1]] + w[i - 1]);
  	  else 
  	  	v[i][j] = v[i - 1][j];
  	}
  }
  return v[w.size()][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
