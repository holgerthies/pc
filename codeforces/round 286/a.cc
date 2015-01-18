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

bool is_palindrome(string s){
	for(int i=0; i<len(s)/2;i++){
		if(s[i] != s[len(s)-1-i])
			return false;
	}
	return true;
}

int main(){
	string s;
	cin >> s;
	for(int i=0; i<=len(s); i++){
		for(int j=0; j<26; j++){
			string ans="";
			for(int k=0; k<=len(s);k++){
				if(k == i){
					ans += char((int)'a'+j);
				}
				if(k < len(s))
					ans += s[k];
			}
			//cout<<ans<<endl;
			if(is_palindrome(ans)){
				cout << ans << endl;
				return 0;
			}
		}
	}

	cout << "NA" << endl;
	return 0;
}