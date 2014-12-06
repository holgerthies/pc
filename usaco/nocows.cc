/*
ID: holger1
PROG: nocows
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
	ifstream fin("nocows.in");
	ofstream fout("nocows.out");
	int N,K;
	fin >> N >> K;
	int D[201][101] = {0};
	int Ds[201][101] = {0};
	D[0][0] = 1;
	D[1][1] = 1;
	for(int k=1;k<=K;k++){
		Ds[1][k] = 1;
		for(int n=2;n<=N;n++){
			for(int j=1;j<n;j++){
				D[n][k] += Ds[j][k-2]*D[n-j-1][k-1]+D[j][k-1]*Ds[n-j-1][k-2]+D[j][k-1]*D[n-j-1][k-1];
				D[n][k] %= 9901;
			}
			Ds[n][k] = D[n][k]+Ds[n][k-1];
			Ds[n][k] %= 9901;
		}
	}
 	fout << D[N][K]<<endl;
}