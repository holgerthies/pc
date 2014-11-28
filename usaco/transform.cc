/*
ID: holger1
PROG: transform
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

pair<int,int> rotate(int n, int y, int x, int num){
	int y_rot = x;
	int x_rot = n-y;
	if(num == 1)
		return make_pair(y_rot, x_rot);
	return rotate(n, y_rot, x_rot, num-1);
}  

pair<int,int> reflect(int n, int y, int x){
	return make_pair(y, n-x);
}

pair<int,int> action(int id, int n, int y, int x){
	if(id < 4){
		return rotate(n, y,x,id);
	}
	else if(id == 4)
		return reflect(n, y,x);
	else if(id < 8){
		pair<int,int> ref = reflect(n, y,x);
		return rotate(n, ref.first, ref.second, id-4);
	}
	else 
		return make_pair(y,x);
}

int main(){
	ifstream fin("transform.in");
	ofstream fout("transform.out");
	int n;
	fin >> n;
	vector<char*> first;
	vector<char*> snd;
	for(int i=0; i<n; i++){
		char* line = new char[n];
		fin >> line;
		first.push_back(line);
	}
	for(int i=0; i<n; i++){
		char* line = new char[n];
		fin >> line;
		snd.push_back(line);
	}	
	bool valid;
	for(int id=1; id<9;id++){
		valid=true;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				auto transformed = action(id, n-1, i, j);
				if(first[transformed.first][transformed.second] != snd[i][j]){
					valid=false;
					break;
				}
				if(!valid) break;
			}
		}
		if(valid){
			if(id <= 4)
				fout << id << endl;
			else if(id <= 8)
				fout << 5 << endl;
			else
				fout << 6 << endl;
			break; 
		}
	}
	if(!valid)
			fout << 7 << endl;
	return 0;
}