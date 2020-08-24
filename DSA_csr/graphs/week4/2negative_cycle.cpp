#include <iostream>
#include <vector>

using namespace std;
using std::vector;

int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
  vector<int> dis(adj.size(),100000);
  dis[0]=0;
  for(size_t x=0;x<adj.size()-1;x++){
  	for(size_t i=0;i<adj.size()-1;i++){
  	
  		for(size_t j=0;j<adj[i].size();j++){ 
  			if(dis[i]+cost[i][j]<dis[adj[i][j]])   dis[adj[i][j]]=dis[i]+cost[i][j];
  			
  			}
  	}
  }
  for(size_t i=0;i<adj.size()-1;i++){
  		
  		for(size_t j=0;j<adj[i].size();j++){ 
  			if(dis[i]+cost[i][j]<dis[adj[i][j]])   return 1;
  			}
  	}
  return 0;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cout << negative_cycle(adj, cost);
}
