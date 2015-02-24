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

int main(){
	string s, t;
	std::ios::sync_with_stdio(false);
	getline(cin,s);
	getline(cin,t);
	vi count(1000, 0);
	REP(i, len(t)){
		count[int(t[i])]++;
	}
	int c1=0;
	int c2=0;
	vector<bool> valid(len(s)+10, false);
	REP(i, len(s)){
		if(count[int(s[i])] > 0){
			count[int(s[i])]--;
			valid[i] = true;
			c1++;
		}
	}
	REP(i, len(s)){
		int r = s[i] > 'Z' ?  s[i]-('a'-'A') : s[i]+('a'-'A'); 
		if(!valid[i] && count[r] > 0 ){
			count[r]--;
			c2++;
		} 
	}
	cout << c1 << " "<<c2<<endl;
	return 0;
}