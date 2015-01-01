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

int fill(string& x, int f){
	int p=1;
	int ans=0;
	for(int i=0; i<x.size();i++){
		int digit;
		if(x[x.size()-i-1] == '?'){
			digit = f % 10;
			f /= 10;
		}else{
			digit = x[x.size()-i-1]-'0';
		}
		ans += p*digit;
		p *= 10;

	}
	return ans;
}

int count(string& x){
	int ans=0;
	for(char c : x){
		if(c == '?')
			ans++;
	}
	return ans;

}
int bs(string& x, int last, int left, int right){
	if(right - left <= 1){ 
		int lfill = fill(x,left);
		if(lfill > last) return lfill;
		return fill(x,right);
	}
	int middle=(left+right)/2;
	int mfill = fill(x,middle);
	if(mfill <= last)
		return bs(x, last, middle+1, right);
	return bs(x,last, left, middle);
}

int stoi2(string& x){
	int ans=0;
	int p=1;
	for(int i=x.size()-1; i>=0;i--){
		ans += (x[i]-'0')*p;
		p*=10;
	}
	return ans;
}

int find_next(string& x, int last){
	int n=count(x);
	if(n==0) return stoi2(x);
	int p = 1;
	int left=0;
	int right=0;
	for(int i=0; i<n;i++){
		right += 9*p;
		p *= 10;
	}
	if(x[0] == '?')
		left = p/10;
	return bs(x, last, left, right);
}

int main(){
	int n;
	cin >> n;
	int last = 0;
	vector<int> ans;
	for(int i=0;i<n;i++){
		string x;
		cin >> x;
		int next;
		next = find_next(x, last);
		if(next <= last){
			cout << "NO"<<endl;
			return 0;
		}
		last=next;
		ans.push_back(next);
	}
	cout << "YES"<<endl;
	for(int a : ans){
		cout << a <<endl;
	}
	return 0;
}