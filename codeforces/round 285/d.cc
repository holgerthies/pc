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
#define pb push_back
#define len(s) (int)((s).size())
using namespace std;
typedef long long ll;
typedef unsigned int uint;
using vi = vector<int>;
using vii = vector<vector<int>>;
using pii = pair<int,int>;

int getSum(const vector<int>& bitree, const int index){
	int i = index+1;
	int ans=0;
	while(i > 0){
		ans += bitree[i-1];
		i -= (i & (-i));
	}
	return ans;
}


void update(vector<int>& bitree, const int index, const int value){
	int i = index+1;
	int n=(int)bitree.size();
	while(i <= n){
		bitree[i-1] += value;
		i += (i & (-i));
	}
}





vi add(vi& f1, vi& f2){
	vi ans;
	int n=len(f1);
	int c=0;
	for(int i=n-1; i>=0; i--){
		int m = (f1[i]+f2[i]+c) % (n-i);
		c = (f1[i]+f2[i]+c)/ (n-i);
		ans.push_back(m);
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int bs(vi& bitree, int i, int left, int right){
	if(left-getSum(bitree, left) == i)
		return left;
	if(right<=left){
		return -1;
	}
	int middle = (left+right)/2;
	if(middle-getSum(bitree, middle) < i){
		return bs(bitree, i, middle+1, right);
	}
	return bs(bitree, i, left+1, middle);
}

vi fr_perm(vi& f){
	int n=len(f);
	vi bitree(n,0);
	vi ans;
	for(int i : f){
		int c=bs(bitree, i, i, n);
		update(bitree, c, 1);
		ans.push_back(c);
	}

	
	return ans;
}

vi perm_fr(vi& p){
	int n=len(p);
	vi bitree(n,0);
	vi ans;
	for(int i : p){
		int index = i-getSum(bitree, i-1);
		update(bitree, i, 1);
		ans.pb(index);
	}
	return ans;
}




int main(){
	int n;
	cin >> n;
	vi p(n);
	vi q(n);
	REP(i,n) cin >> p[i];
	REP(i,n) cin >> q[i];

	vi fp = perm_fr(p);
	vi fq = perm_fr(q);
	vi s = add(fp, fq);
	vi ans = fr_perm(s);
	cout<<ans[0];
	for(int i=1; i<len(ans); i++)
		cout<<" "<<ans[i];
	cout<<endl;
	return 0;
}