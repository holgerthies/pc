/*
ID: holger1
PROG: fracdec
LANG: C++11
*/
#define INF 10000000
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

int main(){
	ifstream fin("fracdec.in");
	ofstream fout("fracdec.out");
	int N,D;
	fin >> N >> D;
	string result=to_string(N/D)+".";
	int b = result.length();
	N %= D;
	if(N==0){
		result += "0";
	}
	int p = 0;
	unordered_set<int> visited;
	map<int, int> pos;
	while(N != 0){
		int c=0;
		visited.insert(N);
		p += 1;
		while(N < D){
			N *= 10;
			if(c > 0){
				result += "0";
				p += 1;
			}
			c += 1;
			
		}
		
		int add = N/D;
		N %= D;
		result += to_string(add);
		if(visited.find(N) != visited.end()){
			int removed=0;
			while(result[pos[N]+b-1-removed] == result[result.length()-1])
			{
				removed++;
				result = result.substr(0, result.length()-1);
			}
			result.insert(pos[N]+b-removed, "(");
			result += ")";
			break;
		}
		
		if(N == 0) break;
		pos[N] = p;
		
	}
	for(int i=76;i<result.length(); i+=77)
		result.insert(i, "\n");
	fout << result<<endl;
	return 0;
}