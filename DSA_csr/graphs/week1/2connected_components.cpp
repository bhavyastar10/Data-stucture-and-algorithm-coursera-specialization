#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void reach(vector<bool> &visit,vector<vector<int> > &adj, int x) {
  visit[x]=1;
  for(size_t i=0;i<adj[x].size();i++){
	if(!visit[adj[x][i]]) {
		reach(visit,adj,adj[x][i]);
	}
  } 
}

int number_of_components(vector<vector<int> > &adj) {
  int res = 0;
  vector<bool> visit(adj.size());
  for(size_t i=0;i<adj.size();i++){
	visit[i]=0;
  }
  for(size_t i=0;i<adj.size();i++){
	if(!visit[i]){
		visit[i]=1;
		for(size_t j=0;j<adj[i].size();j++){
			if(!visit[adj[i][j]]) {
				 reach(visit,adj,adj[i][j]);
			}
		}
	res++;
	}
  } 
  return res;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << number_of_components(adj);
}
