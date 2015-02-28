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
	int n;
	ios_base::sync_with_stdio(false);
	 cin >> n;
	 vi a(n);
	 REP(i, n){
	 	cin >> a[i];
	 }
	 sort(all(a));
	 vi b(n-1);
	 REP(i, n-1){
	 	cin >> b[i];
	 } 
	 sort(all(b));
	 int f,s;
	 REP(i, n){
	 	if(i >= n-1 || a[i] != b[i]){
	 		f = a[i];
	 		break;
	 	}
	 }
	 vi c(n-2);
	 REP(i, n-2){
	 	cin >> c[i];
	 } 
	 sort(all(c));
	 REP(i, n-1){
	 	if(i >= n-2 || b[i] != c[i]){
	 		s = b[i];
	 		break;
	 	}
	 }
	 cout << f << endl;
	 cout << s << endl;
	return 0;
}