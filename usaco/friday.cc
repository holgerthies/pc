/*
ID: holger1
PROG: friday
LANG: C++11
*/
#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ofstream fout("friday.out");
	ifstream fin("friday.in");
	int n;
	fin >> n; 
	int day=14; // first friday
	int days[7]={};
	for(int i=0; i<n; i++){
		for(int m=1;m<=12;m++){
			day %= 7;
			days[day] += 1;
			if(m == 4 || m==6 || m==9 || m==11)
				day += 30;
			else if(m==2){
				if(i%4 == 0 && (i%100 != 0 || (1900+i)%400 == 0))
					day += 29;
				else
					day += 28;
			}
			else{
				day += 31;
			}
		}
	}
	fout << days[0];
	for(int i=1; i<7; i++)
		fout << " " << days[i];
	fout << endl;
	return 0;
}