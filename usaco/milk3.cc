/*
ID: holger1
PROG: milk3
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

using namespace std;

int A[3];
vector<tuple<int,int,int>> neighbors(tuple<int,int,int> v){
	vector<tuple<int,int,int>> n;
	int S[3];
	tie(S[0], S[1], S[2]) = v;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(j != i){
				int new_S[3] = {S[0], S[1], S[2]};
				int diff = min(S[i], A[j]-S[j]);
				new_S[i] -= diff;
				new_S[j] += diff;
				n.push_back(make_tuple(new_S[0], new_S[1], new_S[2]));
			}
		}
	}
	return n;
} 

int main(){
	ifstream fin("milk3.in");
	ofstream fout("milk3.out");
	fin >> A[0] >> A[1] >> A[2];
	tuple<int,int,int> state(0,0,A[2]);
	vector<tuple<int,int,int>> visited = {state};
	set<int> result;
	stack<tuple<int,int,int>> S;
	S.push(state);
	while(!S.empty()){
		auto v = S.top();
		S.pop();
		int v0,v2;
		tie(v0, ignore,v2) = v;
		if(v0 == 0)
			result.insert(v2);
		for(auto w : neighbors(v)){
			if(find(visited.begin(), visited.end(), w) == visited.end()){
				visited.push_back(w);
				S.push(w);
			}
		}
	}
	bool first=true;
	for(int r : result){
		if(!first) fout << " ";
		first=false;
		fout << r;
	}
	fout << endl;
}