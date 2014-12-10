/*
ID: holger1
PROG: contact
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

struct cmp {
	bool operator() (const string& a, const string& b) {
		if(a.length() == b.length())
			return a < b;
		return a.length() < b.length();
	}
};
int main(){
	ifstream fin("contact.in");
	ofstream fout("contact.out");
	int A,B,N;
	fin >> A >> B >> N;
	string seq;
	string in;
	while(fin >> in)
		seq += in;
	map<string,int> count;
	for(int l=A;l<=B;l++){
		if(l > seq.length()) break;
		for(int s=0;s<=seq.length()-l;s++){
			count[seq.substr(s, l)]++;
		}
	}
	
	map<int, set<string, cmp>> freq;
	for(auto& p : count){
		freq[-p.second].insert(p.first);
	}
	int c=0;
	for(auto& p : freq){
		if(p.second.size() > 0){
			int n=0;
			fout << -p.first << endl;
			bool first = true;
			for(string s : p.second){
				if(!first)
					fout << " ";
				first=false;
				fout << s;
				n++;
				if(n % 6 == 0 && n != p.second.size()){
					fout << endl;
					first = true;
				}
			}
			fout << endl;
			c++;
			if(c == N)
				break;
		}
	}
	return 0;
}