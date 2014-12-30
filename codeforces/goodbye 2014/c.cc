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
	int n,m;
	cin >> n >> m;
	vector<int> w(n);
	vector<int> order(m);
	vector<bool> seen(n+1,false);
	vector<int> S;
	for(int i=0; i<n;i++){
		cin >> w[i]; 
	}
	for(int i=0; i<m;i++){
		cin >> order[i];
		order[i]-=1;
		if(!seen[order[i]]){
			seen[order[i]] = true;
			S.push_back(order[i]);
		}
	}
	long long weight=0;
	for(int i=0; i<m;i++){
		for(int j=0; j<n;j++){
			if(S[j] != order[i]){
				weight += w[S[j]];
			} else{
				S.erase(S.begin()+j);
				S.insert(S.begin(), order[i]);
				break;
			}
		}  
	}
	cout << weight<<endl;
	return 0;
}