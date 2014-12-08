/*
ID: holger1
PROG: comehome
LANG: C++11
*/
#define INF 10000000
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <stack>
#include <algorithm>
#include <limits>
#include <queue>

using namespace std;


int get_min(int* dist, unordered_set<int> visited){
	int min_ind =-1;
	for(int i=0; i<52;i++){
		if(visited.find(i) != visited.end()) continue;
		if(dist[i] != INF && (min_ind == -1 || dist[i] < dist[min_ind])) min_ind = i;
	}
	return min_ind;
}
void dijkstra(int adj[52][52], const int start, int* dist){
	dist[start] = 0;
	unordered_set<int> visited;
	while(visited.size() < 52){
		int v = get_min(dist, visited);
		visited.insert(v);
		if(v == -1) break;
		for(int i=0;i<52;i++){
			if(adj[v][i] != INF){
				if(dist[v]+adj[v][i] < dist[i])
					dist[i] = dist[v]+adj[v][i];
			}
		}
	}
}
int main(){
	ifstream fin("comehome.in");
	ofstream fout("comehome.out");
	int adj[52][52];
	for(int i=0; i<52;i++)
		for(int j=0; j<52;j++)
			adj[i][j] = INF;
	int P;
	fin >> P;
	for(int i=0;i<P;i++){
		char u,v;
		int w;
		fin >> u >> v >> w;
		int a = int(u);
		int b= int(v);
		if(a > 90) a-= 97;
		else a-=39;
		if(b > 90) b-=97;
		else b-=39;
		adj[a][b] = min(adj[a][b],w);
		adj[b][a] = min(adj[b][a], w);
	}
	int dist[52];
	for(int i=0; i<52;i++) dist[i] = INF;
	dijkstra(adj, 51, dist);
	int min_dist=INF;
	int min_ind=-1;
	for(int i=26;i<51;i++){
		if(dist[i] < min_dist){
			min_dist = dist[i];
			min_ind = i;
		}
	}
	fout << char(min_ind+39) << " " << min_dist <<endl;
	return 0;
}