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
#define REPP(k,a,b) for(int k= (a); k < (b); ++k)
#define INF 200000000
#define mp make_pair
#define len(s) (int)((s).size())
using namespace std;
typedef long long ll;
typedef unsigned int uint;
using vi = vector<int>;
using vii = vector<vector<int>>;
using pii = pair<int,int>;

int main(){
	int n,q;
	cin >> n>>q;
	vector<ll> f(n+3,0);
	cin >> f[1]>>f[2];
	const ll md = 1000000007ll;
	int a,b;
	cin >> a >> b;
	vector<ll> x(n+1,0);
	vector<ll> p(n+3,0);
	for(int i=1; i<=n+2; i++){
		if(i>=3)
			f[i] = (a*f[i-2]+b*f[i-1]) % md;
	}
	REP(i, n) cin >> x[i+1];
	vector<pii> queries(q); 
	for(int i=0; i<q;i++){
		int l, r;
		cin >> l >> r;
		if(r == l){
			p[l] = (p[l]+(ll)f[1]) % md;
			p[l+1] = (p[l+1]-ll(b)*f[1]) % md;
			p[l+2] = (p[l+2]-ll(a)*f[1]) % md;
		} else {
			p[l] = ((ll)p[l]+f[1]) % md;
			p[l+1] = (p[l+1]+f[2]-ll(b)*f[1]) % md;
			p[r+1] = (p[r+1]-f[r-l+2]) % md;
			p[r+2] = (p[r+2]-ll(a)*f[r-l+1]) % md;

		}
	}
	REPP(i, 2, len(p)){
		p[i] = (p[i]+ll(a)*p[i-2]+ll(b)*p[i-1]) % md;
	}
	REP(i, len(x)){
		x[i] = (ll(x[i])+p[i]) % md;
		if(x[i] < 0) x[i] += md;
	}
	cout<<x[1];
	for(int i=2; i<len(x); i++)
		cout << " " << x[i];
	cout<<endl;
	return 0;
}