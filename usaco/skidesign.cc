/*
ID: holger1
PROG: skidesign
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

using namespace std;

int main(){
	ifstream fin("skidesign.in");
	ofstream fout("skidesign.out");
	vector<int> heights;
	int N;
	fin >> N;
	for(int i=0;i<N;i++){
		int h;
		fin >> h;
		heights.push_back(h);
	}
	int min_cost = numeric_limits<int>::max();
	int max_height = *max_element(heights.begin(), heights.end());
	for(int d=0; d<=max_height;d++){
		int cost=0;
		for(int h : heights){
			if(h<d-17){
				cost += (d-17-h)*(d-17-h);
			}
			if(h>d){
				cost += (d-h)*(d-h);
			}
		}
		min_cost = min(cost, min_cost);
	}
	
	fout << min_cost << endl;
	return 0;
}