/*
ID: holger1
PROG: frac1
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
#include <queue> 

using namespace std;

int main(){
	ifstream fin("frac1.in");
	ofstream fout("frac1.out");
	int N;
	fin >> N;
	int x0=0,y0=1,x1=1,y1=N;
	int count=0;
	while(x0 <= N){
		fout << x0 <<"/" << y0 << endl;
		int k=(N+y0)/y1;
		int c0 = k*x1-x0;
		int c1 = k*y1-y0;
		x0 = x1;
		y0 = y1;
		x1 = c0;
		y1 = c1;
	}
}