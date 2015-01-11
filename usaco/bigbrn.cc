/*
ID: holger1
PROG: bigbrn
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
#define INF 500000000
#define MAXQ 20000
#define MAXP 100
#define MAXVAL 10000
#define rep(n) for(int i=0;i<(n);i++) 
using namespace std;

bool possible(const int x, const int y, const vector<vector<int>>& count, const int size){
	int N=(int)count.size();
	if(x+size > N || y+size > N) return false;
	int top = x>0 ? count[x-1][y+size-1] : 0;
	int left = y>0 ? count[x+size-1][y-1] : 0;
	int d = x>0 && y>0 ? count[x-1][y-1] : 0;
	int c = count[x+size-1][y+size-1]-(top+left-d);
	return c==0;
}

bool possible(const vector<vector<int>>& count, const int size){
	int N=(int)count.size();
	for(int i=0;i<=N-size;i++){
		for(int j=0;j<=N-size;j++){
			if(possible(i,j, count, size))
				return true;
		}
	}
	return false;
}

int binary_search(const vector<vector<int>>& count, const int left, const int right){
	if(left >= right){
		return left;
	}
	int middle=(left+right+1)/2;
	if(possible(count, middle)){
		return binary_search(count,middle, right);
	}
	return binary_search(count,left,middle-1);
}

int main(){
	ifstream fin("bigbrn.in");
	ofstream fout("bigbrn.out");
	int N,T;
	fin >> N >> T;
	vector<vector<int>> count(N, vector<int>(N, 0)); 
	vector<vector<bool>> tree(N, vector<bool>(N, false));
	for(int i=0; i<T;i++){
		int x,y;
		fin >> x >> y;
		x--;y--;	
		tree[x][y] = true;
	}
	if(tree[0][0])
		count[0][0] = 1; 
	for(int j=1;j<N;j++){
		count[0][j] = tree[0][j] ? count[0][j-1]+1 : count[0][j-1];
	}
	for(int i=1; i<N;i++){
		count[i][0] = tree[i][0] ? count[i-1][0]+1 : count[i-1][0];
		for(int j=1; j<N;j++){
			count[i][j] = count[i][j-1]+count[i-1][j]-count[i-1][j-1];
			if(tree[i][j]) count[i][j]++;
		}
	}
	int ans = binary_search(count,1,N);
	fout<<ans<<endl;
	return 0;
}