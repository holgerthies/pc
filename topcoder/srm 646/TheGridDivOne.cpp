#include <vector>
#include <list>
#include <map>
#include <unordered_map>
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
#define REP(k,a) for(int k=0; k < (a); ++k)
#define INF 200000000
#define mp make_pair
#define len(s) (int)((s).size())
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned int uint;
using vi = vector<int>;
using vii = vector<vector<int>>;
using pii = pair<int,int>;

inline void debug(vector<int>& v){ for(auto i : v) cout << i << " "; cout << endl;}
inline void debug(vector<pii>& v){ for(auto i : v) cout << "("<<i.first << "," << i.second << ") "; cout << endl;}


vector<tuple<int,int,int>> neighbors(int x, int y, vector<pii>& coordsx, vector<pii>& coordsy){
	vector<tuple<int,int,int>> ans;
	auto p1 = lower_bound(coordsx.begin(), coordsx.end(), mp(x,y)); 
	auto p2 = lower_bound(coordsy.begin(), coordsy.end(), mp(y,x)); 
	auto left = p2-1;
	auto right = p2+1;
	auto top = p1+1;
	auto bottom = p1-1;
	if(left >= coordsy.begin() && left-> first == y)
		ans.pb(make_tuple(left->second, y, x-left->second));
	if(right < coordsy.end() && right->first == y)
		ans.pb(make_tuple(right->second, y, right->second-x));
	if(bottom >= coordsx.begin() && bottom->first == x)
		ans.pb(make_tuple(x, bottom->second, y-bottom->second));
	if(top < coordsx.end() && top->first == x)
		ans.pb(make_tuple(x, top->second, top->second-y));

	return ans;
}


