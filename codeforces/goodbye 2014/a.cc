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
	int n, t;
	cin >> n >> t;
	vector<int> move(n,-1);
	for(int i=0; i<n-1;i++){
		int a;
		cin >> a;
		move[i] = i+a;
	}
	int curr=0;
	while(curr != -1 && curr != t-1){
		curr=move[curr];
	}
	if(curr == t-1)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}