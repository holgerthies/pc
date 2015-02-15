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


int find_max(const int m, const int i, const int j, const vector<vii>& M){
	int k=0,kp = 1;
	while(i+2*kp <= j){
		k++;
		kp *= 2;
	}
	if(i + kp == j)
		return M[m][i][k];
	int t=0, tp = 1;
	while(j-tp > i+kp){
		tp *= 2;
		t++;
	}
	return max(M[m][i][k], M[m][j-tp][t]);

}

int bin_search(int m, int k, int i, int left, int right, vector<vii>& M){
	if(right-left <= 1){
		return left;
	}
	int middle = (left+right)/2;
	ll shots = 0;
	REP(r, m){
		shots += (ll)find_max(r, i,middle,M);
	}
	if(shots <= k){
		return bin_search(m,k,i, middle, right, M);
	}
	return bin_search(m,k, i, left, middle, M);

}

int main(){
	int n,m,k;
	cin >> n >> m >> k;
	vii D(m, vi(n));
	vector<vii> M(m, vii(n, vi(int(log(n))+6)));
	REP(i,n){
		REP(j, m){
			cin >> D[j][i];
		}
	}
	REP(i, m){
		REP(sz, int(log(n))+6){
			REP(j, n){
				if(sz == 0){
					M[i][j][sz] = D[i][j];
				} else{
					if(j+pow(2,sz-1) >= n){
						M[i][j][sz] = M[i][j][sz-1];
					}else{
						M[i][j][sz] = max(M[i][j][sz-1], M[i][j+pow(2,sz-1)][sz-1]);
					}
				}
			}
		}
	}
	int max_num = 0;
	vi max_shots(m, 0);
	REP(i, n){
		int j = bin_search(m, k,i, i+1, n+1, M);
		//if(i==0) cout << j << " " << find_max(0, i, j, M)<<endl;
		ll shots=0;
		REP(r, m){
			shots += (ll)find_max(r, i,j,M);
		}
		if(j-i > max_num && shots <= k){
			REP(r,m){
				max_shots[r] = find_max(r, i,j,M);
			}
			max_num = j-i;
		}
	}	
	//cout<<m<<endl;
	REP(i, m){
		cout << max_shots[i];
		if(i != m-1)
			cout << " ";
	}
	cout << endl;
	return 0;
}