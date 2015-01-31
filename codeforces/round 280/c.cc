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
#include <string>
#define mp(a,b) make_pair((a), (b))
using namespace std;


int main(){
	long long r, avg, n;
	cin >> n >> r >> avg;
	avg *= n;
	long long sum=0;
	vector<long long> a(n);
	vector<pair<long long,long long>> b(n);
	for(long long i=0; i<n;i++){
		long long bv;
		cin >> a[i] >> bv;
		b[i] = mp(bv, (r-a[i]));
		sum += a[i];
	}
	sort(b.begin(), b.end());
	long long essays=0;
	for(auto p : b){
		if(sum >= avg)
			break;
		long long bv=p.first;
		long long maxk = p.second;
		long long add = min(maxk, avg-sum);
		essays += add*bv;
		sum += add;
	}
	cout << essays << endl;
	return 0;
}


