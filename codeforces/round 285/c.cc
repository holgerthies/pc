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
	int n;
	cin >> n;
	vi deg(n,0);
	vi s(n,0);
	int m=0;
	vector<pii> edges;
	queue<int> leaves;
	REP(i,n){
		cin >> deg[i] >> s[i];
		if(deg[i] == 1){
			leaves.push(i);
		}
		m += deg[i];
	}
	m /= 2;
	while(!leaves.empty()){
		int i=leaves.front();
		leaves.pop();
		if(deg[i] == 1){
			deg[s[i]]--;
			s[s[i]] ^= i;
			edges.pb(mp(i,s[i]));
			if(deg[s[i]] == 1)
				leaves.push(s[i]);
		}

	}
	cout<<m<<endl;
	for(auto e : edges){
		cout<<e.first<<" "<<e.second<<endl;
	}
	return 0;
}