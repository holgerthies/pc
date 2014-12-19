/*
ID: holger1
PROG: ditch
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <stack>
#include <algorithm>
#include <limits>
#include <queue>
#include <memory>
#define INF 500000000
#define contains(c,v) ((c).find((v)) != (c).end()) 
using namespace std;
using vi=vector<int>;
using vii=vector<vector<int>>;
struct edge{
	int from;
	int to;
	int capacity;
	int flow;
	shared_ptr<edge> reverse_edge;
};

int bfs(const vector<vector<shared_ptr<edge>>>& adj, int source, int sink, unordered_map<int, shared_ptr<edge>>& pred_edge){
	queue<int> Q;
	unordered_set<int> visited;
	Q.push(source);
	vi capacity(adj.size(), 0);
	capacity[source] = INF;
	visited.insert(source);
	while(!Q.empty()){
		int v = Q.front();
		Q.pop();
		if(v == sink){
			break;
		}
		
		for(shared_ptr<edge> e : adj[v]){
			if(!contains(visited, e->to)){
				int residual_capacity=e->capacity-e->flow;
				if(residual_capacity > 0){
					visited.insert(e->to);
					pred_edge[e->to] = e;
					capacity[e->to] = min(capacity[v], residual_capacity);
					Q.push(e->to);
				}
			}
		}
	}
	return capacity[sink];
}

int edmondsKarp(const vector<vector<shared_ptr<edge>>>& adj, int source, int sink){
	int augmenting;
	int ans = 0, count=0;
	do{
		unordered_map<int, shared_ptr<edge>> pred_edge;
		pred_edge.clear();
		augmenting = bfs(adj, source, sink, pred_edge);
		if(augmenting > 0){
			int v=sink;
			while(v != source){
				shared_ptr<edge> e=pred_edge[v];
				e->flow += augmenting;
				e->reverse_edge->flow -= augmenting;
				v = e->from;
			}
			ans += augmenting;
		}
	} while(augmenting > 0);
	return ans;
}

int main(){
	ifstream fin("ditch.in");
	ofstream fout("ditch.out");
	int N,M;
	fin >> N >> M;
	vector<vector<shared_ptr<edge>>> adj(M, vector<shared_ptr<edge>>());
	for(int i=0; i<N;i++){
		int f,t,c;
		fin >> f >> t >> c;
		shared_ptr<edge> e = shared_ptr<edge>(new edge);
		shared_ptr<edge> e_rev= shared_ptr<edge>(new edge);
		e->from = f-1;
		e->to = t-1;
		e->capacity = c;
		e->flow = 0;
		e_rev->from = t-1;
		e_rev->to = f-1;
		e_rev->capacity = c;
		e_rev->flow = c; 
		e->reverse_edge = e_rev;
		e_rev->reverse_edge = e;
		adj[f-1].push_back(e);
		adj[t-1].push_back(e_rev);
	}
	fout << edmondsKarp(adj, 0, M-1) << endl;

	return 0;
}