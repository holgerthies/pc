/*
ID: holger1
PROG: fc
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
#include <complex>

#define FOR(k,a,b) for(typeof(a) k=(a); k <= (b); ++k)
#define REP(k,a) for(int k=0; k < (a); ++k)
#define INF 200000000
using namespace std;
using vi=vector<int>;
using vii=vector<vector<int>>;


double cross(const complex<double>& p, const complex<double>& q){
	return real(p)*imag(q)-imag(p)*real(q);
}

vector<int> convex_hull(const vector<complex<double>>& points){
	int n = points.size();
	vector<int> ans;
	int lm=0;
	for(int i=0; i<n; i++){
		if(real(points[i]) < real(points[lm]))
			lm = i;
	}
	int curr = lm;
	do {
		ans.push_back(curr);
		int next=-1;
		for(int i=0; i<n; i++){
			if(i==curr) continue;
			if(next == -1 || cross(points[i]-points[curr], points[next]-points[curr]) < 0)
				next = i;
		}
		curr = next;
	} while(curr != lm);
	return ans;
}

int main(){
	ifstream fin("fc.in");
	ofstream fout("fc.out");
	int N; 
	fin >> N;
	vector<complex<double>> spots(N);
	for(int i=0; i<N;i++){
		double x,y;
		fin >> x>> y;
		spots[i] = complex<double>(x,y);
	}
	auto hull = convex_hull(spots);
	double ans=0.0;
	for(int i=0; i<hull.size(); i++){
		int n = (i+1)% hull.size();
		ans += abs(spots[hull[i]]-spots[hull[n]]);
	}
	fout<<setprecision(2)<<fixed<<ans<<endl;
	return 0;
}