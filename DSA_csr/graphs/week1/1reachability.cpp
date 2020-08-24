#include <iostream>
#include <vector>
using namespace std;
using std::vector;
using std::pair;


int reach(vector<bool> &visit,vector<vector<int> > &adj, int x, int y) {
  visit[x]=1;
  for(size_t i=0;i<adj[x].size();i++){
	if(adj[x][i]==y) return 1;
	else if(!visit[adj[x][i]]) {
		if(reach(visit,adj,adj[x][i],y))  return 1;
	}
  } 
  return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<bool> visit(n);
  for(size_t i=0;i<n;i++){
	visit[i]=0;
  }
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(visit,adj, x - 1, y - 1);
}
