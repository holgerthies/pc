/*
ID: holger1
PROG: stamps
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

#define MAXK 200
#define MAXN 50
#define MAXV 10000

using namespace std;

int main(){
	ifstream fin("stamps.in");
	ofstream fout("stamps.out");
	int N,K;
	fin >> K >> N;
	vector<int> ans={0};
	vector<int> vals;
	bool possible[MAXK*MAXV+1];
	for(int i=0;i<=MAXK*MAXV;i++) possible[i]=false;
	possible[0] = true;
	for(int i=0;i<N;i++){
		int v;
		fin >> v;
		vals.push_back(v);
	}
	set<int> added={0};
	for(int k=0;k<K;k++){
		set<int> temp;
		for(int x : added){
			for(int v : vals){
				if(!possible[x+v]){
					temp.insert(x+v);
					possible[x+v] = true;
				}
			}
		}
		added = temp;
	}
	int curr=0;
	int length=0;
	int max_length=0;
	for(int a=1; a<=MAXK*MAXV; a++){
		if(possible[a]){
			length+=1;
			max_length = max(length, max_length);
		}
		else{
			length = 0;
		}
	}
	fout << max_length << endl;
}