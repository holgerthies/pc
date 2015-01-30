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
#define FOR(k,a,b) for(typeof(a) k=(a); k <= (b); ++k)
#define REP(k,a) for(int k=0; k < (a); ++k)
#define INF 200000000
#define mp make_pair
#define len(s) (int)((s).size())
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned int uint;
using vi = vector<int>;
using vii = vector<vector<int>>;
using pii = pair<int,int>;

int main(){
	int m,t,r;
	cin >> m >> t >> r;
	vi burning(400);
	int num=0;
	REP(i, m){
		int w;
		cin >> w;
		int n=max(0, r-burning[w]);
		if(n > t){
			cout << -1 << endl;
			return 0;
		}
		num += n;
		REP(j, n){
			REP(k, t){
				int ind = w-j+k;
				if(ind >= 0 && ind <= 300)
					burning[ind]++;
			}
		}
	}
	cout << num << endl;
	return 0;
}