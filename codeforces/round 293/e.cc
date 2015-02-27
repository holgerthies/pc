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
#include <stdio.h>
#define REP(k,a) for(int k=0; k < (a); ++k)
#define REPP(k,a,b) for(int k= (a); k < (b); ++k)
#define INF 200000000
#define mp make_pair
#define len(s) (int)((s).size())
#define pb push_back
#define all(X) (X).begin(), (X).end()
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)

using namespace std;
typedef long long ll;
typedef unsigned int uint;
using vi = vector<int>;
using vii = vector<vector<int>>;
using pii = pair<int,int>;
template <class T>
void print(vector<T> v){ bool first=true; for(T x : v) { if(!first) cout << " "; first = false; cout << x; } cout << endl;}

ll toint(string x){
	bool negative=false;
	if(x[0] == '-') negative = true;
	ll ans = 0;
	for(char c : x){
		if(c == '-') continue;
		ans *= 10;
		ans += int(c-'0');
	}
	if(negative) ans *= -1;
	return ans;
}


int main(){
	DRII(n,k);
	vector<ll> a(n,0);
	vector<bool> qm(n, false);

	REP(i, n){
		string x;
		cin >> x;
		if(x == "?"){
			a[i] = 0;
			qm[i] = true;
		}
		else{
			a[i] = toint(x);
		}
 	}
	 
	bool possible = true;
	REP(i, k){
		int j=0;
		while(true){
			if(i+k*j >= n) break;
			int length = 0;
			while(k*(j+length)+i < n && qm[k*(j+length)+i]){
				length++;
			}
			if(length > 0){
				ll before = (k*(j-1)+i >= 0) ? a[k*(j-1)+i] : -10e14;
				ll after = (k*(j+length)+i >= n) ? 10e14 : a[k*(j+length)+i];
				if(after-before < length){
					possible = false;
					break;
				} 
				ll next=0;
				//cout << i << " " <<  j << " " << before << " " << after << endl;
				if(before >= 0){
					next = before+1;
				} else if(after <= 0){
					next = after-length;
				} else{
					next = min(after-length, max(before+1, -(ll)length/2));
				}
				REP(r, length){
					a[k*(j+r)+i] = next+r;
				}
				j += length;
			} else{
				j++;
			}
		}
	}
	REP(i, k){ 
		if(!possible) break;
		REP(j, n/k){
			if(i+k*(j+1) >= n) continue;

			if(a[i+k*j] >= a[i+k*(j+1)]){
				possible = false;
				break;
			}
		}
	}
	if(possible){
		print(a);
	} else{
		cout << "Incorrect sequence" << endl;
	}
}