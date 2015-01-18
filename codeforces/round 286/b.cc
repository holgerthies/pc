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
#define len(s) (int)((s).size())
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned int uint;
using vi = vector<int>;
using vii = vector<vector<int>>;
using pii = pair<int,int>;

int main(){
	int n,m;
	cin >> n >> m;
	vector<vector<pii>> adj(n+1, vector<pii>());
	for(int i=0; i<m;i++){
		int v,w, c;
		cin >> v >> w >>c;
		adj[v].pb({w,c});
		adj[w].pb({v,c});
	} 
	int qu;
	cin >> qu;
	for(int i=0; i<qu;i++){
		int u,v;
		cin >> u >> v;
		int count=0;
		vector<bool> color_visited(m+1, false);
		for(auto p : adj[u]){
			int color=p.second;
			if(color_visited[color]) continue;
			queue<pair<int,int>> q;
			q.push(p);
			vi visited(n+1, false);
			visited[p.first] = true;
			visited[u] = true;
			while(!q.empty()){
				auto vp = q.front();
				q.pop();
				if(vp.first == v){
					count++;
					color_visited[color] = true;
					break;
				}
				for(auto x : adj[vp.first]){
					if(!visited[x.first] && x.second == color){
						visited[x.first] = true;
						q.push(x);
					}
				}
			}
		}
		cout << count << endl;
	}
	return 0;
}