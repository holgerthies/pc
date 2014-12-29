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


int main(){
	int n,x;
	cin >> n>>x;
	int curr=1;
	int ans=0;
	for(int i=0; i<n;i++){
		int r,l;
		cin >> l>>r;
		int k = (l-curr)/x;
		int w = (l-(curr+k*x))+r-l+1;
		ans+=w;
		curr = r+1;
		//cout << curr <<endl;
	}
	cout << ans<<endl;
	return 0;
}