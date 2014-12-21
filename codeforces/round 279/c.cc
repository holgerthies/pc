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

int modpow(int x, int a, int m){
	if(a==0) return 1;
	if(a % 2 == 1)
		return (x*modpow(x,a-1, m) % m);
	long long result = modpow(x,a/2,m);
	return (result*result) % m;
}

int large_modulo(string n, int m){
	int ans=0;
	for(int i=0; i<n.size(); i++){
		int d = n[i]-'0';
		ans += d*modpow(10, n.size()-1-i, m);
		ans %= m;
	}
	return ans;
}
int main(){
	string n;
	cin >> n;
	int a,b;
	cin >> a >> b;
	int m1=0;
	int m2 = large_modulo(n, b);
	for(int i=1; i<n.size(); i++){
		int d =int(n[i-1])-'0';
		m1 *= 10;
		m1 %= a;
		m1 += d;
		m1 %= a;
		int x = d*modpow(10, n.size()-i, b);
		x %= b;
		int x_inv = b-x;
		m2 += x_inv;
		m2 %= b;
		if(m1 == 0 && m2==0 && n[i] != '0'){
			cout << "YES"<<endl;
			cout << n.substr(0, i) << endl;
			cout << n.substr(i) << endl;
			return 0;
		}
	}
	cout << "NO"<<endl;
	return 0;
}