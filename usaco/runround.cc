/*
ID: holger1
PROG: runround
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
#include <sstream>
#include <queue> 

using namespace std;
using ll = unsigned long long;
set<ll> unique_numbers(int d, int len){
	if(len > d) return set<ll>();
	if(len==1){
		set<ll> ans;
		for(int i=1;i<=d;i++){
			ans.insert(i);
		}
		return ans;
	}

	set<ll> ans = unique_numbers(d-1, len);
	for(ll x : unique_numbers(d-1, len-1)){
		ans.insert(10*x+d);
	}
	return ans;
}
int length(ll x){
	int ans=0;
	while(x > 0){
		x /= 10;
		ans++;
	}
	return ans;
}
int digit_at(ll x, int p){
	for(int i=0;i<p;i++){
		x /= 10;
	}
	return x % 10;
}
bool is_runaround(ll x){
	set<int> visited;
	int l = length(x);
	int pos=0;
	while(visited.find(pos) == visited.end()){
		visited.insert(pos);
		pos = pos+digit_at(x,l-1-pos);
		//pos += 2*l;
		pos %= l;
		if(visited.find(pos) != visited.end() && pos != 0){
			return false;
		}
	}
	return visited.size() == l;
}

vector<int> get_digits(ll x){
	vector<int> ans;
	while(x > 0){
		ans.push_back(x %10);
		x /= 10;
	}
	return ans;
}

ll make_number(vector<int> digits){
	ll ans=0;
	for(int d : digits){
		ans = ans*10+d;
	}
	return ans;
}

int main(){
	ifstream fin("runround.in");
	ofstream fout("runround.out");
	int M;
	fin >> M;
	int l=length(M);
	//return 0;
	set<ll> results;
	for(int i=l;i<=9;i++){
		for(ll x : unique_numbers(9,i)){
			ostringstream convert;
			convert << x;
			string digits=convert.str();
			sort(digits.begin(), digits.end());
			//digits=get_digits(x);
			do{
				x = stoll(digits);//;make_number(digits);
				if(x>M && is_runaround(x)){
					results.insert(x);
				} 
			} while(next_permutation(digits.begin(), digits.end()));
		}
		if(results.size()){ 
			fout << *results.begin()<<endl;
			return 0;
		}
	}
}