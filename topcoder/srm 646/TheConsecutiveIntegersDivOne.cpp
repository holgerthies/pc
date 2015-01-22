#include <vector>
#include <list>
#include <map>
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
#define INF 2147483647
#define mp make_pair
#define len(s) (int)((s).size())
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned int uint;
using vi = vector<int>;
using vii = vector<vector<int>>;
using pii = pair<int,int>;

class TheConsecutiveIntegersDivOne {
public:
	int find(vector <int> numbers, int k) {
		sort(numbers.begin(), numbers.end());
		int ans=INF;
		REP(i, len(numbers)-k+1){
			REP(j,k){
				int x = numbers[i+j]-j;
				int dist=0;
				REP(r,k){
					if(dist >= ans -  abs(x+r-numbers[i+r])){
						dist = ans;
						break;
					}
					dist += abs(x+r-numbers[i+r]);
				}
				ans = min(ans, dist);
			}
		}
		return ans;
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
bool KawigiEdit_RunTest(int testNum, vector <int> p0, int p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << p1;
	cout << "]" << endl;
	TheConsecutiveIntegersDivOne *obj;
	int answer;
	obj = new TheConsecutiveIntegersDivOne();
	clock_t startTime = clock();
	answer = obj->find(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p2;
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
	int p1;
	int p2;
	
	// ----- test 0 -----
	disabled = false;
	p0 = {4,7,47};
	p1 = 2;
	p2 = 2;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = {1,100};
	p1 = 1;
	p2 = 0;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = {-96,-53,82,-24,6,-75};
	p1 = 2;
	p2 = 20;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = {64,-31,-56};
	p1 = 2;
	p2 = 24;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = {-4845232, -5077278, -1696332, 9685053, -8008906, -2041580, -2825611, 7330935, -1994531, -5206896, -202206, -1506777, 8005773};
	p1 = 9;
	p2 = 12555151;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, true, p2) ) && all_right;
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
// John and Brus have some integers.
// You are given these integers in a vector <int> numbers.
// In one operation they can pick a number and increase/decrease it by 1.
// They want to have at least k consecutive integers.
// The order in which those integers appear in numbers does not matter.
// Return the minimal number of operations required to achieve the goal.
// 
// 
// DEFINITION
// Class:TheConsecutiveIntegersDivOne
// Method:find
// Parameters:vector <int>, int
// Returns:int
// Method signature:int find(vector <int> numbers, int k)
// 
// 
// CONSTRAINTS
// -numbers will contain between 2 and 47 elements, inclusive.
// -Each element of numbers will be between -10,000,000 and 10,000,000, inclusive.
// -All elements of numbers will be distinct.
// -k will be between 1 and the number of elements in numbers, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {4, 7, 47}
// 2
// 
// Returns: 2
// 
// There are three optimal strategies:
// 
// Increase 4 two times to obtain {6,7,47}.
// Decrease 7 two times to obtain {4,5,47}.
// Increase 4 and decrease 7 to obtain {5,6,47}.
// 
// 
// 
// 1)
// {1, 100}
// 1
// 
// Returns: 0
// 
// No operation is needed.
// 
// 2)
// {-96, -53, 82, -24, 6, -75}
// 2
// 
// Returns: 20
// 
// 
// 
// 3)
// {64, -31, -56}
// 2
// 
// Returns: 24
// 
// 
// 
// 4)
// {-96, -53, 82, -24, 6, -75}
// 4
// 
// Returns: 90
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!