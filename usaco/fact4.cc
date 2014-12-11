/*
ID: holger1
PROG: fact4
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
	ifstream fin("fact4.in");
	ofstream fout("fact4.out");
	int N;
	fin >> N;
	int ans=1;
	int c5=0;
	int d=5;
	while(d < N){
		c5 += N/d;
		d *= 5;
	}
	for(int i=1;i<=N;i++){
		int n=i;
		while(n % 5 == 0){
			n /= 5;
		}
		while(n % 2 == 0 && c5>0){
			c5--;
			n /= 2;
		}
		ans *= n;
		ans %= 10;
	} 
	fout << ans << endl;
	return 0;
}