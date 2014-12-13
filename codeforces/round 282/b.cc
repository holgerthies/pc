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

bool is_prime(long long n){
	if(n == 2) return true;
	if(n % 2 == 0) return false;
	for(long long i=3; i<min(int(n), int(sqrt(n))+3); i+=2){
		if(n % i == 0)
			return false;
	}
	return true;
}

long long fact(long long n, long long p){
	long long cnt = 0;
	while(n % p == 0){
		n /= p;
		cnt++;
	}
	return cnt;
}

vector<pair<long long,long long>> factorize(long long n){
	vector<pair<long long,long long>> ans;
	for(long long i=2; i<min(int(n), int(sqrt(n))+3); i++){
		
		if(is_prime(i) && n % i == 0){
			long long c=fact(n, i);
			long long m=n;
			for(int j=0; j<c;j++)
				m = m/i;
			auto sub = factorize(m);
			sub.push_back(make_pair(i,c));
			return sub;
		}
	}
	if(n != 1)
		ans.push_back(make_pair(n,1));
	return ans;
}
long long number_smaller(vector<pair<long long,long long>> factors, long long n){
	//cout << n << " ";
	if(n==0) return 0;
	if(n==1) return 1;
	if(factors.size() == 0)
		return 1;
	vector<pair<long long,long long>> next(factors.size()-1);
	copy(factors.begin()+1, factors.end(), next.begin());
	long long ans=0;
	long long d=1;
	for(long long i=0; i<=factors[0].second; i++){
		//cout << d << endl;
		if(d > n)
			break;
		ans += number_smaller(next, n/d);
		d *= factors[0].first;
	}
	return ans;
}

int main(){
	long long a,b;
	cin >> a >> b;
	if(a - b == 0){
		cout << "infinity"<<endl;
	}
	else if(a-b < 0){
		cout << 0 << endl;
	}
	else{
		long long d = a-b;
		long long divisors=1;
		auto factors=factorize(d);
		for(auto p : factors){
			divisors *= p.second+1;
		}
		divisors -= number_smaller(factors, b);
		cout << divisors << endl;
	}
	return 0;
}


