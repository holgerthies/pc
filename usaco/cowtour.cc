/*
ID: holger1
PROG: cowtour
LANG: C++11
*/
#define INF 1000000000
#define MAX_N 150
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
#include <iomanip>

using namespace std;

double distance(int i, int j, int* X, int* Y){
	return sqrt(double(pow(X[i]-X[j],2)+pow(Y[i]-Y[j],2)));
}



void FloydWarshall(bool adj[MAX_N][MAX_N], int* X, int* Y, int N, double dist[MAX_N][MAX_N]){
	for(int i=0; i<N;i++){
		for(int j=0;j<N;j++){
			dist[i][j] = adj[i][j] ? distance(i, j, X,Y) : INF;
		}
	}
	for(int k=0; k<N;k++){
		for(int i=0; i<N;i++){
			for(int j=0; j<N;j++){
				if(dist[i][j] > dist[i][k]+dist[k][j])
					dist[i][j] = dist[i][k]+dist[k][j];
			}
		}
	}
}

void set_component(bool adj[MAX_N][MAX_N], int N, int v, int c, int* components){
	components[v] = c;
	for(int w=0; w<N;w++){
		if(adj[v][w] && components[w]==-1){
			set_component(adj, N, w, c, components);
		}
	}
}

void fill_components(bool adj[MAX_N][MAX_N], int N, int* components){
	for(int i=0; i<N;i++)
		components[i] = -1;
	int c=0;
	for(int i=0;i<N;i++){
		if(components[i] == -1){
			set_component(adj, N, i, c, components);
			c++;
		}
	}
}

int main(){
	ifstream fin("cowtour.in");
	ofstream fout("cowtour.out");
	bool adj[150][150];
	int X[150];
	int Y[150];
	int N;
	fin >> N;
	for(int i=0; i<N;i++){
		fin >> X[i] >> Y[i];
	}
	for(int i=0;i<N;i++){
		fin.get();
		for(int j=0;j<N;j++){
			char c;
			fin.get(c);
			adj[i][j] = (c == '1');
		}
		
	}
	double dist[150][150];
	int components[150];
	fill_components(adj, N, components);
	FloydWarshall(adj, X,Y, N, dist);
	double max_dist[150];
	double diam1=0;
	double diam2=0;
	for(int i=0; i<N;i++){
		max_dist[i] = 0;
		for(int j=0; j<N;j++)
			if(i != j && components[i] == components[j]){
				max_dist[i] = max(max_dist[i], dist[i][j]);
			}
		if(components[i] == 0) diam1=max(max_dist[i],diam1);
		if(components[i] == 1) diam2=max(max_dist[i],diam2);

	}

	double min_diam=INF;
	for(int i=0;i<N;i++){
		for(int j=0; j<N;j++){
			if(components[i] != components[j]){
				min_diam = min(min_diam, max_dist[i]+max_dist[j]+distance(i,j,X,Y));
			}
		}
	}
	fout << fixed << setprecision(6)<< max(diam1, max(diam2, min_diam))<<endl;
	return 0;
}