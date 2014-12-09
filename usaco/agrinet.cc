/*
ID: holger1
PROG: agrinet
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

int main(){
	ifstream fin("agrinet.in");
	ofstream fout("agrinet.out");
	int adj[100][100];
	int N;
	fin >> N;
	int dist[100];
	for(int i=0;i<N;i++) dist[i]=INF;
	dist[0] = 0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			fin >> adj[i][j];
		}
	}
	bool chosen[100];
	int total_dist = 0;
	while(true){
		int min=-1;
		for(int i=0;i<N;i++){
			if((min==-1 || dist[i] < dist[min]) && !chosen[i])
				min=i;
		}
		if(min==-1) break;
		chosen[min]=true;
		total_dist+=dist[min];
		for(int i=0;i<N;i++){
			if(!chosen[i] && adj[min][i] < dist[i]){
				dist[i] = adj[min][i];
			}
		}
	}
	fout << total_dist <<endl;
	return 0;
}