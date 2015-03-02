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
	int n,m;
	cin >> n >> m;
	queue<pii> q;
	q.push(mp(0,n));
	vector<bool> visited(50000, false);
	int ans = 0;
	visited[n] = 0;
	while(!q.empty()){
		int s,v;
		tie(s,v) = q.front();
		q.pop();
		if(v == m){
			ans = s;
			break;
		}
		if(v-1 > 0 && !visited[v-1]){
			visited[v-1] = true;
			q.push(mp(s+1, v-1));
		}
		if(v <= 2*m && !visited[2*v]){
			visited[2*v] = true;
			q.push(mp(s+1, 2*v));
		}
	}
	cout<<ans<<endl;
	return 0;
}