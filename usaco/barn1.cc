/*
ID: holger1
PROG: barn1
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

using namespace std;


int main(){
	ifstream fin("barn1.in");
	ofstream fout("barn1.out");
	int M,S,C;
	fin >> M >> S >> C;
	vector<bool> occupied(S+1,false);
	for(int i=0;i<C;i++){
		int j;
		fin >> j;
		occupied[j] = true; 
	}
	int D[201][51][2];
	D[0][0][0] = 0;
	D[0][0][1] = 2*S;
	for(int i=1;i<=S;i++){
		for(int j=0;j<=M;j++){
			if(occupied[i]){
				D[i][j][0] = 10*S;
				D[i][j][1] = 1+D[i-1][j][1];
				if(j > 0)
					D[i][j][1] = min(D[i][j][1], 1+D[i-1][j-1][0]);
			} else{
				D[i][j][0] = min(D[i-1][j][0], D[i-1][j][1]);
				D[i][j][1] = 1+D[i-1][j][1];
			}
		}
	}
	int result = occupied[S] ? D[S][M][1] : D[S][M][0]; 
	fout << result << endl;
	return 0;
}