/*
ID: holger1
PROG: hamming
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

int dist(int x, int y){
	int ans=0;
	int a = x^y;
	while(a){
		a &= a-1;
		ans++;
	}
	return ans;
}

int main(){
	ifstream fin("hamming.in");
	ofstream fout("hamming.out");
	int N,B,D;
	fin >> N >> B >> D;
	int upper=1 << B;
	int curr=0;
	set<int> ans;
	for(int i=0; i<upper;i++){
		bool is_next=true;
		for(int a : ans){
			if(dist(i, a) < D){
				is_next=false;
				break;
			}
		}
		if(is_next){
			ans.insert(i);
		}
		if(ans.size() == N)
			break;
	}
	int count=1;
	for(int i : ans){
		fout << i;
		if(count % 10 == 0 || count == ans.size()){
			fout << endl;
		} else{
			fout << " ";
		}
		count++;
	}
}