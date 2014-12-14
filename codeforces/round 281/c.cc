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
	vector<int> A, B;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		A.push_back(x);
	}
	int m;
	cin >> m;
	for(int i=0; i<m; i++){
		int x;
		cin >> x;
		B.push_back(x);
	}
	sort(A.begin(), A.end(), greater<int>());
	sort(B.begin(), B.end(), greater<int>());
	int nb=0;
	int max_na=0;
	int max_nb=0;

	int max_dist=-1;
	for(int na=1; na<=A.size(); na++){
		while(nb < B.size() && B[nb] >= A[na-1]){
			nb++;
		}
		int dist=na-nb;
		if(dist >= max_dist){
			max_dist = dist;
			max_na = na;
			max_nb = nb;
		}
	}
	int na=0;
	for(nb=0; nb<B.size(); nb++){
		while(na < A.size() && A[na] > B[nb]){
			na++;
		}
		int dist=na-nb;
		if(dist > max_dist ||  (dist == max_dist && na > max_na)){
			max_dist = dist;
			max_na = na;
			max_nb = nb;
		}
	}
	na=max_na;
	nb=max_nb;
	int score_a = na*3+(n-na)*2;
	int score_b = nb*3+(m-nb)*2;
	cout << score_a <<":"<<score_b<<endl;
	return 0;
}


