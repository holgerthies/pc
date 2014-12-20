/*
ID: holger1
PROG: job
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
#define INF 10000000
#define MAXN 1000
#define MAXM 30
#define MAXT 20

using namespace std;


int main(){
	ifstream fin("job.in");
	ofstream fout("job.out");
	int N, M1, M2;
	fin >> N >> M1 >> M2;
	vector<int> atime(M1);
	vector<int> btime(M2);
	for(int i=0; i<M1; i++)
		fin >> atime[i];
	for(int i=0; i<M2; i++)
		fin >> btime[i];
	sort(atime.begin(), atime.end());
	sort(btime.begin(), btime.end());
	vector<pair<int,int>> atot;
	vector<pair<int,int>> btot;
	
	for(int i=0; i<atime.size(); i++){
		atot.push_back(make_pair(atime[i], i));
	}
	for(int i=0; i<btime.size(); i++){
		btot.push_back(make_pair(btime[i], i));
	}

	unsigned int tot_time = 2*N*MAXT;
	vector<int> at_b(N, 0);
	vector<int> at_c(N, 0);
	for(int n=0; n<N; n++){
		int min_time = atot[0].first;
		int min_index = atot[0].second;
		at_b[n] = min_time;
		atot[0].first += atime[min_index];
		sort(atot.begin(), atot.end());
	}
	for(int n=0; n<N; n++){
		int min_time = btot[0].first;
		int min_index = btot[0].second;
		at_c[n] = min_time;
		btot[0].first += btime[min_index];
		sort(btot.begin(), btot.end());
	}

	int t=0;
	for(int n=0;n<N;n++){
		t=max(t, at_c[N-n-1]+at_b[n]);
	}
	fout << *max_element(at_b.begin(), at_b.end()) << " " << t  << endl;
	return 0;
}