/*
ID: holger1
PROG: stall4
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

bool bfs(int N, int M, vector<vector<bool>>& adj){
	queue<int> q;
	q.push(0);
	vi parent(adj.size(), -1);
	while(!q.empty()){
		int v = q.front();
		q.pop();
		if(v == N+M+1){
			break;
		}
		for(int i=0; i<=N+M+1;i++){
			if(adj[v][i] && parent[i] == -1){
				parent[i] = v;
				q.push(i);
			}
		}
	}
	if(parent[N+M+1] == -1){
		return false;
	}
	int v = N+M+1;
	while(v != 0){
		adj[parent[v]][v] = false;
		adj[v][parent[v]] = true;
		v = parent[v];
	}
	return true;
}

int main(){
	ifstream fin("stall4.in");
	ofstream fout("stall4.out");
	int N,M;
	fin >> N >> M;
	vector<vector<bool>> adj(N+M+2, vector<bool>(N+M+2, false));

	for(int i=1; i<=N;i++){
		int S;
		fin >> S;
		adj[0][i] = true;
		for(int j=0; j<S;j++){
			int v;
			fin >> v;
			adj[i][N+v] = true;
		}
	}
	for(int i=1;i<=M;i++){
		adj[N+i][N+M+1] = true;
	}

	int max_flow=0;
	while(bfs(M,N, adj)){
		max_flow++;
	}
	fout << max_flow << endl;
	return 0;
}