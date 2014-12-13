/*
ID: holger1
PROG: fence
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <stack>
#include <algorithm>
#include <limits>
#include <queue> 
#define INF 1000000
#define MAXN 500
using namespace std;

void find_cycle(const int start, int& F, int adj[MAXN][MAXN], vector<int>& cycle){
	bool found=false;
	for(int i=0; i<MAXN;i++){
		if(adj[i][start] > 0){
			found=true;
			adj[i][start]--;
			adj[start][i]--;
			F--;
			find_cycle(i,F,adj,cycle);
		}
	}
	cycle.push_back(start);

}
int main(){
	ifstream fin("fence.in");
	ofstream fout("fence.out");
	int adj[MAXN][MAXN];
	int deg[MAXN];
	for(int i=0;i<MAXN;i++){
		for(int j=0; j<MAXN;j++)
			adj[i][j] = 0;
	}
	int F;
	fin >> F;
	int smallest = INF;
	for(int i=0; i<F;i++){
		int f, t;
		fin >> f >> t;
		f--;t--;
		adj[f][t]++;
		adj[t][f]++;
		deg[f]++;
		deg[t]++;
		smallest = min(smallest, min(f,t));
	}
	vector<int> ans;
	int start_node=INF;
	for(int i=0; i<MAXN;i++){
		if(deg[i] > 0){
			start_node = i;
			break;
		}
	}

	for(int i=0; i<MAXN;i++){
		if(deg[i] % 2 == 1){
			start_node = i;
			break;
		}
	}

	find_cycle(start_node, F, adj, ans);
	reverse(ans.begin(),ans.end());

	for(int v : ans){
		fout << v+1 << endl;
	}
	return 0;
}