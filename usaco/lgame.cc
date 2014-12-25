/*
ID: holger1
PROG: lgame
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

using namespace std;

int points(string word){
	int ans = 0;
	unordered_map<char, int> ps={{'q', 7},{'w', 6}, {'e', 1}, {'r', 2}, {'t', 2}, {'y',5},
								{'u', 4}, {'i', 1}, {'o', 3}, {'p', 5}, {'a', 2}, {'s',1},
								{'d', 4}, {'f',6}, {'g', 5}, {'h', 5}, {'j', 7}, {'k', 6},
								{'l', 3},{'z',7}, {'x', 7},{'c', 4}, {'v', 6}, {'b', 5}, {'n', 2}, {'m', 5}};
	for(char w : word){
		ans += ps[w];
	}
	return ans;
}

pair<string, string> split(string s){
	auto i=s.find(' ');
	if(i == string::npos){
		return make_pair("", s);
	}

	string s1=s.substr(0,i);
	string s2=s.substr(i+1);
	return make_pair(s1,s2);
}

int main(){
	ifstream fin("lgame.in");
	ifstream din("lgame.dict");
	ofstream fout("lgame.out");
	string str;
	fin >> str;
	str += ' ';
	unordered_map<string, int> dict;
	while(true){
		string word;
		din >> word;
		if(word == ".")
			break;
		dict[word] = points(word);

	}
	dict[""] = 0;
	sort(str.begin(), str.end());
	int max_points=0;
	set<string> mp_words;
	do{
		for(int i=1; i<=str.size(); i++){
			string s = str.substr(0,i);
			pair<string, string> words=split(s);
			int p=0;
			if(words.second >= words.first){
				if(dict.find(words.first) != dict.end())
					p+=dict[words.first];
				else
					continue;
				if(dict.find(words.second) != dict.end())
					p+=dict[words.second];
				else
					continue;
				if(p > max_points){
					max_points = p;
					mp_words.clear();
				}	
				if(p >= max_points){
					if(words.first == "")
						mp_words.insert(words.second);
					else
						mp_words.insert(s);
				}
			}
		}
	} while(next_permutation(str.begin(), str.end()));
	fout << max_points << endl;
	for(string w : mp_words)
		fout << w <<endl;
	return 0;
}