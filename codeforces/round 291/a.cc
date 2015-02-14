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
	string x;
	string ans;
	cin >> x;
	bool fd=true;
	REP(i, len(x)){
		if(x[i] == '9' && fd){
			ans += '9';
			fd = false;
			continue;
		}
		fd = false;
		if(x[i]-'0' >= 5){
			ans += '0'+'9'-x[i];
		} else{
			ans += x[i];
		}
	}
	if(len(ans) == 0) ans = "0";
	cout<<ans<<endl;
	return 0;
}