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


bool bs(int x, int ai, vi& a, int left, int right){
	if(abs(left-right) <= 1)
		return ai-a[left]  == x || ai-a[right] == x;
	int middle = (left+right)/2;
	if(ai-a[middle] > x){
		return bs(x, ai, a, middle+1, right);
	} else if(ai-a[middle] < x){
		return bs(x,ai,a,left,middle-1);
	}
	return true;
}

int main(){
	int n,l,x,y;
	cin >> n >> l >> x >> y;
	vi a(n);
	set<int> dx,dy;
	REP(i, n){
		cin >> a[i];
		if(a[i]+x < l)
			dx.insert(a[i]+x);
		if(a[i]+y<l)
			dy.insert(a[i]+y);
		if(a[i]>x){
			dx.insert(a[i]-x);
		}
		if(a[i]>y){
			dy.insert(a[i]-y);
		}

	}
	bool x_found=false, y_found=false;
	REP(i, n){
		if(!x_found && bs(x, a[i], a, 0, len(a)-1))
			x_found = true;
		if(!y_found && bs(y,a[i], a, 0, len(a)-1))
			y_found = true;
	}
	if(y_found && x_found){
		cout << 0 <<endl;
	} else if(x_found){
		cout << 1<<endl;
		cout << y<<endl;
	} else if(y_found){
		cout << 1<<endl;
		cout << x<<endl;
	} else{
		set<int> intersect;
		set_intersection(dx.begin(), dx.end(), dy.begin(), dy.end(), inserter(intersect, intersect.begin()));
		if(intersect.empty()){
			cout << 2 << endl;
			cout << x << " "<< y <<endl;
		}else{
			cout << 1 << endl;
			cout << *intersect.begin()<<endl;
		}
	}
	return 0;
}