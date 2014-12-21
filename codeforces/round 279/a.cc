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
	vector<int> skill[3];
	int n;
	cin >> n;
	for(int i=1; i<=n;i++){
		int t;
		cin >> t;
		skill[t-1].push_back(i);
	}
	int use_all = skill[0].size() < skill[1].size() ? 0 : 1;
	use_all = skill[use_all].size() < skill[2].size() ? use_all : 2;
	cout << skill[use_all].size() << endl;
	int count=0;
	for(int i=0; i<skill[use_all].size(); i++){
		cout << skill[0][i] << " "<<skill[1][i] << " "<<skill[2][i]<<endl;
	}
	return 0;
}