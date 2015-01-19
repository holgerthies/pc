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

vii memo;
int maxnum(int curr, int d, int length, vector<int>& g, vector<int>& S){
	int ans = 0;
	//cout<<curr<<endl;
	int diff=length-d+500;
	if(S[30000]-S[curr] == 0) return g[curr]; 
	if(memo[curr][diff] != -1)
		return memo[curr][diff];
	for(int i=-1;i<=1;i++){
		if(length+i > 0 && curr+length+i <= 30000){
			if(S[30000]-S[curr+length+i-1] <= ans)
				continue;
			int sub=maxnum(curr+length+i,d, length+i, g, S);
			if(sub > ans)
				ans = sub;
		}
	}
	memo[curr][diff] = ans+g[curr];
	return memo[curr][diff];
}

int main(){
	int n,d;
	cin >> n >> d;
	vector<int> g(30001, 0);
	memo = vii(30001, vi(1001, -1));
	vector<int> S(30001, 0);
	for(int i=0; i<n;i++){
		int x;
		cin >> x;
		g[x] += 1;
	}
	for(int i=1; i<=30000; i++){
		S[i] = g[i]+S[i-1];
	}
	cout << maxnum(d, d,d, g, S) << endl;
	return 0;
}