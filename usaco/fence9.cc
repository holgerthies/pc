/*
ID: holger1
PROG: fence9
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


int cross_product(int x1, int x2, int y1, int y2){
	return x1*y2-x2*y1;
}

double length(int x, int y){
	return sqrt(double(x*x+y*y));
}

bool on_line(int a1, int a2, int b1, int b2, int p1, int p2){
	return cross_product(p1-a1, p2-a2, b1-a1, b2-a2) == 0 
	&& abs(length(b1-a1,b2-a2)-(length(p1-a1, p2-a2) + length(b1-p1, b2-p2))) < 0.1;
}

int main(){
	ifstream fin("fence9.in");
	ofstream fout("fence9.out");
	int n,m,p;
	fin >> n >> m >> p;
	int cnt=0;
	int area = 0.5*p*m;
	//cout << area <<endl;
	//area+1-b/2 = i
	//set<pair<int,int>> e;
	for(int x=0; x<=max(n,p);x++){
		
		int y1;
		if(n==0)
			y1=-100;
		else
			y1 = x*(double(m)/n);
		int y2;
		if(p==n)
			y2=-100;
		else
			y2 = m-(x-n)*double(m)/double(p-n);
		for(int i=-3; i<=3; i++){
			if(n > 0 && on_line(0,0,n,m,x,y1+i) && y1+i>0){
				cnt++;
				//e.insert(make_pair(x,y1+i));
			}
			if(p!=n && on_line(n,m,p,0,x,y2+i) && y2+i>0){
				cnt++;
				//e.insert(make_pair(x,y2+i));

			}
		}

	}
	cnt += p;
	if(n==0||p==n)
		cnt += m;
	/*int cnt2=0;
	for(int x=0;x<=max(n,p);x++){
		for(int y=0;y<=m;y++){
			if(on_line(0,0,n,m,x,y) || on_line(0,0,p,0,x,y) || on_line(n,m,p,0,x,y)){
				if(e.find(make_pair(x,y)) == e.end()){
					cout << x<<","<<y<<endl;
				}
				cnt2++;
			}
		}
	}
	cout<<cnt2<<","<<cnt<<endl;*/
	fout << area+1-cnt/2 << endl;
	return 0;
}