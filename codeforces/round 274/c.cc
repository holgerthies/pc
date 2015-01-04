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
#define FOR(k,a,b) for(decltype(a) k=(a); k <= (b); ++k)
#define REP(k,a) for(int k=0; k < (a); ++k)
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
	int n,a,b,k;
	cin >> n>>a>> b>>k;
	a--;b--;
	vi high(n, 0);
	vi low(n, 0);
	vector<vector<ll>> dp(n, vector<ll>(k+1,0));
	vector<ll> s(n, 0);
	REP(i,n){
		if(i > b){ 
			int h = min(n-1,2*i-b-1);
			int l = b+1;
			high[i] = h;
			low[i] = l;
		} else{
			int l = max(0, 2*i-b+1);
			int h = b-1;
			high[i] = h;
			low[i] = l;
		}
	}


	REP(i,n) dp[i][0] = 1;

	FOR(i, 1,k){
		s[0] = dp[0][i-1];
		for(int j=1; j<n;j++){
			s[j] = s[j-1]+dp[j][i-1]; 
			s[j] %= 1000000007;
		}
		REP(j,n){
			dp[j][i] = (s[high[j]]-dp[j][i-1]) % 1000000007;

			if(low[j] > 0)
				dp[j][i] -= s[low[j]-1] % 1000000007;
			dp[j][i] %= 1000000007;
			if(dp[j][i] < 0) dp[j][i] += 1000000007;
			/*for(int p=low[j]; p<=high[j];p++){
				if(p != j){
					dp[j][i] += dp[p][i-1];
				}
			}*/
		}
	}
	cout<<dp[a][k]<<endl;
	return 0;
}