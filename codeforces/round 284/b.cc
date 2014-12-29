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
	unordered_map<string,string> T;
	int n,m;
	cin >> n >> m;
	for(int i=0; i<m; i++){
		string w, w2;
		cin >> w >> w2;
		T[w] = w2;
	}
	for(int i=0; i<n; i++){
		string w;
		cin >> w;
		if(T[w].size() < w.size())
			cout << T[w];
		else
			cout << w;
		if(i < n-1)
			cout << " ";
	}
	cout << endl;
	return 0;
}