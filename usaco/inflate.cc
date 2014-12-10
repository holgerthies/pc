/*
ID: holger1
PROG: inflate
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
#include <unordered_set>

#define MAXM 10000
#define MAXN 10000

using namespace std;

int main(){
	ifstream fin("inflate.in");
	ofstream fout("inflate.out");
	int v[MAXN], w[MAXN];
	int m[MAXM+1];
	for(int i=0; i<=MAXM;i++)
		m[i] = 0;
	int N,M;
	fin >> M >> N;
	for(int i=0; i<N;i++){
		fin >> v[i] >> w[i];
	}
	for(int weight=1; weight<=M;weight++){
		for(int i=0; i<N; i++){
			if(w[i] <= weight){
				m[weight] = max(m[weight], v[i]+m[weight-w[i]]);
			}
		}
	}
	fout << m[M] << endl;
	return 0;
}