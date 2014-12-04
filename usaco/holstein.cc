/*
ID: holger1
PROG: holstein
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

int backtrack(int v,int g, int p, int requires[25], int feeds[15][25], bool* chosen){
	if(p > g) return -1;
	bool done=true;
	for(int i=0; i<v;i++){
		//cout << requires[i] << " ";
		if(requires[i] > 0){
			done=false;
			break;
		}
	}
	//cout << endl;
	if(done) return 0;
	for(int i=0; i<v;i++){
		requires[i] -= feeds[p][i];
	}
	bool new_chosen[15];
	for(int i=0; i<15;i++) new_chosen[i] = chosen[i];
	new_chosen[p] = true;
	int m1=backtrack(v,g, p+1, requires, feeds, new_chosen);
	if(m1 != -1) m1++;
	for(int i=0; i<v;i++){
		requires[i] += feeds[p][i];
	}
	int m2=backtrack(v,g, p+1, requires, feeds, chosen);
	if(m1 != -1 && (m1 <= m2 || m2==-1)){
		for(int i=0;i<15;i++) chosen[i] = new_chosen[i];
		return m1;
	}
	return m2;
}
int main(){

	ifstream fin("holstein.in");
	ofstream fout("holstein.out");
	int v;
	fin >> v;
	int requires[25];
	for(int i=0; i<v;i++)
		fin >> requires[i];
	int g;
	fin >> g;
	int feeds[15][25];
	for(int i=0;i<g;i++){
		for(int j=0; j<v;j++){
			fin >> feeds[i][j];
		}
	} 
	bool chosen[15] = {false};
	int n = backtrack(v,g, 0, requires, feeds, chosen);
	fout << n;
	for(int i=0; i<g;i++)
		if(chosen[i])
			fout << " " << i+1;
	fout << endl;
}