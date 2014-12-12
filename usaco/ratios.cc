/*
ID: holger1
PROG: ratios
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <stack>
#include <algorithm>
#include <limits>
#include <queue>

using namespace std;


void mul(const int lambda, const int vec[3], int ans[3]){
	ans[0] = lambda*vec[0];
	ans[1] = lambda*vec[1];
	ans[2] = lambda*vec[2];
}

int divide(const int a[3], const int b[3]){  
	if(a[0] == 0 && b[0] != 0)
		return -1;
	if(a[1] == 0 && b[1] != 0)
		return -1;
	if(a[2] == 0 && b[2] != 0)
		return -1;
	int l = 0;
	for(int i=0; i<3;i++){
		if(a[i] != 0 && b[i] % a[i] == 0)
			l = b[i] / a[i];
	}
	int prod[3];
	mul(l, a, prod);
	for(int i=0; i<3;i++){
		if(prod[i] != b[i])
			return -1;
	}
	return l;
}



void sum(const int a[3], const int b[3], int ans[3]){
	ans[0] = a[0]+b[0]; 
	ans[1] = a[1]+b[1];
	ans[2] = a[2]+b[2];
}

void sum3(const int a[3], const int b[3], const int c[3], int ans[3]){
	sum(a,b, ans);
	sum(ans, c, ans);
}

int main(){
	ifstream fin("ratios.in");
	ofstream fout("ratios.out");
	int goal[3];
	int m[3][3];
	for(int i=0; i<3;i++)
		fin >> goal[i];
	for(int i=0; i<3;i++)
		for(int j=0; j<3;j++)
			fin >> m[i][j];
	for(int sum=1;sum<300;sum++){
		for(int l1=0;l1<100;l1++){  
			for(int l2=max(0,sum-l1-99); l2<100;l2++){
				int l3=sum-l1-l2; 
				int v[3];
				int w1[3], w2[3], w3[3];
				mul(l1,m[0], w1);
				mul(l2,m[1], w2);
				mul(l3,m[2], w3);
				sum3(w1, w2,w3, v);
				int d = divide(goal, v);
				if(d != -1){
					fout << l1 << " " << l2 << " " << l3 << " " << d << endl; 
					return 0;
				}
			}
		}
	}
	fout << "NONE" << endl;
	return 0;
}