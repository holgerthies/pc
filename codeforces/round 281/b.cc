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
	bool f = true;
	vector<int> seq1, seq2;
	unsigned long long p1=0,p2=0;
	for(int i=0; i<n;i++){
		long long a; 
		cin >> a;
		if(a > 0){
			f = true;
		} else{
			a *= -1;
			f = false;
		}
		if(f){
			seq1.push_back(a);
			p1 += a;
		}
		else{
			seq2.push_back(a);
			p2 += a;
		}
	}
	bool lex = lexicographical_compare(seq2.begin(), seq2.end(), seq1.begin(), seq1.end());
	bool same = seq1.size() == seq2.size() && equal(seq1.begin(), seq1.end(), seq2.begin());
	if(p1 > p2 || (p1 == p2 && lex) || (p1 == p2 && same && f)){
		cout << "first"<<endl;
	} else{
		cout << "second" << endl;
	}
	return 0;
}


