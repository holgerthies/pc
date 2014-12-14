/*
ID: holger1
PROG: range
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

#define MAXN 250
using namespace std;

bool check(int field[MAXN][MAXN], int y, int x, int size){
	for(int i=y;i<y+size;i++){
		for(int j=x;j<x+size;j++){
			if(field[i][j] == 0)
				return false;
		}
	}
	return true;
}

int main(){
	ifstream fin("range.in");
	ofstream fout("range.out");
	int N;
	fin >> N;
	int field[MAXN][MAXN];
	for(int i=0; i<N;i++){
		for(int j=0; j<N;j++){
			field[i][j] = fin.get();
			if(field[i][j] == 10)
				field[i][j] = fin.get();
			field[i][j] -= 48;
		}
	}

	vector<vector<vector<bool>>> valid(MAXN, vector<vector<bool>>(MAXN, vector<bool>(MAXN+1)));
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
			valid[i][j][1] = field[i][j];
	}
	for(int size=2; size<=N; size++){
		for(int i=0; i<=N-size;i++){
			for(int j=0; j<=N-size;j++){
				valid[i][j][size] = valid[i][j][size-1] 
									&& valid[i+1][j][size-1]
									&& valid[i][j+1][size-1]
									&& valid[i+1][j+1][size-1];
			}
		}
	}
	for(int size=2; size<=N; size++){
		int count=0;
		for(int i=0; i<=N-size;i++){
			for(int j=0; j<=N-size;j++){
				if(valid[i][j][size]){
					count++;
				}
			}
		}
		if(count > 0)
			fout << size << " " << count << endl;
	}
}