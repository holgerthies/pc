/*
ID: holger1
PROG: milk6
LANG: C++11
*/
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <limits>
#include <tuple>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iterator>
#include <string>
#include <fstream>
#define FOR(k,a,b) for(typeof(a) k=(a); k <= (b); ++k)
#define REP(k,a) for(int k=0; k < (a); ++k)
#define INF 20000000000000000L
using namespace std;


// Graph is given is adjacency matrix (vector<vector<int>>)

long long bfs(const vector<vector<long long>>& G, const int s, const int t, vector<int>& parent, vector<bool>& visited){
	int n = G.size();
	queue<int> q;
	q.push(s);
	visited[s] = true;
	long long min_cut=-1;
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(int i=0; i<n;i++){
			if(!visited[i] && G[v][i] > 0){
				visited[i] = true;
				parent[i] = v;
				q.push(i);
				if(min_cut == -1)
					min_cut = G[v][i];
				else
					min_cut = min(min_cut, G[v][i]);
				if(i == t)
					return min_cut;
			}
		}
	}
	return 0;
}

long long maxflow(vector<vector<long long>>& G, const int s, const int t){
	bool increment=true;
	int n = G.size();
	long long ans=0;
	while(increment){
		vector<int> parent(n, -1);
		vector<bool> visited = vector<bool>(G.size(), false);
		long long flow=bfs(G, s, t, parent, visited);

		if(flow > 0){
			int curr=t;
			ans+=flow;
			while(curr != s){
				G[parent[curr]][curr] -= flow;
				G[curr][parent[curr]] += flow;
				curr = parent[curr];
			}
		} else{
			increment=false;
		}
	}
	return ans;
}



int main(){
	ifstream fin("milk6.in");
	ofstream fout("milk6.out");
	int N,M;
	fin >> N >> M;
	vector<vector<long long>> adj(N, vector<long long>(N, 0));
	vector<vector<long long>> orig_adj(N, vector<long long>(N, 0));
	vector<vector<set<int>>> edge_name(N,vector<set<int>>(N,set<int>()));

	REP(i,M){
		long long s,e,c;
		fin >> s >> e >> c;
		adj[s-1][e-1] += 3*M*c+M+i;
		orig_adj[s-1][e-1] += c;
		edge_name[s-1][e-1].insert(i+1);
	}
	auto G(adj);
	int ans = maxflow(orig_adj, 0,N-1);
	maxflow(G,0,N-1);
	vector<bool> reachable(N,false);
	vector<int> parent(N,-1);
	bfs(G, 0, -1, parent, reachable);
	set<int> edges;
	REP(i,N){
		if(reachable[i]){
			REP(j,N){
				if(!reachable[j] && adj[i][j]>0){
					for(int e : edge_name[i][j])
						edges.insert(e);
				}
			}
		}
	}
	fout<<ans<< " "<<edges.size()<<endl;
	for(int e : edges){
		fout<<e <<endl;
	}
	return 0;
}