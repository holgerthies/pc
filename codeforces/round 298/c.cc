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
  DRI(n);
  ll A;
  cin >> A;
  vector<ll> d(n);
  vector<ll> S(n+1, 0);
  REP(rai, n) 
  {
    cin>>d[rai];
    S[rai+1] = S[rai]+d[rai];
  }
  vector<ll> ans;
  REP(i, n){
    int num=max(0ll, d[i]-(A-n+1));
    num += max(0ll, A-(S[n]-d[i]+1));
    ans.pb(num);
  }
  print(ans);
	return 0;
}
