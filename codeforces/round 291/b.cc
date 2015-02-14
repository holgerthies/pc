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

int ggt(int a , int b){
	if(b == 0) return a;
	return ggt(b, a % b);
}

int main(){
	int n,x0,y0;
	cin >> n >> x0 >> y0;
	set<pii> s;
	int count = 0;
	REP(i, n){
		int x,y;
		cin >> x >> y;
		int dx = x-x0;
		int dy = y-y0;
		pii k = mp(dx/ggt(dx,dy), dy/ggt(dx,dy));
		if(k.second < 0)
			k = mp(-k.first, -k.second);
		if(s.find(k) == s.end()){
			s.insert(k);
			count++;
		}
	}
	cout << count << endl;
	return 0;
}