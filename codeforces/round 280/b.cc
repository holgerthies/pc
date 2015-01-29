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

using namespace std;


int main(){
	int n,l;
	cin >> n >> l;

	vector<int> pos(n);
	for(int i=0; i<n;i++){
		cin >> pos[i];
	}
	sort(pos.begin(), pos.end());
	int curr = 0;
	int maxdist = 2*pos[0];
	bool first=true;
	for(int p : pos){
		maxdist = max(maxdist, p-curr);
		curr = p;
	}
	maxdist = max(maxdist, 2*(l-*(pos.end()-1)));
	long double ds = (long double)(maxdist)/2.0;
	cout << std::setprecision(30) << ds << endl;
	return 0;
}


