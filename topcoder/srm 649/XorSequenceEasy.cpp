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

int count(vi& A){
	int ans=0;
	REP(i, len(A)){
		for(int j=i+1; j<len(A); j++)
			if(A[i] < A[j]) ans++;
	}
	return ans;
}

class XorSequenceEasy {
public:
	int getmax(vector <int> A, int N) {
		int max_digit = log2(N);
		if((1 << max_digit) != N){
			max_digit--;
			if((1 << max_digit) != N) max_digit += 2;
		}
		REP(i, max_digit+1){
			int d = 1 << (max_digit-i);
			vi A2(A);
			REP(j, len(A)) A2[j] ^= d;
			if(count(A2) > count(A))
				A = A2;
		}
		return count(A);
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
	XorSequenceEasy *obj;
	int answer;
	obj = new XorSequenceEasy();
	clock_t startTime = clock();
	answer = obj->getmax(p0, p1);
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
	p0 = {3,2,1,0,3,2};
	p1 = 4;
	p2 = 8;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = {3,0,4,6,1,5,7,6};
	p1 = 8;
	p2 = 21;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = {3,1,4,1,5,9,2,6,5,3,5,8,9,7,9};
	p1 = 16;
	p2 = 76;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = {5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5};
	p1 = 1073741824;
	p2 = 0;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = {408024109,11635919,196474438,117649705,812669700,553475508,445349752,271145432,730417256,738416295,147699711,880268351,816031019,686078705,1032012284,182546393,875376506,220137366,906190345,16216108,799485093,715669847,413196148,122291044,777206980,68706223,769896725,212567592,809746340,964776169,928126551,228208603,918774366,352800800,849040635,941604920,326686120,920977486,964528038,659998484,207195539,607901477,725914710,655525412,949610052,142750431,766838105,1024818573,836758851,97228667};
	p1 = 1073741824;
	p2 = 720;
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
// You are given a vector <int> A and an int N that is a power of 2.
// All elements of A are between 0 and N-1, inclusive.
// 
// You can now choose an integer B which is between 0 and N-1, inclusive.
// This integer determines a new sequence C defined as follows:
// For each valid i, C[i] = (A[i] xor B).
// 
// Given the sequence C, we will count the pairs of indices (i,j) such that both i<j and C[i]<C[j].
// Compute and return the largest result we can obtain.
// 
// DEFINITION
// Class:XorSequenceEasy
// Method:getmax
// Parameters:vector <int>, int
// Returns:int
// Method signature:int getmax(vector <int> A, int N)
// 
// 
// NOTES
// -XOR (exclusive or) is a binary operation, performed on two numbers in binary notation. First, the shorter number is prepended with leading zeroes until both numbers have the same number of digits (in binary). Then, the result is calculated as follows: for each bit where the numbers differ the result has 1 in its binary representation. It has 0 in all other positions.
// -For example 42 XOR 7 is performed as follows. First, the numbers are converted to binary: 42 is 101010 and 7 is 111. Then the shorter number is prepended with leading zeros until both numbers have the same number of digits. This means 7 becomes 000111. Then 101010 XOR 000111 = 101101 (the result has ones only in the positions where the two numbers differ). Then the result can be converted back to decimal notation. In this case 101101 = 45, so 42 XOR 7 = 45.
// 
// 
// CONSTRAINTS
// -N will be between 2 and 1,073,741,824 (2^30), inclusive.
// -N will be a power of 2.
// -The number of elements in A will be between 1 and 50, inclusive.
// -Each element in A will be between 0 and N-1, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {3,2,1,0,3,2}
// 4
// 
// Returns: 8
// 
// For B=3 we get C={0,1,2,3,0,1}.
// For this C there are 8 pairs (i,j) such that i<j and C[i]<C[j].
// These are the 8 pairs: (0,1), (0,2), (0,3), (0,5), (1,2), (1,3), (2,3), and (4,5).
// No other choice of B produces more than 8 pairs.
// 
// 1)
// {3,0,4,6,1,5,7,6}
// 8
// 
// Returns: 21
// 
// 
// 
// 2)
// {3,1,4,1,5,9,2,6,5,3,5,8,9,7,9}
// 16
// 
// Returns: 76
// 
// 
// 
// 3)
// {5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5}
// 8
// 
// Returns: 0
// 
// Regardless of the value of B you choose, all elements in C will be equal.
// Thus, the number of pairs we seek is always zero.
// 
// 4)
// {408024109,11635919,196474438,117649705,812669700,553475508,445349752,271145432,730417256,738416295
// ,147699711,880268351,816031019,686078705,1032012284,182546393,875376506,220137366,906190345,16216108
// ,799485093,715669847,413196148,122291044,777206980,68706223,769896725,212567592,809746340,964776169
// ,928126551,228208603,918774366,352800800,849040635,941604920,326686120,920977486,964528038,659998484
// ,207195539,607901477,725914710,655525412,949610052,142750431,766838105,1024818573,836758851,97228667}
// 1073741824
// 
// Returns: 720
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
