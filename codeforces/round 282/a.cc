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
	vector<vector<bool>> light(10, vector<bool>(7));
	light[0] = {true, true, true, false, true, true, true};
	light[1] = {false, false, true, false, false, true, false};
	light[2] = {true, false, true,true, true, false, true};
	light[3] = {true, false, true, true, false, true, true};
	light[4] = {false, true, true, true, false, true, false};
	light[5] = {true, true, false, true, false, true, true};
	light[6] = {true, true, false, true, true, true, true};
	light[7] = {true, false, true, false, false, true, false};
	light[8] = {true, true, true, true, true, true, true};
	light[9] = {true, true, true, true, false, true, true};
	int n;
	cin >> n;
	int d1 = n/10;
	int d2 = n%10;
	int cnt=0;
	for(int x=0; x<=99; x++){
		bool possible = true;
		int x1 = x/10;
		int x2 = x % 10;
		for(int i=0; i<7; i++){
			if(light[d1][i] && !light[x1][i] || light[d2][i] && !light[x2][i]){
				possible = false;
				break;
			}
		}
		if(possible)
			cnt++;
	}
	cout << cnt << endl;
	return 0;
}


