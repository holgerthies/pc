/*
ID: holger1
PROG: sort3
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
	ifstream fin("sort3.in");
	ofstream fout("sort3.out");
	int N;
	fin >> N;
	int count[] = {0,0,0};
	int pos[] = {0,0,0};
	vector<int> in;
	for(int i=0;i<N;i++){
		int x;
		fin >> x;
		count[x-1] += 1;
		in.push_back(x);
	}
	pos[1] = count[0];
	pos[2] = pos[1]+count[1];
	int error=0;
	int p[3][3];
	for(int i=0; i<3;i++)
		for(int j=0; j<3;j++)
			p[i][j] = 0;
	for(int i=0; i<N;i++){
		int c=0;
		if(i >= pos[1]) c=1;
		if(i >= pos[2]) c=2;
		p[in[i]-1][c] += 1;
	}
	 for(int i=0;i<3;i++){
	 	for(int j=0; j<3;j++){
	 		if(i != j){
	 			int move = min(p[i][j], p[j][i]);
				p[i][j] -= move;
	 			p[j][i] -= move;
	 			p[i][i] += move;
	 			p[j][j] += move;
	 			error += move;
	 			int rest = p[i][j];
	 			int k= (i+j == 1) ? 2 : (i+j == 3) ? 0 : 1;
	 			p[i][j] -= rest;
	 			p[i][k] += rest;
	 			p[j][k] -= rest;
	 			p[j][j] += rest;
	 			error += rest;
			}
		}
	}
	fout << error << endl;
}