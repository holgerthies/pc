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
	int n,t;
	double p;
	cin >> n >> p >> t;
	vector<vector<double>> dp(n+10, vector<double>(t+10, 0.0));
	dp[0][0] = 1.0;
	REPP(j, 1, t+1){
		REPP(i, 0, n+1){
			if(i >= n)
				dp[i][j] = dp[i][j-1];
			else
				dp[i][j] = (1-p)*dp[i][j-1];
			if(i > 0)
				dp[i][j] += p*dp[i-1][j-1];
		}
	}
	double E=0.0;
	REP(i, n+1){
		E += i*dp[i][t];
	}
	printf("%.7f\n", E);
	return 0;
}