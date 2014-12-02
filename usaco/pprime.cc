/*
ID: holger1
PROG: pprime
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

int reverse(int x){
	int res = 0;
	while(x > 0){
		res *= 10;
		res += (x % 10);
		x /= 10;
	}
	return res;
}

int length(int x){
	int res = 0;
	while(x > 0){
		res += 1;
		x /= 10;
	}
	return res;
}

set<int> palin(int length){
	set<int> result;
	int rep=length/2;
	int base=pow(10,rep);
	for(int i=pow(10,rep-1);i<pow(10,rep); i++){
		if(length % 2 == 0)
			result.insert(i*base+reverse(i));
		else
			for(int d=0;d<10;d++){
				result.insert(i*10*base+d*base+reverse(i));
			}
	}
	return result;
}

bool is_prime(int x){
	if(x==2) return true;
	if(x % 2 == 0) return false;
	for(int i=3; i<int(pow(x,0.5))+1; i++){
		if(x%i==0) return false; 
	}
	return true;
}	

int main(){
	ifstream fin("pprime.in");
	ofstream fout("pprime.out");
	int a,b;
	fin >> a >> b;
	int minl = length(a);
	int maxl = length(b);
	for(int l = minl; l<=maxl; l++){
		for(int p : palin(l)){
			if(p >= a && p <= b && is_prime(p)){
				fout << p << endl;
			}
		}
	}
}