/*
ID: holger1
PROG: kimbits
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <stack>
#include <algorithm>
#include <limits>
#include <queue>
using namespace std;

unsigned int C[33][33];

unsigned int choose(int n, int k){
	if(k > n ) return 0;
	return C[n][k];
}
  
unsigned int number(int l, int n){ // number of elements of strings of length l, starting with one and having at most n ones
	unsigned int ans = 0;
	for(int i=0; i<l;i++){
		ans += choose(n-1, i);
	}
	return ans;
}



int main(){
	ifstream fin("kimbits.in");
	ofstream fout("kimbits.out");
	int N, L;
	unsigned int I;
	fin >> N >> L >> I;
	
	I--;
	for(int i=1;i<33;i++){
		C[0][i] = 0;
		C[i][0] = 1;
	}
	C[0][0] = 1;
	for(int i=1; i<33;i++){
		for(int j=1; j<33;j++)
			C[i][j] = C[i-1][j-1]+C[i-1][j];
	}


	bool is_one[32];
	for(int i=0; i<32; i++) is_one[i] = false;
	int a=0;
	while(I > 0){
		unsigned int pos=0;
		for(int f = 1; f <= N; f++){
			unsigned int n=number(L, f);
			//cout << pos+n << endl;
			if(pos+n >= I){
				is_one[f-1] = true;
				I -= pos+1;
				L--;
				break;
			}
			pos += n;
		}
	}
	for(int i=N-1; i>=0;i--){
		fout << (is_one[i] ? 1 : 0);
	}
	fout << endl;
	return 0;
}