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
	const ll mod = 1e9+7;
	cin >> n;
	string x;
	cin >> x;
	vector<vector<ll>> dp(len(x)+1, vector<ll>(4,0));
	vector<long long> D(len(x)+1, 0);
	vector<long long> A(len(x)+1, 0);
	A[0] = 1;
	vector<int> cnt(4,0);
	map<char, int> M = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
	REP(i, n){
		cnt[M[x[i]]]++;
	}
	REP(i, n){
		REP(j, 4){
			dp[i+1][j] = D[i]+cnt[j];
			//cout << i+1 << " "<<j<<" " << dp[i+1][j]<<endl;
			if(dp[i+1][j] > D[i+1])
				D[i+1] = dp[i+1][j];
		}
		ll c=0;
		REP(j, 4){
			if(D[i+1] == dp[i+1][j]){
				c++;
			}
		}
		A[i+1] = (A[i]*c) % mod;
		A[i+1] %= mod;
	}
	//cout << D[n]<<endl;
	cout << A[n]<<endl;
	return 0;
}