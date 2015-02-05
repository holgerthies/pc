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
	int n,k;
	cin >> n >> k;
	vi a(n);
	vii c(n);
	vii b(n, vi(k,0));
	REP(i,n){
		cin >> a[i];
		c[i] = vi(a[i]);
	}
	int ma = *max_element(a.begin(), a.end());
	REP(i,ma){
		REP(j, n){
			if(i < a[j]){
				c[j][i] = (i % k)+1;
				b[j][(i % k)]++;
			}
		}
	}
	REP(i, n){
		REP(j, n){
			REP(cl, k){
				if(abs(b[i][cl]-b[j][cl]) > 1){
					cout << "NO"<<endl;
					return 0;
				}
			}
		}
	}
	cout << "YES"<<endl;
	REP(i, n){
		REP(j, a[i]){
			cout << c[i][j];
			if(j != a[i]-1)
				cout << " ";
		}
		cout<<endl;
	}
	return 0;
}