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
	int i=1;
	while((i*(i+1))/2 <= n){
		n -= (i*(i+1))/2;
		i++;
	}	
	i--;
	cout << i << endl;
	return 0;
}