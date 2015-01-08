/*
ID: holger1
PROG: milk4
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <stack>
#include <algorithm>
#include <limits>
#include <queue>
#define INF 500000000
#define MAXQ 20000
#define MAXP 100
#define MAXVAL 10000
#define rep(n) for(int i=0;i<(n);i++) 
using namespace std;
using uint=unsigned int;
vector<int> partition(const int Q, const int P, const int num, const vector<int>& vals, const int first, int dp[MAXQ+1][MAXP+1]){
	vector<int> ans;
	if((num==0 && Q > 0) || (Q==0 && num > 0) || Q<0 || num<0)
		return vector<int>();
	if(num == 1){
		for(uint i=first; i<vals.size();i++){
			if(Q % vals[i] == 0)
				return vector<int>{vals[i]};
		}
		return vector<int>();
	}
	int v=vals[first];
	for(int k=1;k*v<Q; k++){
		if(dp[Q-k*v][P] == num-1){
			vector<int> p=partition(Q-k*v, P, num-1,vals,first+1, dp);
			if(ans.size() == 0 || p < ans){
				ans = p;
			}
		}
	}
	if(ans.size() == 0)
		ans = partition(Q, P, num,vals,first+1, dp);
	else{
		ans.push_back(v);
	}
	return ans;
}

int main(){
	ifstream fin("milk4.in");
	ofstream fout("milk4.out");
	int Q, P;
	fin >> Q >> P;
	vector<int> vals(P);
	for(int i=0; i<P;i++){
		fin >> vals[i];
	}
	sort(vals.begin(), vals.end());
	int dp[MAXQ+1][MAXP+1];
	for(int i=0; i<=Q; i++){
		for(int j=0; j<=P; j++)
			dp[i][j] = INF;
	}
	dp[0][0] = 0;
	for(int p=0; p<=P;p++){
		for(int q=0; q<=Q; q++){
			if(dp[q][p] < dp[q][p+1]){
				dp[q][p+1] = dp[q][p];
			}
			if(p==P || q > Q-vals[p]) continue;

			for(int k=1; q+k*vals[p] <= Q; k++){
				if(dp[q][p]+1 < dp[q+k*vals[p]][p+1] && dp[q][p]+1 <  dp[q+k*vals[p]][p]){
					dp[q+k*vals[p]][p+1] = dp[q][p]+1;
				}
				else if(dp[q+k*vals[p]][p] <= dp[q+k*vals[p]][p+1]){
					dp[q+k*vals[p]][p+1] = dp[q+k*vals[p]][p];
				}
			}
		}
	}	
	vector<int> ans=partition(Q,P, dp[Q][P], vals,0, dp);

	
	sort(ans.begin(),ans.end());
	fout << ans.size();
	for(int a : ans)
		fout <<" "<< a;
	fout <<endl;
	return 0;
}