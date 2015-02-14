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

ll modpow(int a, int x, ll m){
	if(x == 0)
		return 1;
	if(x % 2 == 1)
		return (a*modpow(a, x-1, m)) % m;
	ll x2 = modpow(a, x/2, m);
	return (x2*x2) % m;

}

ll hashstr(string x, int b, ll m){
	ll ans=0;
	REP(i, len(x)){
		ll d = modpow(b, i, m);
		ans += (ll(x[i]-'a'+1)*d) % m;
		ans %= m;
	}
	return ans;
}

int main(){
	int n,m;
	cin >> n >> m;
	unordered_set<ll> hash1, hash2, hash3;
	const ll m1 = 1000000007ll, m2=1000000009ll, m3 = 1100000009ll, b1=4,b2=7,b3=13;
	REP(_, n){
		string x;
		cin >> x;
		ll h1 = hashstr(x, b1, m1);
		ll h2 = hashstr(x, b2, m2);
		ll h3 = hashstr(x, b3, m3);

		REP(i, len(x)){ 
			ll d1 = modpow(b1, i, m1);
			ll d2 = modpow(b2, i, m2);
			ll d3 = modpow(b3, i, m3);
			ll dx1 = (ll(x[i]-'a'+1)*d1) % m1;
			ll dx2 = (ll(x[i]-'a'+1)*d2) % m2;
			ll dx3 = (ll(x[i]-'a'+1)*d3) % m3;
			ll hs1 = (h1-dx1+m1) % m1 , hs2 = (m2+h2-dx2) % m2, hs3 = (m3+h3-dx3) % m3;
			if(x[i] != 'a'){
				hash1.insert((hs1 + d1) % m1);
				hash2.insert((hs2 + d2) % m2);
				hash3.insert((hs3 + d3) % m3);
			}

			if(x[i] != 'b'){
				hash1.insert((hs1 + 2*d1) % m1);
				hash2.insert((hs2 + 2*d2) % m2);
				hash3.insert((hs3 + 2*d3) % m3);
			}
			if(x[i] != 'c'){
				hash1.insert((hs1 + 3*d1) % m1);
				hash2.insert((hs2 + 3*d2) % m2);
				hash3.insert((hs3 + 3*d3) % m3);
			}
		}
	}
	REP(_, m){
		string query;
		cin >> query;
		ll hq1 = hashstr(query,b1,m1), hq2 = hashstr(query,b2,m2), hq3 = hashstr(query,b3,m3);
		if(hash1.find(hq1) != hash1.end() && hash2.find(hq2) != hash2.end() && hash3.find(hq3) != hash3.end()){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}