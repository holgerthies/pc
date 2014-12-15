/*
ID: holger1
PROG: game1
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

#define MAXN 100
using namespace std;


int main(){
	ifstream fin("game1.in");
	ofstream fout("game1.out");
	int points[MAXN][MAXN];
	int sum[MAXN+1];
	int board[MAXN];
	int N;
	fin >> N;
	sum[0] = 0;
	for(int i=0;i<N;i++){
		fin >> board[i];
		sum[i+1] = sum[i]+board[i];
	}
	for(int i=0;i<N;i++)
		points[i][i] = board[i];
	for(int x=N-2;x>=0;x--){
		for(int y=x+1;y<N;y++){
			points[x][y] = max(sum[y+1]-sum[x]-points[x+1][y], sum[y+1]-sum[x]-points[x][y-1]);
		}
	}
	fout << points[0][N-1] << " " << sum[N]-points[0][N-1] << endl;
	return 0;
}