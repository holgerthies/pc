/*
ID: holger1
PROG: combo
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <unordered_set>
#include <algorithm>
using namespace std;

unordered_set<int> get_combinations(int c1, int c2, int c3, int N){
	unordered_set<int> result;
	for(int e1=-2; e1<3; e1++){
		for(int e2=-2; e2<3; e2++){
			for(int e3=-2; e3<3; e3++){
				int v= 100*((c1+N+e1)%N)+10*((c2+N+e2)%N)+((c3+N+e3)%N);
				result.insert(v);
			}
		}
	}
	return result;
} 
int main(){
	ifstream fin("combo.in");
	ofstream fout("combo.out");
	int N;
	fin >> N;
	int f1,f2,f3,m1,m2,m3;
	fin >> f1 >> f2 >> f3 >> m1 >> m2 >> m3;
	auto s1 = get_combinations(f1,f2,f3,N);
	auto s2 = get_combinations(m1,m2,m3,N);
	s1.insert(s2.begin(), s2.end());
	fout << s1.size() << endl;
}