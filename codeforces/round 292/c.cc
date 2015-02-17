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
	int n;
	cin >> n;
	string x;
	cin >> x;
	vii f = {{2}, {3}, {2,2}, {5}, {2,3}, {7}, {2,2,2}, {3,3}};
	vii ff(9);
	REP(i, len(f)){
		ff[i] = f[i];
		if(i > 0){
			for(int k : ff[i-1])
				ff[i].pb(k);
		}	
	}
	vi factors;
	REP(i, n){
		int d = int(x[i]-'0');
		if(d == 1 || d == 0) continue;
		for(int p : ff[d-2]){
			factors.pb(p);
		}
	}
	sort(factors.begin(), factors.end());
	vi ans;
	while(!factors.empty()){
		int last = *(factors.end()-1);
		ans.pb(last);
		for(int i=0;i<last-1; i++){
			for(int y : f[i]){
				factors.erase(find(factors.begin(), factors.end(), y));
			}
		}
	}
	sort(ans.begin(), ans.end());
	reverse(ans.begin(), ans.end());
	for(int d : ans){
		cout << d;
	}
	cout << endl;
	return 0;
}