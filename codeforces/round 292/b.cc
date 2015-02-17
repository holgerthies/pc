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
#define INF 200000000
#define mp make_pair
#define len(s) (int)((s).size())
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned int uint;
using vi = vector<int>;
using vii = vector<vector<int>>;
using pii = pair<int,int>;

int main(){
	int n,m;
	cin >> n >> m;
	int b;
	cin >> b;
	vector<bool> happyboy(n, false);
	vector<bool> happygirl(m, false);
	REP(i, b){
		int x;
		cin >> x;
		happyboy[x] = true;
	} 
	int g;
	cin >> g;
	REP(i, g){
		int x;
		cin >> x;
		happygirl[x] = true;
	}

	REP(i, n*m){
		if(happyboy[i % n] || happygirl[i % m]){
			happyboy[i % n] = true;
			happygirl[i % m] = true;
		}
	}
	bool change=true;
	while(change){
		change=false;
		REP(i, n*m){
			if((happyboy[i % n] && !happygirl[i % m]) || (!happyboy[i % n] && happygirl[i % m])){
				happyboy[i % n] = true;
				happygirl[i % m] = true;
				change = true;
			}
		}
	}
	bool allbhappy=true, allghappy=true;
	REP(i, n){
		if(!happyboy[i]) allbhappy = false;
	}
	REP(i, m){
		if(!happygirl[i]) allghappy = false;
	}
	if(allbhappy && allghappy)
		cout<<"YES" << endl;
	else
		cout<<"NO"<<endl;
	return 0;
}