/*
ID: holger1
PROG: wormhole
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <bitset>
#include <stack>
#include <algorithm>

using namespace std;


vector<vector<pair<int,int>>> all_pairs(int n, int k, vector<bool> used){
	vector<vector<pair<int,int>>> result;
	if(k==n){ 
		result.push_back(vector<pair<int,int>>());
		return result;
	}
	if(used[k])
		return all_pairs(n,k+1, used);
	used[k] = true;
	for(int i=k+1; i<n; i++){
		if(!used[i]){
			used[i] = true;
			vector<vector<pair<int,int>>> subresult;
			 subresult = all_pairs(n, k+1, used);
			for(auto sv : subresult){
				sv.push_back(make_pair(k,i));
				result.push_back(sv);
			}
			used[i] = false;
		}
	}
	return result;
} 


int next(vector<pair<int,int>> pairing, int p1, vector<int> xs, vector<int> ys, int N){
	int min_x=-1;
	int min_ind=-1;
	for(int i=0; i<N;i++){
		if(ys[i] == ys[p1] && xs[i] > xs[p1]){
			if(min_x == -1 || xs[i] < min_x){ 
				min_x=xs[i];
				min_ind = i;
			}
		}	
	}
	return min_ind;
}

int beam(vector<pair<int,int>> pairing, int x){
	for(auto p : pairing){
		int v1=p.first;
		int v2=p.second;
		if(x == v1) return v2;
		if(x == v2) return v1;
	}
}

bool reachable(vector<pair<int,int>> pairing, int p1, int p2, vector<int> xs, vector<int> ys, int N){
	int curr=p1;
	vector<int> visited;
	visited.push_back(p1);
	int count=0;
	while(curr != -1 && count < 2*N){
		curr = next(pairing, curr, xs, ys, N);
		if(curr == -1) return false;
		//if(curr == p2) return true;
		curr = beam(pairing, curr);
		//visited.push_back(curr);
		if(curr == p2) return true;
		count++;

	}
	return false;
}

int main(){
	ifstream fin("wormhole.in");
	ofstream fout("wormhole.out");
	int N;
	fin >> N;
	vector<int> xs,ys;
	for(int i=0; i<N;i++){
		int y, x;
		fin >> x >> y;
		ys.push_back(y);
		xs.push_back(x);
	}
	vector<bool> used(N,false);
	auto pairs=all_pairs(N, 0, used);
	int count=0;
	for(auto pair : pairs){
		for(int i=0; i<N;i++){
			if(reachable(pair, i,i, xs,ys, N)){
				//cout << i << "VALID" << endl;
				count++;
				break;
			}
		}
	}
	fout << count << endl;
	
	return 0;
}