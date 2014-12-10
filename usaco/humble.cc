/*
ID: holger1
PROG: humble
LANG: C++11
*/
#define INF 1000000L
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
using ll = long long ;
int main(){
	int K,N;
	ifstream fin("humble.in");
	ofstream fout("humble.out");
	fin >> K >> N;
	vector<int> numbers;
	set<ll> humble_numbers;
	unordered_set<ll> quick_check;
	set<ll> pre;
	for(int i=0;i<K;i++){
		int n;
		fin >> n;
		numbers.push_back(n);
		humble_numbers.insert(n);
		pre.insert(n);
		quick_check.insert(n);
	}
	while(true){
		set<ll> next;
		for(ll h : pre){
			if(humble_numbers.size() >= N && 2*h > *prev(humble_numbers.end())){
				break;
			}
			for(ll p : numbers){
				if(quick_check.find(p*h) != quick_check.end()) continue;
				if(humble_numbers.size() >= N && *prev(humble_numbers.end()) <= p*h){
					break;
				}
				humble_numbers.insert(p*h);
				quick_check.insert(p*h);
				if(humble_numbers.size() > N)
					humble_numbers.erase(--humble_numbers.end(),humble_numbers.end());
				if(humble_numbers.size() < N || p*h < *prev(humble_numbers.end()))
					next.insert(p*h);
			}
		}

		pre = next;
		if(pre.size()==0) break;
	}

	/*ll max=2;
	ll min=INF/2;
	while(humble_numbers.size() <= 2*N){
		max = 2*min;
		min = INF;
		//cout << max << endl;
		set<int> next = {};
		for(ll h : humble_numbers){
			//if(2*h > max) break;
			for(ll p : numbers){
				if(quick_check.find(p*h) != quick_check.end()) continue;
				if(p*h > 1 && p*h <= max){
					next.insert(p*h);
					min = std::min(min, p*h);
				} //else if(p*h <= min) continue;
				else {
					break;
				}
			}
		}
		quick_check.insert(next.begin(), next.end());
		int m = humble_numbers.size();
		humble_numbers.insert(next.begin(), next.end());
		//if(m == humble_numbers.size()) break;
	}*/
	fout << *next(humble_numbers.begin(), N-1)<<endl;
	return 0;
}