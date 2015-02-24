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

int main(){
	DRIII(n,m,k);
	vi a(n+1);
	vi pos(n+1);
	REP(i, n){
		cin >> a[i];
		pos[a[i]] = i;
	}
	ll ans=0;
	REP(i, m){
		int b;
		cin >> b;
		int steps = (pos[b])/k + 1;
		ans += (ll)steps;
		if(pos[b] != 0){
			int t=a[pos[b]-1];
			swap(a[pos[b]], a[pos[b]-1]);
			swap(pos[b], pos[t]);
		}
	}
	cout << ans<<endl;
	return 0;
}