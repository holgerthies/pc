/*
ID: holger1
PROG: tour
LANG: C++11
*/
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
#define INF 200000000
#define mp make_pair
#define pb push_back
#define len(s) (int)((s).size())
using namespace std;
typedef long long ll;
typedef unsigned int uint;
using vi = vector<int>;
using vii = vector<vector<int>>;
using pii = pair<int,int>;

vector<vector<bool>> visited(101, vector<bool>(101,false));

vector<pii> nbs(pii p, vii& adj){
	int n=adj.size();
	vector<pii> ans;

		for(int n1 : adj[p.first]){
			if(n1 > p.second || n1 == n-1){
				ans.pb({n1,p.second});
			}
		}		
		for(int n2 : adj[p.second]){
			if(n2 > p.first || n2 == n-1){
				ans.pb({p.first, n2});
			}
		}		
	return ans;	
}


void topsort(vii& adj, int i, int j, vector<pii>& ans){
	int n=adj.size();
	visited[i][j] = true;
	for(auto p : nbs({i,j}, adj)){
		int n1,n2;
		tie(n1,n2) = p;
		if(!visited[n1][n2] && (n1 !=n2 || n1 == n-1))
			topsort(adj, n1,n2, ans);
	}

	ans.pb({i,j});
}



int main(){
	ifstream fin("tour.in");
	ofstream fout("tour.out");
	int n,m;
	fin >> n >> m;
	map<string, int> ids;
	REP(i,n){
		string name;
		fin >> name;
		ids[name] = i;
	}
	vii adj(n, vi());
	REP(i,m){
		string s1, s2;
		fin >> s1 >> s2;
		int id1 = ids[s1], id2=ids[s2];
		adj[min(id1, id2)].pb(max(id1,id2));
	}
	vii max_dist(n+1, vi(n+1,0));
	max_dist[n-1][n-1] = 1;
	vector<pii> nodes;
	topsort(adj, 0,0, nodes);
	reverse(nodes.begin(), nodes.end());
	for(auto p : nodes){
		int i,j;
		tie(i,j) = p;
		// cout<<"curr " << i<<" "<<j<<endl;

		for(auto nb : nbs(p,adj)){
			int n1,n2;
			tie(n1,n2) = nb;
			if(n1 == n2  && n1 != n-1) continue;
			// cout << n1<<" "<<n2<<endl;
			if(n1 != n2 && n1 != i && n2 != j){
				max_dist[n1][n2] = max(max_dist[n1][n2], max_dist[i][j]+2);
			} else {
				max_dist[n1][n2] = max(max_dist[n1][n2], max_dist[i][j]+1);

			}
		}
	}
	fout << max_dist[n-1][n-1] << endl;
	return 0;
}