/*
ID: holger1
PROG: butter
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
#define MAXP 800
#define MAXN 500
#define INF 5000000
using namespace std;

int main(){
	ifstream fin("butter.in");
	ofstream fout("butter.out");
	int N,P,C;
	int dist[MAXP][MAXP];
	for(int i=0; i<MAXP;i++){
		for(int j=0; j<MAXP; j++){
			dist[i][j] = INF;
		}
		dist[i][i] = 0;
	}
	int pasture[MAXN];
	int num[MAXP];
	fin >> N >> P >> C;

	for(int i=0; i<P;i++) num[i] = 0;
	for(int i=0; i<N;i++){
		fin >> pasture[i];
		pasture[i]--;
		num[pasture[i]]++;
	}
	for(int i=0; i<C;i++){
		int u,v;
		fin >> u >> v;
		fin >> dist[u-1][v-1];
		dist[v-1][u-1] = dist[u-1][v-1];
	}
	for(int k=0; k<P;k++){
		for(int i=0; i<P;i++){
			if(dist[i][k] == INF) continue;
			for(int j=i+1; j<P;j++){
				if(dist[i][k] + dist[k][j] < dist[i][j]){
					dist[i][j] = dist[i][k]+dist[k][j];
					dist[j][i] = dist[i][j];
				}
			}
		}
	}
	int min_dist=INF;
	for(int p=0; p<P; p++){
		int d=0;
		for(int i=0; i<P; i++){
			d += num[i]*dist[i][p];
		}
		min_dist = min(d, min_dist);
	}
	fout << min_dist << endl;
}