class TheGridDivOne {
public:
	int find(vector <int> x, vector <int> y, int k) {
		set<pii> coords;
		vector<pii> coordsx, coordsy;
		vector<pii> blocked;
		REP(i, len(x)) blocked.pb({y[i], x[i]});
		sort(blocked.begin(), blocked.end());
		map<pii,int> dists;
		x.pb(0);
		y.pb(0);
		vi xs, ys;
		REP(i, len(x)){
			for(int c1 = -1; c1 <= 1; c1++){
				xs.pb(x[i]+c1);
				ys.pb(y[i]+c1);			
			}
		}

		REP(i, len(xs)){
			REP(j, len(ys)){
				auto ret = coords.insert({xs[i], ys[j]});
				if(ret.second){
					coordsx.pb({xs[i], ys[j]});
					coordsy.pb({ys[j], xs[i]});
				}
			}
		}

		sort(coordsx.begin(), coordsx.end());
		sort(coordsy.begin(), coordsy.end());
		//debug(coordsy);
		set<pair<int, pii>> q;
		q.insert({0, {0,0}});
		dists[mp(0,0)] = 0;
		int rm = 0;
		while(!q.empty()){
			pii sh;
			int xc,yc,d;
			tie(d,sh) = *q.begin();
			tie(xc, yc) = sh;
			q.erase(q.begin());
			rm = max(rm, xc);
			

			if(d < k){
				auto l = lower_bound(blocked.begin(), blocked.end(), mp(yc, xc));
				int dist;
				if(l == blocked.end() || l->first != yc){
					dist = k-d;
				}
				else{
					dist = min(k-d, l->second - xc - 1);
				}
				
				//xc += dist;
				if(dists.find(mp(xc+dist,yc)) == dists.end()){
					q.insert(mp(d+dist, mp(xc+dist,yc)));
					dists[mp(xc+dist,yc)] = d+dist;

				}
				else{
					if(dists[mp(xc+dist,yc)] > d+dist){
						q.erase(q.find({dists[mp(xc+dist,yc)], mp(xc+dist,yc)}));
						q.insert(mp(d+dist, mp(xc+dist,yc)));
						dists[mp(xc+dist,yc)] = d+dist;
					}
				}

				//d += dist;
				//rm = max(rm, xc);
			}

			for(auto n : neighbors(xc,yc, coordsx, coordsy)){
				int nx,ny,nd;
				tie(nx,ny,nd) = n;
				pii p = {nx,ny};
				if(d + nd <= k){
					if(binary_search(blocked.begin(), blocked.end(), mp(ny, nx))) continue;
					if(dists.find(p) == dists.end()){
						dists[p] = d+nd;
						q.insert({d+nd, {nx,ny}});
					} else{
						if(dists[p] > d+nd){
							auto pos = q.find({dists[p], mp(nx,ny)});
							if(pos != q.end())
								q.erase(pos);
							q.insert({d+nd, {nx,ny}});
							dists[p] = d+nd;

						}
					}
					rm = max(rm, nx);
				}
			}
		}
		return rm;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit-pf 2.3.0
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, int p2, bool hasAnswer, int p3) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}" << "," << p2;
	cout << "]" << endl;
	TheGridDivOne *obj;
	int answer;
	obj = new TheGridDivOne();
	clock_t startTime = clock();
	answer = obj->find(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p3 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p3;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	bool disabled;
	bool tests_disabled;
	all_right = true;
	tests_disabled = false;
	
	vector <int> p0;
	vector <int> p1;
	int p2;
	int p3;
	
	// ----- test 0 -----
	disabled = false;
	p0 = {1,1,1,1};
	p1 = {-2,-1,0,1};
	p2 = 4;
	p3 = 2;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = {-1,0,0,1};
	p1 = {0,-1,1,0};
	p2 = 9;
	p3 = 0;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = {};
	p1 = {};
	p2 = 1000;
	p3 = 1000;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = {1,0,0,-1,-1,-2,-2,-3,-3,-4,-4};
	p1 = {0,-1,1,-2,2,-3,3,-4,4,-5,5};
	p2 = 47;
	p3 = 31;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	// ----- test 3 -----
	disabled = false;
	p0 = {3, 3, 3, 3, 4, 5, 6, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 3, 4, 5, 6, 7, 3, 3, 3};
	p1 = {3, 4, 5, 6, 6, 6, 6, 6, 6, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, -6, -6, -6, -6, -6, -5, -4, -3};
	p2 = 10000000;
	p3 = 9999993;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	if (all_right) {
		if (tests_disabled) {
			cout << "You're a stud (but some test cases were disabled)!" << endl;
		} else {
			cout << "You're a stud (at least on given cases)!" << endl;
		}
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// PROBLEM STATEMENT
// John is standing at the origin of an infinite two-dimensional grid.
// He is going to move along this grid.
// During each second he can either stay where he is or he can move by one unit in one of the four cardinal directions (north, south, east, or west).
// Some of the grid points are blocked.
// John is not allowed to move to a blocked grid point.
// 
// 
// You are given the coordinates of the blocked grid points as vector <int>s x and y.
// For each valid i, the grid point that is x[i] units east and y[i] units north of the origin is blocked.
// You are also given an int k.
// Compute and return the maximal possible x-coordinate of a point John can reach in k seconds.
// 
// 
// DEFINITION
// Class:TheGridDivOne
// Method:find
// Parameters:vector <int>, vector <int>, int
// Returns:int
// Method signature:int find(vector <int> x, vector <int> y, int k)
// 
// 
// CONSTRAINTS
// -x will contain between 0 and 47 elements, inclusive.
// -x and y will contain the same number of elements.
// -Each element of x will be between -1,000,000,000 and 1,000,000,000, inclusive.
// -Each element of y will be between -1,000,000,000 and 1,000,000,000, inclusive.
// -All pairs (x[i], y[i]) will be distinct.
// -Each pair (x[i], y[i]) will be different from (0, 0).
// -k will be between 1 and 1,000,000,000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {1,1,1,1}
// {-2,-1,0,1}
// 4
// 
// Returns: 2
// 
// The optimal strategy is to move two times north to (0, 2) and then two times east to (2,2).
// 
// 1)
// {-1, 0, 0, 1}
// {0, -1, 1, 0}
// 9
// 
// Returns: 0
// 
// John can not make any moves.
// 
// 2)
// {}
// {}
// 1000
// 
// Returns: 1000
// 
// 
// 
// 3)
// {1,0,0,-1,-1,-2,-2,-3,-3,-4,-4}
// {0,-1,1,-2,2,-3,3,-4,4,-5,5}
// 47
// 
// Returns: 31
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
