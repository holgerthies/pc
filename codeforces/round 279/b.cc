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
	int n;
	cin >> n;
	map<int,int> next;
	map<int,int> parent;
	int last=0;
	set<int> ids;
	for(int i=0; i<n;i++){
		int a,b;
		cin >> a >> b;
		next[a] = b;
		parent[b] = a;
		ids.insert(a);
		ids.insert(b);
	}
	set<int> comp1;
	int c0=next[0];
	while(next.find(c0) != next.end() && c0 != 0){
		comp1.insert(c0);
		c0 = next[c0];
	}
	int start1=next[0];
	int start2=0;
	for(int i : ids){
		if(comp1.find(i) == comp1.end() && parent.find(i) == parent.end()){
			start2=i;
			break;
		}
	}
	
	for(int i=0; i<n;i++){
		if(i % 2 == 0){
			cout << start2;
			start2=next[start2];
		}
		else{
			cout << start1;
			start1=next[start1];
		}

		if(i != n-1)
			cout << " ";
	}
	cout << endl;
	return 0;
}