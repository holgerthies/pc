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
using namespace std;
typedef long long ll;
typedef unsigned int uint;
using vi = vector<int>;
using vii = vector<vector<int>>;
using pii = pair<int,int>;

int main(){
	map<string, string> new_handle;
	map<string, string> orig;
	int n;
	cin >> n;
	for(int i=0; i<n;i++){
		string o, nw;
		cin >> o >> nw;
		if(orig.find(o) != orig.end()){
			new_handle[orig[o]] = nw;
			orig[nw] = orig[o];
		}else{
			new_handle[o] = nw;
			orig[nw] = o;
		}
	}
	cout<<new_handle.size()<<endl;
	for(auto p : new_handle){
		cout <<p.first<<" "<<p.second<<endl;
	}
	return 0;
}