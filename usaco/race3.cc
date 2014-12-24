/*
ID: holger1
PROG: race3
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
#include <unordered_set>

using namespace std;

bool has_to_pass(const vector<vector<int>>& adj, const int n, int goal=-1){
	int N=adj.size();
	if(goal == -1) goal=N-1;
	if(goal == 0) return false;
	vector<bool> visited(N, false);
	visited[0] = true;
	vector<int> stack={0};
	while(!stack.empty()){
		int v=*(stack.end()-1);
		stack.resize(stack.size()-1);
		for(int w : adj[v]){
			if(!visited[w] && w != n){
				if(w == goal) return false;
				visited[w] = true;
				stack.push_back(w);
			}
		}
	}
	return true;
}

bool reachable(const vector<vector<int>>& adj, const int s, const int t){
	int N=adj.size();
	vector<bool> visited(N, false);
	visited[s] = true;
	vector<int> stack={s};
	while(!stack.empty()){
		int v=*(stack.end()-1);
		stack.resize(stack.size()-1);
		for(int w : adj[v]){
			if(!visited[w]){
				if(w == t) return true;
				visited[w] = true;
				stack.push_back(w);
			}
		}
	}
	return false;
}

int main(){
	ifstream fin("race3.in");
	ofstream fout("race3.out");
	vector<vector<int>> edges;
	bool reading=true;
	while(reading){
		vector<int> adj;
		while(true){
			int n;
			fin >> n;
			if(n==-1){
				reading=false;
				break;
			}
			if(n==-2)
				break;
			adj.push_back(n);
		}
		if(reading)
			edges.push_back(adj);
	}
	vector<vector<int>> edges_ud(edges.size(), vector<int>());
	for(int i=0; i<edges.size(); i++){
		for(int v : edges[i]){
			if(find(edges_ud[i].begin(), edges_ud[i].end(), v) == edges_ud[i].end())
				edges_ud[i].push_back(v);
			if(find(edges_ud[v].begin(), edges_ud[v].end(), i) == edges_ud[v].end())
				edges_ud[v].push_back(i);
		}
	}
	int c=0;
	set<int> unavoidable;
	set<int> splitting;
	for(int i=1; i<edges.size()-1; i++){
		if(has_to_pass(edges, i))
			unavoidable.insert(i);
		if(has_to_pass(edges_ud, i)){
			bool valid=true;
			for(int v : edges[i]){
				if(!has_to_pass(edges, i, v)){
					valid=false;
					break;
				}
			}
			if(valid)
				splitting.insert(i);
		}
	}
	fout << unavoidable.size();
	for(int x : unavoidable){
		fout << " "<<x;
	}
	fout << endl;
	fout << splitting.size();
	for(int x : splitting){
		fout << " "<<x;
	}
	fout << endl;
}