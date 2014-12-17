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

int parse_digit(char digit) {
    return digit - '0';
}

int main(){
	int n;
	cin >> n;
	vector<int> digits(n);
	string input;
	cin >> input;

	for(int i=0; i<n;i++){
		digits[i] = parse_digit(input[i]);
	}
	//reverse(digits.begin(), digits.end());
	vector<int> smallest(digits);
	for(int i=0; i<=9;i++){
		vector<int> rot(n);
		for(int j=0; j<n;j++){
			rot[j] = (digits[j]+i) % 10;
		}
		if(rot < smallest)
				smallest = rot;
		for(int k=0; k<=n;k++){
			rotate(rot.rbegin(), rot.rbegin()+1, rot.rend());
			if(rot < smallest)
				smallest = rot;
		}
	}
	for(int i=0; i<n; i++){
		cout << smallest[i];
	}
	cout << endl;
	return 0;
}


