/*
ID: holger1
PROG: fence6
LANG: C++11
*/
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
#define MAXN 100
#define INF 10000000

void dijkstra(const int adj[MAXN][2][MAXN][2], const int start, const int N, int dist[MAXN][2]){
	bool visited[MAXN][2];
	bool used[MAXN][2][MAXN][2];
	for(int i=0; i<N;i++){
		dist[i][0] = INF;
		dist[i][1] = INF;
		visited[i][0] = false;
		visited[i][1] = false;
		for(int j=0; j<N;j++){
			used[i][0][j][0] = false;
			used[i][0][j][1] = false;
			used[i][1][j][0] = false;
			used[i][1][j][1] = false;
		}
	}
	used[start][0][start][1] = true;
	dist[start][0] = 0;
	int count=0;
	while(true){
		int min_dist=INF;
		int min_i = -1;
		int min_k = -1;
		for(int i=0;i<N;i++){
			for(int k=0;k<=1;k++){
				if(!visited[i][k] && dist[i][k] < min_dist){
					min_i = i;
					min_k = k;
					min_dist = dist[i][k];
				}
			}
		}
		if(min_i == -1)
			break;
		visited[min_i][min_k] = true;
		for(int i=0; i<N;i++){
			for(int j=0; j<=1;j++){
				if(!used[min_i][min_k][i][j] && dist[min_i][min_k]+adj[min_i][min_k][i][j] < dist[i][j]){
					dist[i][j] = dist[min_i][min_k]+adj[min_i][min_k][i][j];
					used[min_i][min_k][i][j] = true;
					used[i][j][min_i][min_k] = true;
				}
			}
		}
	}
}
int main(){
	ifstream fin("fence6.in");
	ofstream fout("fence6.out");
	int dist[MAXN][2][MAXN][2];
	int adj[MAXN][2][MAXN][2];
	bool neighbors[MAXN][2][MAXN];
	int N;
	int length[MAXN];

	fin >> N;
	for(int i=0; i<MAXN;i++){
		for(int j=0; j<MAXN; j++){
			adj[i][0][j][0] = INF;
			adj[i][1][j][0] = INF;
			adj[i][0][j][1] = INF;
			adj[i][1][j][1] = INF;
			neighbors[i][0][j] = false;
			neighbors[i][1][j] = false;

		}
	}
	for(int i=0; i<N;i++){
		int s, L, N1, N2;
		fin >> s >> L >> N1 >> N2;
		s--;
		length[s] = L;
		for(int j=0; j<N1; j++){
			int n;
			fin >> n;
			neighbors[s][0][n-1] = true;
		}
		for(int j=0; j<N2; j++){
			int n;
			fin >> n;
			neighbors[s][1][n-1] = true;
		}
	}
	for(int i=0; i<N;i++){
		adj[i][0][i][1] = length[i];
		adj[i][1][i][0] = length[i];
		for(int j=0; j<N;j++){
			for(int k1=0;k1<=1;k1++){
				for(int k2=0; k2<=1;k2++){
					if(neighbors[i][k1][j] && neighbors[j][k2][i]){
						adj[i][k1][j][k2] = 0;
						adj[j][k2][i][k1] = 0;
					}
				}
			}
			
		}
	}
	for(int i=0;i<N;i++){
		dijkstra(adj, i, N, dist[i][0]);
	}
	int min_dist=INF;
	for(int i=0; i<N; i++){
		min_dist = min(min_dist, dist[i][0][i][1]+adj[i][0][i][1]);
	}
	fout << min_dist << endl;
	return 0;
}