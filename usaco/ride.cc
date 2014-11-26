/*
ID: holger1
PROG: ride
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main(){
	ofstream fout("ride.out");
	ifstream fin("ride.in");
	string l1, l2;
	fin >> l1 >> l2;
	int n1 = 1;
	int n2 = 1;
	for(char c : l1){
		n1 *= int(c)-64;
		n1 %= 47;
	}
	for(char c : l2){
		n2 *= int(c)-64;
		n2 %= 47;
	}
	if(n1 == n2)
		fout << "GO" << endl;
	else	
		fout << "STAY" << endl;
	return 0;
}