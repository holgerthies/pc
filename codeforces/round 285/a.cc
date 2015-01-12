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
using namespace std;
typedef long long ll;
typedef unsigned int uint;
using vi = vector<int>;
using vii = vector<vector<int>>;
using pii = pair<int,int>;

int main(){
	 int a,b,c,d;
	 cin >> a >> b >> c >> d;
	 int p1 = max((3*a)/10, a-(a/250)*c);
	 int p2 = max((3*b)/10, b-(b/250)*d);
	 if(p1 > p2){
	 	cout<<"Misha"<<endl;
	 }
	 else if(p2 > p1){
	 	cout <<"Vasya"<<endl;
	 }
	 else{
	 	cout<<"Tie"<<endl;
	 }
	return 0;
}