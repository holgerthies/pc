/*
ID: holger1
PROG: nuggets
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
#define MAXN 2000000000L
using namespace std;


int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a % b);
}

int gcd(set<int> l){
	int ans=*l.begin();
	for(int a : l){
		ans = gcd(ans, a);
	}
	return ans;
}

int main(){
	ifstream fin("nuggets.in");
	ofstream fout("nuggets.out");
	set<int> packages;
	int N;
	fin >> N;
	for(int i=0; i<N;i++){
		int p;
		fin >> p;
		packages.insert(p);
	} 
	if(gcd(packages) != 1){
		fout << 0 <<endl;
		return 0;
	}
	int m = *packages.begin();
	vector<int> curr;
	vector<int> next;
	set<int> all;
	bool constructible[1000000];
	for(int p : packages){
		curr.push_back(p);
		constructible[p] = true;
	//	all.insert(p);
	}
	int result=0;
	bool found=false;

	int count=0;
	while(!found){
		count++;
		for(int p : packages){
			for(int c: curr){
				if(c+p < MAXN){
					if(!constructible[c+p]){
						next.push_back(c+p);
						constructible[c+p] = true;
					}
		//			all.insert(c+p);
				}
			}
		}

		for(int n : curr){
			found = true;
			for(int i=1; i<m; i++){
				if(!constructible[n+i]){
					found = false;
					break;
				}
			}
			if(found){
				result = n-1;
				break;
			}
		}
		for(int n : next){
			found = true;
			for(int i=1; i<m; i++){
				if(!constructible[n+i]){
					found = false;
					break;
				}
			}
			if(found){
				result = n-1;
				break;
			}
		}
		
		curr = next;
	}
	for(int n=1;n<=result; n++){
		if(constructible[n]){
			found = true;
			for(int i=1; i<m; i++){
				if(!constructible[n+i]){
					found = false;
					break;
				}
			}
			if(found){
				result = n-1;
				break;
			}
		}
	}
	fout << result << endl;
	return 0;
}