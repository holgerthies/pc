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

using namespace std;

long long memo[52][52];
long long ncr(int N, int k, int m){
	if(k > N || N < 0 || k < 0) return 0;
	if(memo[N][k] != -1) return memo[N][k];
	if(k == 0 || k==N) return 1;
	long long ans = ncr(N-1, k,m)+ncr(N-1, k-1,m);
	memo[N][k] = ans % m;
	return memo[N][k];
}

class OkonomiyakiParty {
public:
	int count(vector <int> osize, int M, int K) {
		sort(osize.begin(), osize.end());
		long long ans = 0;
		for(int i=0; i<=osize.size(); i++){
			for(int j=0; j<=M+1; j++){
				memo[i][j] = -1;
			}
		}
		for(int i=0; i<osize.size(); i++){
			long long length=1;
			for(int j=i+1; j<osize.size(); j++){
				if(osize[j]-osize[i] > K) break;
				length++;
			}
			ans += ncr(length-1, M-1, 1000000007);
			ans %= 1000000007;
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
bool KawigiEdit_RunTest(int testNum, vector <int> p0, int p1, int p2, bool hasAnswer, int p3) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << p1 << "," << p2;
	cout << "]" << endl;
	OkonomiyakiParty *obj;
	int answer;
	obj = new OkonomiyakiParty();
	clock_t startTime = clock();
	answer = obj->count(p0, p1, p2);
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
	int p1;
	int p2;
	int p3;
	
	// ----- test 0 -----
	disabled = false;
	p0 = {1,4,6,7,9};
	p1 = 2;
	p2 = 3;
	p3 = 6;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = {1,6,2,7,4,2,6,1,5,2,4};
	p1 = 4;
	p2 = 3;
	p3 = 60;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = {1,4,5,7,10,11,13,16,18};
	p1 = 4;
	p2 = 5;
	p3 = 0;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = {55,2,7,232,52,5,5332,623,52,6,532,5147};
	p1 = 6;
	p2 = 10000;
	p3 = 924;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = {5781,8708,1754,4750,9888,3675,4810,1020,922,9834,5695,1101,1236,2496,8431,6727,1376,3373,4423,1839,7438,9407,1851,6966,8715,2905,542,535,8980,2602,2603,3117,3452,5682,7775,4356,5140,8923,9801,3729};
	p1 = 15;
	p2 = 4003;
	p3 = 114514;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 1 -----
	disabled = false;
	p0 = vector<int>(50, 1);
	p1 = 30;
	p2 = 2;
	p3 = 2;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, p2, true, p3) ) && all_right;
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
// Wolf Sothe is planning a party for his M friends.
// He wants to give them some okonomiyaki at the party.
// (Okonomiyaki is a Japanese pancake.)
// 
// Sothe just came to an okonomiyaki restaurant.
// The restaurant makes several types of okonomiyaki.
// Each type of okonomiyaki has its specific size.
// You are given the sizes of all okonomiyaki types as a vector <int> osize.
// 
// Sothe would like to buy exactly M okonomiyaki.
// They must all have different types, so that the people at the party have the most options to choose from.
// Additionally, they must all have roughly the same sizes, so that nobody feels disappointed.
// More precisely, the difference between the size of the largest and smallest okonomiyaki ordered by Sothe must be K or less.
// 
// You are given the vector <int> osize and the ints M and K.
// Compute and return the number of different orders Sothe could place at the restaurant, modulo 1,000,000,007.
// 
// DEFINITION
// Class:OkonomiyakiParty
// Method:count
// Parameters:vector <int>, int, int
// Returns:int
// Method signature:int count(vector <int> osize, int M, int K)
// 
// 
// CONSTRAINTS
// -osize will contain between 2 and 50 elements, inclusive.
// -Each element in osize will be between 1 and 10,000, inclusive.
// -M will be between 2 and the number of elements in osize, inclusive.
// -K will be between 1 and 10,000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {1,4,6,7,9}
// 2
// 3
// 
// Returns: 6
// 
// There are five types of okonomiyaki.
// Let's call them types A, B, C, D, and E.
// (Type A has size 1, type B has size 4, and so on.)
// Sothe wants to buy M=2 different okonomiyaki and their sizes must differ by K=3 or less.
// There are 6 valid orders: A+B, B+C, B+D, C+D, C+E, and D+E.
// 
// Note that B+A is the same order as A+B: you get one pancake of type A and one pancake of type B.
// 
// 1)
// {1,6,2,7,4,2,6,1,5,2,4}
// 4
// 3
// 
// Returns: 60
// 
// Different types of okonomiyaki may have equal sizes.
// An order may contain multiple okonomiyaki of the same size, they are only required to have different types.
// 
// 2)
// {1,4,5,7,10,11,13,16,18}
// 4
// 5
// 
// Returns: 0
// 
// In this test case there is no valid order: regardless of which 4 pancakes Sothe wants, the difference between their sizes will be too large.
// 
// 3)
// {55,2,7,232,52,5,5332,623,52,6,532,5147}
// 6
// 10000
// 
// Returns: 924
// 
// 
// 
// 4)
// {5781,8708,1754,4750,9888,3675,4810,1020,922,9834,5695,1101,1236,2496,8431,6727,
// 1376,3373,4423,1839,7438,9407,1851,6966,8715,2905,542,535,8980,2602,2603,3117,3452,
// 5682,7775,4356,5140,8923,9801,3729}
// 15
// 4003
// 
// Returns: 114514
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
