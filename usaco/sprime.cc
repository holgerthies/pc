/*
ID: holger1
PROG: sprime
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <algorithm>

using namespace std;

bool is_prime(int x){
	if(x==2) return true;
	if(x % 2 == 0) return false;
	for(int i=3; i<int(pow(x,0.5))+1; i++){
		if(x%i==0) return false; 
	}
	return true;
}	

set<int> super_primes(int l){
	if(l==1){
		return set<int>{2,3,5,7};
	}
	set<int> result;
	for(int s : super_primes(l-1)){
		for(int i=1;i<10;i+=2){
			int p = 10*s+i;
			if(is_prime(p))
				result.insert(p);
		}
	}
	return result;
}


int main(){
	ifstream fin("sprime.in");
	ofstream fout("sprime.out");
	int N;
	fin >> N;
	for(int s : super_primes(N))
		fout << s << endl;
}