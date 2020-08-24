#include <iostream>
#include <vector>
#include <queue>
#include<bits/stdc++.h>
using namespace std;
using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

/* pair<vertex,dist> */
class Comparator 
{ 
public: 
    int operator() (const pair<int,int>& p1, const pair<int,int>& p2) 
    { 
        return p1.second > p2.second; 
    } 
};

int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  priority_queue <pair<int,int>, vector<pair<int,int>>, Comparator> pq;
  vector<int> dist(adj.size(),100000);
  
  dist[s]=0;
  pq.push(make_pair(s,dist[s]));
  while(!pq.empty()){
  	pair<int,int> k=pq.top();
  	int x=k.first,y=k.second;
  	pq.pop();
  
  	for(size_t i=0;i<adj[x].size();i++){
  		if(dist[adj[x][i]]>y+cost[x][i]) { dist[adj[x][i]]=y+cost[x][i];
  						    pq.push(make_pair(adj[x][i],dist[adj[x][i]]));  } 						    
  		}
  	}
  	
  if(dist[t]!=100000) return dist[t];
  return -1;
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
