/*
ID: holger1
PROG: namenum
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

long long make_numeric(string name){
	map<char, long> conversion;
	for(long long i=0; i<25; i++){
		if('A'+i < 'Q')
			conversion['A'+i] = i/3+2;
		if('A'+i > 'Q')
			conversion['A'+i] = (i-1)/3+2;
	}
	long long p=1;
	long long result=0;
	for(auto it = name.end()-1; it >= name.begin(); it--){
		char s = *it;
		if(s=='Q' || s=='Z') return -1;
		result += p*conversion[s];
		p *= 10;
	}
	return result;
}

int main(){
	ifstream fin("namenum.in");
	ifstream dict("dict.txt");
	ofstream fout("namenum.out");
	long long id;
	fin >> id;
	bool empty=true;
	while(dict.good()){
		string name;
		dict >> name;
		long long num=make_numeric(name);
		if(num == id){
			empty = false;
			fout << name << endl;
		}
	}
	if(empty)
		fout << "NONE" << endl;
	return 0;
}