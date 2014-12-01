/*
ID: holger1
PROG: ariprog
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

int main(){
	ifstream fin("ariprog.in");
	ofstream fout("ariprog.out");
	int N,M;
	fin >> N >> M;
	int maxbs = 0;
	bool is_bisquare[150001] = {false};
	for(int p=0; p<=M; p++){
		for(int q=0; q<=M; q++){
			int bs=p*p+q*q;
			is_bisquare[bs] = true;
			maxbs = max(maxbs, bs);
		}
	}

	bool exists=false;
	for(int b=1; b<maxbs/(N-1)+1;b++){
		for(int a=0;a<=maxbs;a++){
			if(a+(N-1)*b > maxbs) break;
			if(!is_bisquare[a] || !is_bisquare[a+(N-1)*b]) continue;
			bool ok=true;
			for(int n=1;n<N;n++){
				//cout << a+n*b << "," << *bisquares.find(a+n*b)<<endl;
				if(!is_bisquare[a+n*b]){
					//cout << a <<"," << n << "," << b << endl;
					ok=false;
					break;
				}
			}
			if(ok){ 
				exists=true;
				fout << a << " " << b << endl;
			}
		}
	}
	if(!exists)
		fout << "NONE"<<endl;

}