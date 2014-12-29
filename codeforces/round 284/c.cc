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
#define INF 2000000000
using namespace std;


bool same_side(long long a, long long b,long long c, long long x1,long long y1, long long x2, long long y2){
	long long f1=a*x1+b*y1+c;
	long long f2=a*x2+b*y2+c;
	return f1 < 0 && f2 <0 || f1 > 0 && f2 > 0;
}

int main(){
	int x1,y1,x2,y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int n;
	cin >> n;
	vector<int> a(n), b(n), c(n);
	int ans=0;
	for(int i=0; i<n;i++){
		cin >> a[i] >> b[i] >> c[i];
		if(!same_side(a[i], b[i], c[i], x1,y1,x2,y2))
			ans++;
	}

	cout << ans<<endl;
	return 0;
}