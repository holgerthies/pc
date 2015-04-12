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
	DRII(v1,v2);
  DRII(t,d);
  vii s(t+1, vi(1001, 0));
  vector<vector<bool>> p(t+1, vector<bool>(1001, false));
  p[0][v1] = true;
  REP(i,  t){
    REP(j, d+1){
       REP(k, 1001){
        if(p[i][k]){
          if(k+j <= 1000){
              p[i+1][k+j] = true;
              s[i+1][k+j] = max(s[i+1][k+j], s[i][k]+k);
          }
          if(k-j >= 0){
              p[i+1][k-j] = true;
              s[i+1][k-j] = max(s[i+1][k-j], s[i][k]+k);
          }
        }
       }
    }
  }
  std::cout << s[t-1][v2]+v2 << std::endl;
	return 0;
}
