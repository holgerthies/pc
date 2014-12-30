/*
ID: holger1
PROG: theme
LANG: C++11
*/
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
#include <iterator>
#include <string>
#include <fstream>
#define FOR(k,a,b) for(typeof(a) k=(a); k <= (b); ++k)
#define REP(k,a) for(int k=0; k < (a); ++k)
#define INF 1000000000
using namespace std;
using vi=vector<int>;
using vii=vector<vector<int>>;

struct suffix{
	int index;
	vector<int> rank;
	suffix () : rank(vector<int>(2,0)), index(0) {};
};

vector<int> suffix_array(const vector<int>& S){
	int n=S.size();
	vector<suffix> suffixes(n);
	vector<int> index_list(n);
	vector<int> ans(n);
	for(int i=0; i<n;i++){
		//suffix suf;
		suffixes[i].index = i;
		suffixes[i].rank[0] = S[i];
		suffixes[i].rank[1] = (i+1 < n) ? S[i+1] : -INF;
		//suffixes[i] = suf;
	}
	function<int(suffix, suffix)> cmp([] (suffix a, suffix b) -> int { return a.rank[0] < b.rank[0] || a.rank[0] == b.rank[0] && a.rank[1] < b.rank[1]; });
	sort(suffixes.begin(), suffixes.end(), cmp);
	for(int i=2; i<=n; i *= 2){
		int prev_rank = suffixes[0].rank[0];
		suffixes[0].rank[0] = 0;
		index_list[suffixes[0].index] = 0;
		for(int j=1;j<n; j++){
			if(suffixes[j].rank[0] == prev_rank && suffixes[j].rank[1] == suffixes[j-1].rank[1]){
				prev_rank = suffixes[j].rank[0];
				suffixes[j].rank[0] = suffixes[j-1].rank[0];
			} else{
				prev_rank = suffixes[j].rank[0];
				suffixes[j].rank[0] = suffixes[j-1].rank[0]+1;
			}
			index_list[suffixes[j].index] = j;
		}
		for(suffix& suf : suffixes){
			int ind = suf.index + i;
			suf.rank[1] = (ind < n) ? suffixes[index_list[ind]].rank[0] : -INF;
		}
		sort(suffixes.begin(), suffixes.end(), cmp);
	}
	for(int i=0; i<n; i++){
		/*for(int j=suffixes[i].index; j<n;j++){
			cout << S[j]<<" ";
		}
		cout<<endl;*/
		ans[i] = suffixes[i].index;
	}
	return ans;
}


int bin_search(const vector<int>& S, const int s1, const int left, const int right){
	int n=S.size();
	if(right-left <= 1){
		return right;
	}
	int middle = (left+right)/2;
	int k=0;
	while(s1+k<n && middle+k<n && S[s1+k] == S[middle+k]){
		k++;
	}
	if(abs(s1-middle) <= k){
		return bin_search(S, s1, middle, right);
	} 
	return bin_search(S, s1, left, middle);
}

bool possible(const vector<int>& S, const vector<int>& A, const int size){
	int n=S.size();
	int s=A.size()-1;
	for(int i=0; i<s;i++){
		int i1=i;
		int i2=i+1;
		if(A[i1] > A[i2])
			swap(i1,i2);
		int s1 = A[i1];
		int s2 = A[i2];
		while(abs(s1-s2) <= size && i2<A.size()){
			i2++;
			s2=A[i2];
		}
		if(abs(s1-s2) <= size) continue; 
		bool found=true;
		for(int k=0; k<size; k++){
			if(S[s1+k] != S[s2+k]){
				found=false;
				break;
			}
		}
		if(found) return true;
	}
	return false;
}

/*int longest_common(const vector<int>& S, const vector<int>& A){
	int n=S.size();
	int ans=0;
	int s = A.size()-1;
	int count=1;
	int curr=S[0];
	for(int i=1; i<n;i++){
		if(S[i] == curr)
			count++;
		else{
			curr = S[i];
			ans = max(ans, count/2);
			count = 0;
		}
	}
	ans = max(ans, count/2);
	for(int i=0; i<s; i++){
		int i1=i;
		int i2=i+1;
		int s1=A[i1];
		int s2=A[i2];
		if(s2 < s1){
			swap(i1,i2);
			swap(s1,s2);
		}
		while(abs(s1-s2) < 4){
			i1--;
			s2=A[i2];
		}
		int k;
		k=0;
		int a=0;
		bool overlaps = true;
		while(overlaps && i1>=0){
			k=0;
			s1 = A[i1];
			while(s1+k<n && s2+k<n && S[s1+k] == S[s2+k] && k<S.size()/2){
				k++;
			}
			//cout<<i2<<endl;
 			if(k<=ans) {
 				break;
 			}
			if(abs(s1-s2) > k) overlaps = false;
			i1--;
		}
		/*if(k > ans && abs(s1-s2) <= k){
			//s2 = bin_search(S, s1, s2, s2+k);
			while(abs(s1-s2) <= k) s2++;
			k = 0;
			while(s1+k<n && s2+k<n && S[s1+k] == S[s2+k]) k++;
			cout << s1<<" "<<s2<<" "<<k<<endl;
		}
		//cout<<ans<<endl;

		if(k > ans && abs(s1-s2) > k) {
			ans = k;
		}
	}
	return ans;
}*/

int bs(const vector<int>& S, const vector<int>& A, const int left, const int right){
	if(right-left <= 1){
		return left;
	}
	int middle = (left+right)/2;
	if(possible(S,A, middle))
		return bs(S,A,middle, right);
	else
		return bs(S,A,left,middle);
}

int longest_common(const vector<int>& S, const vector<int>& A){
	return bs(S, A,1, S.size()/2+1);
}

int main(){
	ifstream fin("theme.in");
	ofstream fout("theme.out");
	int N;
	fin >> N;
	vector<int> S(N-1);
	int curr;
	fin >> curr;
	for(int i=1; i<N;i++){
		int next;
		fin >> next;
		S[i-1] = next-curr;
		//cout<<S[i-1]<<" ";
		curr = next;
	}
	//cout<<endl;
	vector<int> A = suffix_array(S);
	int ans =longest_common(S, A)+1;
	if(ans >= 5){
		fout << ans <<endl;
	} else{
		fout << 0<<endl;
	}
	
}