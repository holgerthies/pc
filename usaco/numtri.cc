/*
ID: holger1
PROG: numtri
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
	ifstream fin("numtri.in");
	ofstream fout("numtri.out");
	int D[1000][1000];
	int triangle[1000][1000];
	int R;
	fin >> R;
	for(int i=0;i<R;i++){
		for(int j=0;j<=i;j++){
			int t;
			fin >> t;
			triangle[i][j] = t; 
		}
	}
	for(int i=0; i<R; i++) D[R-1][i] = triangle[R-1][i];
	for(int r=R-2;r>=0;r--){
		for(int i=0; i<=r; i++){
			D[r][i] = triangle[r][i]+max(D[r+1][i], D[r+1][i+1]);
		}
	}
	fout << D[0][0]<<endl;
	return 0;
}