/*
ID: holger1
PROG: concom
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
	ifstream fin("concom.in");
	ofstream fout("concom.out");
	int n;
	fin>>n;
	int owns[101][101]={0};
	for(int i=0; i<n;i++){
		int a,b,x;
		fin >> a >>b >> x;
		owns[a][b] = x;
	}

	bool controls[101][101] = {false};
	n=101;
	for(int i=0;i<n;i++){
		controls[i][i] = true;
	}
	
	for(int m=0;m<n;m++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				int s=0;
				for(int k=0;k<n;k++){
					if(controls[i][k]){
						s += owns[k][j];
					}
				}
				if(s > 50)
					controls[i][j] = true;
			}
		}
	}
	for(int i=0; i<n;i++){
		for(int j=0;j<n;j++){
			if(i != j && controls[i][j])
				fout << i <<" " << j << endl;
		}
	}
}