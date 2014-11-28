/*
ID: holger1
PROG: palsquare
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

string convert(int n, int B){
	map<int, char> digits;
	for(int i=0; i<20;i++){
		if(i < 10)
			digits[i] = '0'+i;
		else
			digits[i] = 'A'+i-10;
	}
	string out;
	while(n > 0){
		out = digits[(n % B)]+out;
		n /= B;
	}
	return out;
}

bool palindrome(string s){
	int n= s.length();
	for(int i=0; i<n; i++){
		if(s[i] != s[n-i-1])
			return false;
	}
	return true;
}

int main(){
	ifstream fin("palsquare.in");
	ofstream fout("palsquare.out");
	int B;
	fin >> B;
	for(int i=1;i<=300; i++){
		int s=i*i;
		string ib = convert(i,B);
		string i2b = convert(i*i,B);
		if(palindrome(i2b))
			fout << ib << " " << i2b << endl;
	}
	return 0;
}