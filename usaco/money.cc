/*
ID: holger1
PROG: money
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
	ifstream fin("money.in");
	ofstream fout("money.out");
	int V,N;
	fin >> V >> N;
	int coins[25];
	for(int i=0;i<V;i++)
		fin >> coins[i];
	long long M[10001][26] = {0};
	for(int i=0; i<V;i++)
		M[0][i] = 1;
	for(int i=1; i<=N;i++){
		for(int j=0;j<V;j++){
			M[i][j] = 0;
			if(coins[j] <= i){
				M[i][j] += M[i-coins[j]][j];
			}
			if(j > 0)
				M[i][j] += M[i][j-1];
		}
	}
	fout << M[N][V-1] <<endl;
}