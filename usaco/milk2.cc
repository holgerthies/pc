/*
ID: holger1
PROG: milk2
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <set>
using namespace std;

int main(){
	ifstream fin("milk2.in");
	ofstream fout("milk2.out");
	int n;
	fin >> n;
	multiset<pair<int,int>> interval;
	for(int i=0; i<n;i++){
		int start, end;
		fin >> start >> end;
		interval.insert(make_pair(start, end));
	}
	int curr_start = 0;
	int curr_end = 0;
	int longest=curr_end-curr_start;
	int longest_without=0;
	for(auto inter : interval){
		int start = inter.first;
		int end = inter.second;
		int intermission = 0;
		if(start > curr_end){
			curr_start = start;
			if(curr_end > 0)
				intermission = start-curr_end;
		}
		curr_end = max(end, curr_end);
		longest = max(curr_end-curr_start, longest);
		longest_without = max(intermission, longest_without);

	}
	fout << longest << " " << longest_without << endl; 
	return 0;
}