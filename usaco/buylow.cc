/*
ID: holger1
PROG: buylow
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
#define rep(n) for(int i=0;i<(n);i++)
using namespace std;

struct bignum{
	string num;
	bignum(string n) : num(n) {};
	bignum operator+(const bignum& other){
		int overflow=0;
		string result="";
		string n1=this->num;
		string n2=other.num;
		while(n1.size() < n2.size())
			n1 += '0';
		while(n2.size() < n1.size())
			n2 += '0';
		for(int i=0; i<n1.size();i++){
			int a = n1[i]-'0';
			int b = n2[i]-'0';
			char d = (a+b+overflow) % 10 + '0';
			overflow = (a+b+overflow)/10;
			//cout << a<< " " << b << " " << d<< " " << overflow << endl;
			result += d;
		}
		if(overflow ){
			char x=overflow+'0';
			result += x;
		}
		return result;
	}
};

int main(){
	ifstream fin("buylow.in");
	ofstream fout("buylow.out");
	int N;
	fin >> N;
	N++;
	vector<int> dp(N);
	vector<int> prices(N);
	vector<bignum> count(N,bignum("1"));
	vector<vector<int>> next(N, vector<int>());
	dp[N-1] = 1;   
	prices[0] = INF;
	for(int i=1;i<=N;i++){
		fin >> prices[i];
	}
	for(int i=N-2; i>=0; i--){
		int sm=0;
		for(int j=i+1;j<N;j++){
			if(prices[j] < prices[i]){
				if(dp[j] == sm){
					bool insert=true;
					for(int ind : next[i]){
						if(prices[ind] == prices[j]){
							insert=false;
							break;
						}
					}
					if(insert){
						count[i] = count[i]+count[j];
						next[i].push_back(j);
					}
				}
				if(dp[j] > sm){
					sm=dp[j];
					count[i] = count[j];
					next[i] = vector<int>{j};
				}
				
			}
		}
		//if(count[i].num == "0") count[i] = bignum("1");
		dp[i] = sm+1;
	}
	int m=*max_element(dp.begin(), dp.end());
	string c = count[0].num ;
	reverse(c.begin(), c.end());
	fout << m-1 << " " << c <<endl;
	return 0;
}