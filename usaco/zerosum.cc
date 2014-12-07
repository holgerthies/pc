/*
ID: holger1
PROG: zerosum
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
int N;
vector<vector<char>> signs(int len, int result){
	vector<vector<char>> ans(0);
	int x=N-len+1;
	if(len == 1 && x==result || len==0 && result==0){
		ans.push_back(vector<char>());
	}
	if(len <= 1){
		return ans;
	}
	int curr=0;
	for(int i=1;i<=len;i++){
		curr *= 10;
		curr+=(N-len+i);
		vector<vector<char>> plus=signs(len-i, result-curr);
		for(auto p : plus){
			if(i<len)
				p.push_back('+');
			for(int j=1;j<i;j++)
				p.push_back('s');
			ans.push_back(p);
		}
		if(i==len) continue;
		vector<vector<char>> minus=signs(len-i,curr-result);
		for(auto m : minus){
			m.push_back('-');
			for(int j=1;j<i;j++)
				m.push_back('s');
			ans.push_back(m);
		}
	}


	return ans;
}

string reconstruct(vector<char> rules){
	string s="";
	int reverse=false;
	for(int i=1;i<=N;i++){
		s+=i+48;
		if(rules[N-i-1] == 's') s+= ' ';
		else if(rules[N-i-1] == '+')
			s += reverse ? '-' : '+';
		else if(rules[N-i-1] == '-'){
			s += reverse ? '+' : '-';
			reverse = !reverse;
		}
	}
	return s;
}

int main(){
	ifstream fin("zerosum.in");
	ofstream fout("zerosum.out");
	fin>>N;
	vector<vector<char>> all=signs(N,0);
	set<string> sorted;
	for(auto r : all){
		sorted.insert(reconstruct(r));
		//cout << calc(r, 0)<<endl;
	}
	for(auto s : sorted) fout << s <<endl;
	return 0;
}