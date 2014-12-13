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


class ShufflingCardsDiv2 {
public:
	string shuffle(vector <int> permutation) {
		int N = permutation.size()/2;
		int x_left = N/2;
		int y_left = N-x_left;
		if(N % 2 == 1) x_left += 1;
		int x_right = N/2;
		int y_right = N-x_right;
		for(int i=0; i<permutation.size(); i++){
			if(i % 2 == 0){
				if(permutation[i] <= N)
					x_left--;
				if(permutation[i] > N)
					y_left--;
			}
			else{
				if(permutation[i] <= N)
					x_right--;
				if(permutation[i] > N)
					y_right--;
			}
			if(x_right < 0 || x_left < 0 || y_right < 0 || y_left < 0)
				return "Impossible";
		}
		return "Possible";
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
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, string p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}";
	cout << "]" << endl;
	ShufflingCardsDiv2 *obj;
	string answer;
	obj = new ShufflingCardsDiv2();
	clock_t startTime = clock();
	answer = obj->shuffle(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p1 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p1;
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
	string p1;
	
	// ----- test 0 -----
	disabled = false;
	p0 = {1,2,3,4};
	p1 = "Possible";
	all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = {4,3,2,1};
	p1 = "Possible";
	all_right = (disabled || KawigiEdit_RunTest(1, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = {1,3,2,4};
	p1 = "Impossible";
	all_right = (disabled || KawigiEdit_RunTest(2, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = {1,4,2,5,3,6};
	p1 = "Impossible";
	all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = {8,5,4,9,1,7,6,10,3,2};
	p1 = "Possible";
	all_right = (disabled || KawigiEdit_RunTest(4, p0, true, p1) ) && all_right;
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
// Fox Ciel likes shuffling cards.
// She uses a deck with 2N cards, numbered 1 through 2N.
// 
// Ciel always uses the same procedure when shuffling.
// One round of shuffling looks as follows:
// 
// She splits the deck into two piles: the top N cards will be pile A, the bottom N cards pile B.
// She takes pile A and rearranges the cards it contains arbitrarily.
// She takes pile B and rearranges the cards it contains arbitrarily.
// She interleaves the cards from the two piles, producing a single deck again. More precisely, if pile A has cards A1,A2,...,AN and pile B has cards B1,B2,...,BN then the new deck will be A1,B1,A2,B2,...,AN,BN. (Note that the first card has to come from pile A.)
// 
// 
// For example, let N=2 and suppose that Ciel starts with the sorted deck 1,2,3,4.
// One possible round of shuffling looks as follows:
// 
// She splits the deck into two piles: the cards 1,2 are pile A and the cards 3,4 are pile B.
// She rearranges pile A into 1,2. (I.e., she keeps the cards in their current order.)
// She rearranges pile B into 4,3.
// She merges the two piles, obtaining the deck 1,4,2,3.
// 
// 
// In the above example we have shown one of four possible outcomes of the shuffling process.
// After the first round of shuffling, Ciel could have that deck in one of these four orders:
// 
// 1,3,2,4
// 1,4,2,3
// 2,3,1,4
// 2,4,1,3
// 
// 
// You are given a vector <int> permutation which contains a permutation of the 2N cards.
// Ciel's deck is currently sorted: the cards are in the order 1,2,3,...,2N from top to bottom.
// Ciel wants to make exactly two rounds of shuffling.
// After the second round the order of cards in her deck should correspond to the given permutation.
// Return "Possible" (quotes for clarity) if this can be done and "Impossible" otherwise.
// 
// DEFINITION
// Class:ShufflingCardsDiv2
// Method:shuffle
// Parameters:vector <int>
// Returns:string
// Method signature:string shuffle(vector <int> permutation)
// 
// 
// CONSTRAINTS
// -permutation will contain between 4 and 200 elements, inclusive.
// -The number of elements in permutation will be even.
// -The elements of permutation will form a permutation of the numbers 1 through 2N, where 2N is the number of elements in permutation.
// 
// 
// EXAMPLES
// 
// 0)
// {1,2,3,4}
// 
// Returns: "Possible"
// 
// Fox Ciel can make the following two shuffles: {1,2,3,4} -> {1,3,2,4} -> {1,2,3,4}.
// 
// Note that she cannot simply keep the deck in sorted order, the shuffling procedure does not allow that.
// Luckily for Ciel, it is possible to shuffle the deck in the first round and to return the cards to their original places in the second round.
// 
// 1)
// {4,3,2,1}
// 
// Returns: "Possible"
// 
// 
// 
// 2)
// {1,3,2,4}
// 
// Returns: "Impossible"
// 
// Ciel can produce this permutation after the first round of shuffling.
// However, it is not possible to start with a sorted deck and to have this permutation of cards after two rounds of shuffling.
// 
// 
// 3)
// {1,4,2,5,3,6}
// 
// Returns: "Impossible"
// 
// 
// 
// 4)
// {8,5,4,9,1,7,6,10,3,2}
// 
// Returns: "Possible"
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!