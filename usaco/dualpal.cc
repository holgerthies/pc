/*
ID: holger1
PROG: dualpal
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
	ifstream fin("dualpal.in");
	ofstream fout("dualpal.out");
	int N,S;
	fin >> N >> S;
	int found=0;
	while(found < N){
		S++;
		int count=0;
		for(int b=2; b<=10;b++){
			string sb = convert(S,b);
			if(palindrome(sb)) count++;
			if(count == 2){
				fout << S << endl;
				found += 1;
				break;
			}

		}
	}
	return 0;
}