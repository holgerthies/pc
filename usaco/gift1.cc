/*
ID: holger1
PROG: gift1
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

int main(){
	ofstream fout("gift1.out");
	ifstream fin("gift1.in");
	int np;
	fin >> np;
	string* names = new string[np];
	int* money = new int[np];
	map<string,int> ids;
	for(int i=0; i<np;i++){
		fin >> names[i];
		ids[names[i]] = i;
		money[i] = 0;
	}
	for(int j=0; j<np; j++){
		string name;
		fin >> name;
		int i=ids[name];
		int initial_money, receivers;
		fin >> initial_money >> receivers;
		int giving=0;
		if(receivers > 0)
			giving = initial_money/receivers;
		for(int r=0; r<receivers; r++){
			string receiver;
			fin >> receiver;
			money[i] -= giving;
			money[ids[receiver]] += giving;
		}
	}
	for(int i=0;i<np;i++){
		fout << names[i] << " " << money[i] << endl;
	}
	return 0;
}
