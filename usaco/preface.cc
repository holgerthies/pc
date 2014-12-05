/*
ID: holger1
PROG: preface
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
	ifstream fin("preface.in");
	ofstream fout("preface.out");
	int N;
	fin >> N;
	string num[3501];
	num[0]="";
	int count[3501][7];
	int sum[7] = {0};
	for(int n=1;n<=N;n++){
		if(n >= 1000){
			num[n]="M"+num[n-1000];
			for(int i=0; i<7;i++){
				count[n][i] = count[n-1000][i];
			}
			count[n][6] += 1;
		}
		else if(n>=900){
			num[n] ="CM"+num[n-900];
			for(int i=0; i<7;i++){
				count[n][i] = count[n-900][i];
			}
			count[n][6] += 1;
			count[n][4] += 1;
		}
		else if(n >= 500){
			num[n]="D"+num[n-500];
			for(int i=0; i<7;i++){
				count[n][i] = count[n-500][i];
			}
			count[n][5] += 1;
		}
		else if(n >= 400){
			num[n]="CD"+num[n-400];
			for(int i=0; i<7;i++){
				count[n][i] = count[n-400][i];
			}
			count[n][5] += 1;
			count[n][4] += 1;
		}
		else if(n >= 100){
			num[n]="C"+num[n-100];
			for(int i=0; i<7;i++){
				count[n][i] = count[n-100][i];
			}
			count[n][4] += 1;
		}
		else if(n >= 90){ 
			num[n]="XC"+num[n-90];
			for(int i=0; i<7;i++){
				count[n][i] = count[n-90][i];
			}
			count[n][4] += 1;
			count[n][2] += 1;
		}
		else if(n >= 50){ 
			num[n]="L"+num[n-50];
			for(int i=0; i<7;i++){
				count[n][i] = count[n-50][i];
			}
			count[n][3] += 1;
		}
		else if(n >= 40){
			num[n]="XL"+num[n-40];
			for(int i=0; i<7;i++){
				count[n][i] = count[n-40][i];
			}
			count[n][3] += 1;
			count[n][2] += 1;
		}
		else if(n >= 10){ 
			num[n]="X"+num[n-10];
			for(int i=0; i<7;i++){
				count[n][i] = count[n-10][i];
			}
			count[n][2] += 1;
		}
		else if(n >= 9){
			num[n]="IX"+num[n-9];
			for(int i=0; i<7;i++){
				count[n][i] = count[n-9][i];
			}
			count[n][2] += 1;
			count[n][0] += 1;
		}
		else if(n >= 5) {
			num[n]="V"+num[n-5];
			for(int i=0; i<7;i++){
				count[n][i] = count[n-5][i];
			}
			count[n][1] += 1;
		}
		else if(n >= 4){
			num[n]="IV"+num[n-4];
			for(int i=0; i<7;i++){
				count[n][i] = count[n-4][i];
			}
			count[n][1] += 1;
			count[n][0] += 1;
		}
		else if(n >= 1){
			num[n]="I"+num[n-1];
			for(int i=0; i<7;i++){
				count[n][i] = count[n-1][i];
			}
			count[n][0] += 1;
		}
		for(int i=0; i<7;i++){
			sum[i] += count[n][i];
		}
	}
	map<int,char> names={{0,'I'}, {1,'V'}, {2, 'X'}, {3,'L'}, {4,'C'}, {5, 'D'}, {6, 'M'}};
	for(int i=0;i<7;i++){
		if(sum[i] > 0)
			fout << names[i] << " " << sum[i]<<endl;
	}

}