/*
ID: holger1
PROG: lamps
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

map<string, string> invert_map;
map<string, string> invert_even_map;
map<string, string> invert_odd_map;
map<string, string> invert_3n_map;


string invert(string s){
	if(invert_map.find(s) != invert_map.end())
		return invert_map[s];
	string ans = "";
	for(char c : s){
		ans += (c == '0') ? '1' : '0';
	}
	invert_map[s] = ans;
	return ans;
}

string invert_even(string s){
	if(invert_even_map.find(s) != invert_even_map.end())
		return invert_even_map[s];
	string ans = "";
	for(int i=0; i<s.length();i++){
		char c = s[i];
		if(i % 2 == 0)
			ans += (c == '0') ? '1' : '0';
		else
			ans += c;
	}
	invert_even_map[s] = ans;
	return ans;
}

string invert_odd(string s){
	if(invert_odd_map.find(s) != invert_odd_map.end())
		return invert_odd_map[s];
	string ans = "";
	for(int i=0; i<s.length();i++){
		char c = s[i];
		if(i % 2 == 1)
			ans += (c == '0') ? '1' : '0';
		else
			ans += c;
	}
	invert_odd_map[s] = ans;
	return ans;
}

string invert_mod3(string s){
	if(invert_3n_map.find(s) != invert_3n_map.end())
		return invert_3n_map[s];
	string ans = "";
	for(int i=0; i<s.length();i++){
		char c = s[i];
		if(i % 3 == 0)
			ans += (c == '0') ? '1' : '0';
		else
			ans += c;
	}
	invert_3n_map[s] = ans;
	return ans;
}



int main(){
	ifstream fin("lamps.in");
	ofstream fout("lamps.out");
	int N, C;
	fin >> N >> C;
	vector<int> on;
	vector<int> off;
	while(true){
		int l;
		fin >> l;
		if(l==-1) break;
		on.push_back(l);
	}
	while(true){
		int l;
		fin >> l;
		if(l==-1) break;
		off.push_back(l);
	}
	map<int, set<string>> possible;
	possible[0] = set<string>{string(N,'1')};
	for(int i=0;i<C;i++){
		possible[i+1] = set<string>();
		for(string p : possible[i]){
			possible[i+1].insert(invert(p));
			possible[i+1].insert(invert_odd(p));
			possible[i+1].insert(invert_even(p));
			possible[i+1].insert(invert_mod3(p));
		}
	}
	bool written=false;
	for(string p : possible[C]){
		bool is_possible=true;
		for(int x : on){
			if(p[x-1] == '0'){
				is_possible=false;
				break;
			}
		}
		for(int x : off){
			if(p[x-1] == '1'){
				is_possible=false;
				break;
			}
		}
		if(!is_possible) continue;
		written=true;
		fout << p << endl;
	}
	if(!written) fout << "IMPOSSIBLE" << endl;
}