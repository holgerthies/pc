#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <limits>
#include <tuple>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iterator>
#include <string>
#include <fstream>
#define FOR(k,a,b) for(typeof(a) k=(a); k <= (b); ++k)
#define REP(k,a) for(int k=0; k < (a); ++k)
#define INF 2000000000
using namespace std;


void subtree_count(vector<vector<int>>& neighbors, int start, vector<bool>& visited, vector<unsigned long long>& ans, vector<int>& parent){
	visited[start] = true;
	ans[start] = 1; 
	for(int w : neighbors[start]){
		if(!visited[w]){
			parent[w] = start;
			subtree_count(neighbors, w, visited, ans, parent);
			ans[start] += ans[w];
		}
	}
}

int main(){
	int n;
	cin >> n;
	vector<vector<int>> neighbors(n+1, vector<int>());
	vector<unsigned long long> w(n-1,0);
	vector<pair<int,int>> edges(n-1);
	vector<unsigned long long> num_nodes(n-1, 0);
	for(int i=0; i<n-1; i++){
		int a,b;
		unsigned long long l;
		cin >> a >> b >> l;
		a--; b--;
		neighbors[a].push_back(b);
		neighbors[b].push_back(a);
		w[i] = l;
		edges[i] = make_pair(a,b);
	}
	vector<unsigned long long> sz(n,false); 
	vector<int> parent(n,false); 
	vector<bool> visited(n, false);
	vector<unsigned long long> weight(n-1, 0);

	subtree_count(neighbors, 0, visited, sz, parent);
	unsigned long long total_weight = 0;
	for(int i=0; i<n-1; i++){
		int a = edges[i].first, b=edges[i].second;
		if(parent[a] == b){
			num_nodes[i] = sz[a]*(n-sz[a]);
		}else{
			num_nodes[i] = sz[b]*(n-sz[b]);
		}
		weight[i] = num_nodes[i]*w[i];
		total_weight += weight[i];
	}
	//cout << total_weight<<endl;
	int q;
	cin >> q;
	for(int i=0; i<q;i++){
		int r;
		unsigned long long nw;
		cin >> r >> nw;
		r--;
		total_weight -= weight[r];
		weight[r] = num_nodes[r]*nw;
		total_weight += weight[r];
		//cout << total_weight<<endl;
		printf("%.9f\n", total_weight*(6.0/(double(n)*double(n-1))));
	}
	return 0;
}