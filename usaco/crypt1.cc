/*
ID: holger1
PROG: crypt1
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
vector<int> combinations(vector<int> d, int k){
	vector<int> result;
	if(k==0){
		result.push_back(0);
		return result;
	}
	for(auto last : d){
		auto s2 = combinations(d, k-1);
		for(auto rest : s2){
			result.push_back(10*rest+last);
		}
	} 
	return result;
}

bool contains_other(int n, vector<int> digits){
	while(n > 0){
		int d = n%10;
		if(find(digits.begin(), digits.end(), d) == digits.end())
			return true;
		n /= 10;
	}
	return false;
}

bool valid(int n1, int n2, vector<int> d){
	int r1 = (n2%10)*n1;
	int r2 = (n2/10)*n1;
	int r3 = n1*n2;
	if(r1 >= 1000 || r2 >= 1000 || r3 >= 10000) return false;
	return !(contains_other(r1,d) || contains_other(r2,d) || contains_other(r3,d));
}
int main(){
	ifstream fin("crypt1.in");
	ofstream fout("crypt1.out");
	int n;
	fin >> n;
	vector<int> valid_digits;
	for(int i=0; i<n; i++){
		int v;
		fin >> v;
		valid_digits.push_back(v);
	}
	int result=0;
	vector<int> two_digits = combinations(valid_digits, 2);
	vector<int> three_digits = combinations(valid_digits, 3);
	for(auto n1 : three_digits){
		for(auto n2 : two_digits){
			if(valid(n1,n2, valid_digits)){ 
				result++;
			}
		}
	}
	fout << result << endl;
	return 0;
}