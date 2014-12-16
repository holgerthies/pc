/*
ID: holger1
PROG: rockers
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
#define INF 5000000
#define MAXN 21
using namespace std;

int main(){
	ifstream fin("rockers.in");
	ofstream fout("rockers.out");
	int N,T,M;
	fin >> N >> T >> M;
	int length[MAXN];
	for(int i=0;i<N;i++)
		fin >> length[i];
	int maxnum[MAXN][MAXN][MAXN];
	for(int i=0;i<=N;i++){
		for(int j=0;j<=N;j++){
			maxnum[i][j][0] = 0;
		}
		for(int t=0;t<=T;t++)
			maxnum[i][0][t] = 0;
	}
	//4 5 3
	//4 3 4 2
	for(int i=1;i<=N;i++){
		maxnum[i][0][0] = 0;
		for(int j=1;j<=M;j++){
			maxnum[i][j][0] = maxnum[i][j-1][T];
			for(int t=1;t<=T;t++){
				if(t>=length[i-1]){
					maxnum[i][j][t] = max(maxnum[i][j][t-1], max(maxnum[i-1][j][t], maxnum[i-1][j][t-length[i-1]]+1)); 
				}
				else{
					maxnum[i][j][t] = max(maxnum[i-1][j][t], maxnum[i][j][t-1]);
				}
			}
		}
	}

	fout << maxnum[N][M][T]<<endl;
	return 0;
}