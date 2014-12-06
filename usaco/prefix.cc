/*
ID: holger1
PROG: prefix
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

bool prefix(string a, string b, int start){
	return mismatch(a.begin(), a.end(), b.begin()+start).first == a.end();
	for(int i=0; i<a.length(); i++)
		if(a[i] != b[start+i]) return false;
	return true;
}

int main(){
	ifstream fin("prefix.in");
	ofstream fout("prefix.out");
	vector<string> prefixes;
	string S="";
	while(true){
		string p;
		fin >> p;
		if(p == ".") break;
		prefixes.push_back(p);
	}
	while(true){
		string part;
		fin >> part;
		if(part == "") break;
		S+=part;
	}
	int L[200001] = {0};
	int sum[200001] = {0};
	int m=S.length();
	for(int i=1;i<=m;i++){
		sum[i] = sum[i-1]+int(S[i-1]); 
	}
	int prefix_sum[201] = {0};
	int prefix_sum2[201] = {0};
	for(int i=0; i<prefixes.size();i++){
		for(char p : prefixes[i]){
			prefix_sum[i] += int(p);
			prefix_sum2[i] += int(p);
		}
		prefix_sum2[i]-=prefixes[i][0];
	}
	for(int i=m-1;i>=0;i--){
		for(int j=0;j<prefixes.size();j++){
			string p=prefixes[j];
			int pl = p.length();
			if(pl+i <= m && prefix_sum[j] == sum[i+pl]-sum[i] && prefix_sum2[j] == sum[i+pl] - sum[i+1]){
				L[i] = max(L[i], pl+L[i+pl]);
			}
		}
	}
	fout << L[0] << endl;
}