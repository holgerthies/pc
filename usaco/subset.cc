/*
ID: holger1
PROG: subset
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
#include <queue> 

using namespace std;

int main(){
	ifstream fin("subset.in");
	ofstream fout("subset.out");
	int N;
	fin >> N;
	if(N*(N+1) % 4 != 0){
		fout << 0 << endl;
		return 0;
	}
	int sum=(N*(N+1))/4;
	int D[41][410] = {0};
	for(int i=0; i<=N;i++){
		D[i][0] = 1;
	}
	for(int i=N;i>0; i--){
		for(int k=i; k<=sum;k++){
			D[i][k] = D[i+1][k]+D[i+1][k-i];
		}
	}
	fout << D[1][sum]<<endl;
	return 0;
}