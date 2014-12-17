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
	int n;
	cin >> n;
	vector<int> holds(n);
	for(int i=0; i<n; i++){
		cin >> holds[i];
	}
	int min_dist=10000000;
	int rem = -1;
	for(int i=1; i<n-1; i++){
		int dist = holds[i+1]-holds[i-1];
		if(dist < min_dist){
			min_dist = dist;
			rem = i;
		}
	}
	int difficulty = 0;
	for(int i=1; i<n;i++){
		difficulty = max(holds[i]-holds[i-1], difficulty);
	}

	difficulty = max(min_dist, difficulty);
	cout << difficulty << endl;
	return 0;
}


