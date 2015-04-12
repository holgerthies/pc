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
  vi ans;
  if(n == 1 || n==2){
    std::cout << 1 << std::endl;
    std::cout << 1 << std::endl;
    return 0;
  }
  if(n == 3){
    std::cout << 2 << std::endl;
    cout << 1 << " " << 3 << endl;
    return 0;
  }
  if(n == 4){
    std::cout << 4 << std::endl;
    cout << 2 << " " << 4 << " " << 1 << " " << 3 << endl;
    return 0;
  }
  REP(i, n/2+1){
    if(2*i+1 > n) break;
    ans.pb(2*i+1);
  }
  if(n > 3)
  {
    REP(i, n/2){
      if(abs(2*(i+1) - ans[len(ans)-1]) != 1)
        ans.pb(2*(i+1));
      else if(abs(2*(i+1) - ans[0]) != 1)
        ans.insert(ans.begin(), 2*(i+1));
    }
  }
  std::cout << len(ans) << std::endl;
  print(ans);
	return 0;
}
