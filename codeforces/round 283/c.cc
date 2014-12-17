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

bool col_good(const vector<string>& rows, int c, int l, vector<bool>& is_removed){
	for(int i=0; i<rows.size()-1; i++){
		for(int j=0; j<l; j++){
			if(is_removed[c+j]) continue;
			if(rows[i][c+j] > rows[i+1][c+j]){
				return false;
			}
			if(rows[i][c+j] < rows[i+1][c+j]){
				break;
			}
		}
	}
	return true;
}


int main(){
	int n,m;
	cin >> n >> m;
	vector<string> rows(n);
	for(int i=0; i<n;i++){
		cin >> rows[i];
	}
	vector<bool> is_removed(m,false);
	bool change=true;
	while(change){
		change=false;
		int l=1;
		for(l=1; l<=m; l++){
			if(is_removed[l-1]) continue;
			if(!col_good(rows, 0, l, is_removed)){
				is_removed[l-1] = true;
				//cout << c+l-1<<endl;
				change=true;
				break;
			}
		}
		
	}
	int removed=0;
	for(int i=0; i<m;i++){
		if(is_removed[i]) removed++;
	}
	cout << removed << endl;
	return 0;
}


