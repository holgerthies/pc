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
	string s;
	cin >> s;
	long long last_index=0;
	long long count_after=0;
	for(long long i=0; i<s.length(); i++){
		if(s[i] == ')'){
			count_after++;
		}
		if(s[i] == '('){
			count_after--;
		}
		if(s[i] == '#'){
			last_index=i;
			count_after = 0;
		}
	}
	if(count_after < 0){
		cout << "-1"<<endl;
		return 0;
	}
	vector<long long> out;
	long long open_count=0;
	for(long long i=0; i<s.length(); i++){
		if(s[i] == '(') open_count++;
		if(s[i] == ')') open_count--;
		if(open_count < 0){
			cout << "-1" << endl;
			return 0;
		}
		if(s[i] == '#'){
			if(open_count == 0){
				cout << "-1" << endl;
				return 0;
			}
			if(i != last_index){
				out.push_back(1);
				open_count--;
			}
			else{
				long long d=open_count-count_after;
				open_count-=d;
				if(d <= 0){
					cout << "-1" << endl;
					return 0;
				}
				out.push_back(d);
			}
		}
	}
	if(open_count != 0){
		cout << "-1"<<endl;
		return 0;
	}
	for(long long i : out){
		cout << i << endl;
	}
	return 0;
}


