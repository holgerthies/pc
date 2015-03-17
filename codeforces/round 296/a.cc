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

int main(){
	DRIII(w, h, n);
	set<int> hcuts, vcuts;
	hcuts.insert(0);
	hcuts.insert(h);
	vcuts.insert(0);
	vcuts.insert(w);
	multiset<int> hdists, vdists;
	hdists.insert(h); vdists.insert(w);
	REP(i, n){
		char c;
		int x;
		cin >> c >> x;
		if(c == 'H'){
			hcuts.insert(x);
			auto pos=hcuts.find(x);
			--pos;
			int bf=*pos;
			++pos; ++pos;
			int af=*pos;
			auto old = hdists.find(af-bf);
			hdists.erase(old);
			hdists.insert(x-bf);
			hdists.insert(af-x);
		} else{
			vcuts.insert(x);
			auto pos=vcuts.find(x);
			--pos;
			int bf=*pos;
			++pos; ++pos;
			int af=*pos;
			auto old = vdists.find(af-bf);
			vdists.erase(old);
			vdists.insert(x-bf);
			vdists.insert(af-x);
		}
		auto vend = vdists.end();
		vend--;
		//cout << *vend << endl;
		auto hend = hdists.end();
		//cout << *hend << endl;
		hend--;
		ll ans = ll(*hend)*ll(*vend);
		cout << ans << endl;
	}
	return 0;
}