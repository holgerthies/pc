/*
ID: holger1
PROG: spin
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

struct interval{
	int a;
	int b;
	bool empty;
};

interval unite(interval x, interval y){
	interval ans;
	ans.empty = false;
	if(x.empty && y.empty){
		ans.empty = true;
		return ans;
	}
	if(x.empty){
		ans.a = y.a;
		ans.b = y.b;
		return ans;
	}
	if(y.empty){
		ans.a = x.a;
		ans.b = x.b;
		return ans;
	}
	ans.a = min(x.a,y.a);
	ans.b = max(y.a,y.b);
	if(x.b == 359)
		ans.a = x.a;
	return ans;
}
bool intersects(int x1, int x2, int y1, int y2){
	if(x2 < x1) x2+=360;
	if(y2 < y1) y2+=360;
	return (y1 >= x1 && y1 <= x2 || x1 >= y1 && x1<=y2 );

}
interval intersect(int x1, int x2, int y1, int y2){
	if(x2 < x1)
		return unite(intersect(x1,359, y1, y2), intersect(0,x2,y1,y2));
	if(y2 < y1)
		return unite(intersect(x1,x2,y1,359), intersect(x1,x2,0,y2));
	interval ans;
	ans.empty = false;
	if(!intersects(x1, x2, y1,y2)){
		//cout << ":::::" << x1 << " "<<x2<<" "<<y1<<" "<<y2<<endl;
		ans.empty = true;
	}
	ans.a = max(x1,y1);
	ans.b = min(x2,y2);

	return ans;
}

bool aligned(int wp[5], int start[5][5], int extend[5][5], int nwedges[5], int curr, int intersection_start, int intersection_end){
	if(curr >= 5)
		return true;
	//cout << curr << " "<<intersection_start << ","<<intersection_end<<endl;
	for(int i=0; i<nwedges[curr]; i++){
		int from = (wp[curr]+start[curr][i])% 360;
		int to = (from+extend[curr][i]) % 360;
		//cout << curr << " " << from << ", "<<to<<endl;
		interval intersection = intersect(intersection_start, intersection_end, from, to);
		if(!intersection.empty){
			bool s = aligned(wp, start, extend, nwedges, curr+1, intersection.a, intersection.b);
			if(s) return true;
		}
	}
	return false;
}

int ggt(int a, int b){
	if(b == 0) return a;
	return ggt(b, a % b);
}


int main(){
	ifstream fin("spin.in");
	ofstream fout("spin.out");
	int wp[5];
	int nwedges[5];
	int speed[5];
	int start[5][5];
	int extent[5][5];
	for(int i=0; i<5;i++){
		wp[i] = 0;
		fin >> speed[i];
		fin >> nwedges[i];
		for(int w=0; w<nwedges[i]; w++){
			fin >> start[i][w] >> extent[i][w];
			/*extent[i][w] = extent[i][w] - start[i][w];
			if(extent[i][w] < 0){
				extent[i][w] += 360; 
			}*/
		}
	}

	for(int i=0;i<360;i++){
		//for(int i=0; i<5;i++) cout << wp[i] << " ";
		if(aligned(wp, start, extent, nwedges, 0, 0, 360)){
			fout << i << endl;
			return 0;
		}
		for(int k=0;k<5;k++){
			wp[k] += speed[k];
			wp[k] %= 360;
		}
	}
	fout << "none" << endl;
	return 0;
}