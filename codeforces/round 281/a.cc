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
#include <string>

using namespace std;


int main(){
	string home, away;
	cin >> home >> away;
	int n;
	cin >> n;
	vector<vector<bool>> is_yellow(2,vector<bool>(100, false));
	vector<vector<bool>> is_red(2,vector<bool>(100, false));

	for(int i=0;i<n;i++){
		int t,m;
		char h, color;
		cin >> t >> h >> m >> color;
		int is_home = (h=='h') ? 1 : 0;
		if(!is_red[is_home][m] && (color == 'r' || is_yellow[is_home][m])){
			string tn = is_home ? home : away;
			cout << tn <<" "<< m << " "<<t << endl;
			is_red[is_home][m] = true;
		} else if(color == 'y'){
			is_yellow[is_home][m] = true;
		}
		
	}
	return 0;
}


