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
	int n;
	cin >> n;
	vector<int> p(n);
	vector<int> pos(n+2);
	vector<vector<bool>> A(n+2, vector<bool>(n+2, false));
	vector<vector<bool>> reachable(n+2, vector<bool>(n+2, false));
	for(int i=0; i<n;i++){
		cin >> p[i];
		pos[p[i]] = i;
	}
	for(int i=0; i<n;i++){
		string x(n, ' ');
		cin >> x;
		for(int j=0; j<n;j++){
			A[i][j] = x[j]-'0';
			reachable[i][j] = A[i][j];
		}
		reachable[i][i] = 1;
	}

	for(int k=0; k<n; k++){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				reachable[i][j] = reachable[i][j] || reachable[i][k] && reachable[k][j];
			}
		}
	}
	vector<int> ans(n+2, 0);
	vector<bool> visited(n+2,false);
	for(int i=1; i<=n;i++){
		int j=pos[i];
		for(int k=0;k<=n;k++){
			if(reachable[j][k] && !visited[k]){
				ans[k] = i;
				visited[k] = true;
				break;
			}
		}
	}
	for(int i =0; i<p.size(); i++){
		cout << ans[i];
		if(i < p.size()-1) cout << " ";
	}
	cout << endl;
	return 0;
}