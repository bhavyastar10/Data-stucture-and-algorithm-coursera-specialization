#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int distance(vector<vector<int> > &adj, int s, int t) {
  vector<int> dist(adj.size(),100000);
  queue<int> q;
  dist[s]=0;
  q.push(s);
  while(!q.empty()){
  	int k=q.front();
  	q.pop();
  	for(size_t i=0;i<adj[k].size();i++){
  		if(dist[adj[k][i]]==100000){
  			dist[adj[k][i]]=dist[k]+1;
  			q.push(adj[k][i]); }
  		if(adj[k][i]==t) return dist[t];
  		}
  	}
  
  return -1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
