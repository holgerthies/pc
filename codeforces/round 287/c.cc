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

ll pow(ll a, ll x){
	if(x == 0) return 1;
	if(x % 2 == 1)
		return a*pow(a, x-1);
	ll x2 = pow(a, x/2);
	return x2*x2;
}
int main(){
	ll h, n;
	cin >> h >> n;
	ll ans=0;
	bool left=true;


	while(h > 0){
		ll num = pow(2ll, h);
		ll leaves = pow(2ll, h-1);
		//cout << num<<" "<<leaves<<" "<<n<<" "<<left<<endl;
		if(left && n > leaves){
			//cout<<"adding "<<num<<endl;
			ans += num;
			n -= leaves;
		} else if(!left && n <= leaves){
			ans += num;
			left=false;
		} else if(left){
			ans++;
			left=false;
		} else{
			n -= leaves;
			ans++;
			left=true;
		}
		h--;
	}
	cout<<ans<<endl;
	return 0;
}