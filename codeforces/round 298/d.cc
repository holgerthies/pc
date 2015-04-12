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
  set<pii> a;
  vi count(1000000,0);
  REP(i, n){
    DRI(x);
    a.insert(mp(x, i));
    count[x]++;
  }
  int curr=0;
  vi ans;
  int in=0;
  while(in < n){
    while(count[curr] == 0){
      curr -= 3;
      if(curr < 0){
        std::cout << "Impossible" << std::endl;
        return 0;
      }
    }
    auto it = a.lower_bound(mp(curr, 0));
    ans.pb((*it).second+1);
    a.erase(it);
    count[curr]--;
    curr++;
    in++;
  }
  cout << "Possible" << endl;
  print(ans);
	return 0;
}
