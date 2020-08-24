#include <iostream>
#include <limits>
#include <vector>
#include <queue>

using namespace std;
using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

class Comparator 
{ 
public: 
    int operator() (const pair<int,int>& p1, const pair<int,int>& p2) 
    { 
        return p1.second > p2.second; 
    } 
};

void shortest_paths(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, vector<long long> &distance, vector<int> &reachable, vector<int> &shortest) {
  queue<int> q;
  reachable[s]=1;
  distance[s]=0;
  for(size_t i=0;i<adj.size();i++){
  
  	for(size_t u=0;u<adj.size();u++){
  	
  		for(size_t k=0;k<adj[u].size();k++){
  			int v = adj[u][k];
      			  if (distance[u]!= std::numeric_limits<long long>::max() && distance[v] > distance[u] + cost[u][k]) {
    				      distance[v] = distance[u] + cost[u][k];
    				      reachable[v] = 1;
    				      if (i == adj.size() - 1) 	q.push(v);
    			      }
  		}
  	}
  }
  vector<int> visit(adj.size(),0);
  while(!q.empty()){
  	int i=q.front();
  	q.pop();
  	visit[i]=1;
  	shortest[i]=0;
  	for(size_t j=0;j<adj[i].size();j++){
  		if(!visit[adj[i][j]])  { q.push(adj[i][j]);  }
  	}
  }
  distance[s]=0;
}

int main() {
  int n, m, s;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;	
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cin >> s;
  s--;
  vector<long long> distance(n, std::numeric_limits<long long>::max());
  vector<int> reachable(n, 0);
  vector<int> shortest(n, 1);
  shortest_paths(adj, cost, s, distance, reachable, shortest);
  for (int i = 0; i < n; i++) {
    if (!reachable[i]) {
      std::cout << "*\n";
    } else if (!shortest[i]) {
      std::cout << "-\n";
    } else {
      std::cout << distance[i] << "\n";
    }
  }
}
