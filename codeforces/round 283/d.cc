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

#define INF 100000000
using namespace std;

int bin_search(const vector<int>& G, const int f, const int left, const int right){
	if(right-left<=1){
		if(G[left] == f)
			return left;
		if(G[right] == f)
			return right;
		return INF;
	}
	int middle=(left+right)/2;
	if(G[middle] >= f)
		return bin_search(G, f, left, middle);
	return bin_search(G,f,middle,right);
}

int main(){
	int n;
	cin >> n;
	vector<int> g(n);
	vector<int> G1(n+1,0);
	vector<int> G2(n+1,0);

	for(int i=0; i<n;i++){
		cin >> g[i];
		G1[i+1]=G1[i];
		G2[i+1]=G2[i];

		if(g[i] == 1) G1[i+1]=G1[i]+1;
		if(g[i] == 2) G2[i+1]=G2[i]+1;

	}
	set<pair<int,int>> result;
	for(int t=1; t<=n; t++){
		int t1=0, t2=0, c1=0,c2=0;
		int left=0;
		int last=1;
		while(left < n){
			int p1=bin_search(G1, t+G1[left], left, n+1);
			int p2=bin_search(G2, t+G2[left], left, n+1);
			//cout <<t <<" "<<left<< " "<<p1<<" "<<p2<<" "<<G2[left]<<endl;
			if(p1 == INF && p2==INF) break;
			if(p1 <= p2){
				last=1;
				left=p1;
				c1++;
			}
			else{
				last=2;
				left=p2;
				c2++;
			}
			
		}
		if(left==n && (c1 < c2 && last==2 || c2<c1 && last==1)){
			int cand = max(c1,c2);
			result.insert(make_pair(cand, t));
		}
	}
	cout<<result.size()<<endl;
	for(auto x : result){
		cout << x.first << " "<<x.second<<endl;
	}
	return 0; 
}


