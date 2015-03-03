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
#define REP(k,a) for(int k=0; k < (a); ++k)
#define REPP(k,a,b) for(int k= (a); k < (b); ++k)
#define INF 200000000
#define mp make_pair
#define len(s) (int)((s).size())
#define pb push_back
#define all(X) (X).begin(), (X).end()
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)

using namespace std;
typedef long long ll;
typedef unsigned int uint;
using vi = vector<int>;
using vii = vector<vector<int>>;
using pii = pair<int,int>;
template <class T>
void print(vector<T> v){ bool first=true; for(T x : v) { if(!first) cout << " "; first = false; cout << x; } cout << endl;}


bool is_removable(int i, map<pii,int>& M, map<int, pii>& Mi, vector<pii>& g, vi& indeg, vi& outdeg, map<int, bool>& removed){
	auto p = Mi[i];
	int x,y;
	tie(x,y) = p;
	bool tl = binary_search(all(g), mp(p.first-1, p.second+1)) && !removed[M[mp(p.first-1, p.second+1)]];
	bool t = binary_search(all(g), mp(p.first, p.second+1))  && !removed[M[mp(p.first, p.second+1)]];
	bool tr = binary_search(all(g), mp(p.first+1, p.second+1))  && !removed[M[mp(p.first+1, p.second+1)]];
	return (outdeg[i] == 0 || ((!tl || indeg[M[mp(x-1,y+1)]] > 1) && (!t || indeg[M[mp(x,y+1)]] > 1) && (!tr || indeg[M[mp(x+1,y+1)]] > 1)));
}

vector<pii> neighborst(pii& p){
	int x,y;
	tie(x,y) = p;
	vector<pii> ans = {mp(x-1,y+1), mp(x,y+1), mp(x+1,y+1)};
	return ans;
}
vector<pii> neighborsb(pii& p){
	int x,y;
	tie(x,y) = p;
	vector<pii> ans = {mp(x-1,y-1), mp(x,y-1), mp(x+1,y-1)};
	return ans;
}

int main(){
	DRI(m);
	map<pii, int> M;
	map<int, pii> Mi;
	map<int, bool> removed;
	vi indeg(m,0), outdeg(m,0);
	vector<pii> g;
	REP(i,m){
		DRII(x,y);
		M[mp(x,y)] = i;
		Mi[i] = mp(x,y);
		removed[i] = false;
		g.pb(mp(x,y));
	}
	sort(all(g));
	for(auto p : g){
		bool tl = binary_search(all(g), mp(p.first-1, p.second+1));
		bool t = binary_search(all(g), mp(p.first, p.second+1));
		bool tr = binary_search(all(g), mp(p.first+1, p.second+1));
		outdeg[M[p]] = tl+t+tr;
		if(tl) indeg[M[mp(p.first-1, p.second+1)]]++;  
		if(t) indeg[M[mp(p.first, p.second+1)]]++;  
		if(tr) indeg[M[mp(p.first+1, p.second+1)]]++;  
	}
	set<int> removable;
	REP(i,m){
		if(is_removable(i, M, Mi, g, indeg, outdeg, removed))
			removable.insert(i);
	}
	bool v=true;
	ll ans=0;
	const ll mod = 1e9+9;
	while(!removable.empty()){
		auto pos = v ? --removable.end() : removable.begin();  
		while(!is_removable(*pos, M, Mi, g, indeg, outdeg, removed)){
			removable.erase(pos);
			pos = v ? --removable.end() : removable.begin(); 
		}
		if(removable.empty()) break;
		auto r = Mi[*pos];
		ans *= m;
		ans %= mod;
		ans += *pos;
		ans %= mod;
		//cout<< *pos<<" ";
		removed[*pos] = true;
		for(auto p : neighborst(r)){
			if(binary_search(all(g), p)){
				indeg[M[p]]--;

			}
		}  
		for(auto p : neighborsb(r)){
			if(binary_search(all(g), p)){
				outdeg[M[p]]--;
				//cout << p.first << " "<< M[p] << " " << outdeg[M[p]] << endl;
				if(!removed[M[p]] && is_removable(M[p], M, Mi, g, indeg, outdeg, removed)){
					removable.insert(M[p]);
				}
			}
		}  
		removable.erase(pos);
		v = !v;
	}
	cout << ans << endl;
	return 0;
}