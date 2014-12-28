/*
ID: holger1
PROG: frameup
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <stack>
#include <algorithm>
#include <limits>

#define FOR(k,a,b) for(typeof(a) k=(a); k <= (b); ++k)
#define REP(k,a) for(int k=0; k < (a); ++k)
#define INF 20000000000000000L
using namespace std;

using namespace std;

bool on_border(int i, int j, int h, int w, int t, int l){
	bool top = t==i && l >= j && l < j+w;
	bool bottom = t==i+h-1 && l >= j && l < j+w;
	bool left = l==j && t>=i && t < i+h;
	bool right = l==j+w-1 && t>=i && t < i+h;
	return top || bottom || left || right;
}

int count_h[30][30][26];
int count_v[30][30][26];

vector<int> ltop(26,1000);
vector<int> lbottom(26,-1);
vector<int> lleft(26,1000);
vector<int> lright(26,-1);


bool match_one(const vector<string>& pic, const char c, const int h, const int w, const int i, const int j, const set<char>& letters) {
	int H = pic.size();
	int W = pic[0].size();
	for(int t=0;t<H;t++){
		for(int l=0;l<W;l++){
			if(on_border(i,j,h,w,t,l)){
				if(pic[t][l] != c && letters.find(pic[t][l]) != letters.end()){
					return false;
				}
			}else{
				if(pic[t][l] == c){
					return false;
				}
			}		
		}
	}
	return true;
}

bool match(const vector<string>& pic, const char c, const int h, const int w, const set<char>& letters){
	int H = pic.size();
	int W = pic[0].size();
	for(int i=0;i<=H-h;i++){
		for(int j=0;j<=W-w;j++){
			bool ok=true;
			if(match_one(pic, c, h,w,i,j,letters))
				return true;
		}
	}
	return false;
}

set<char> find_next(const vector<string>& pic, const set<char>& letters){
	int H = pic.size();
	int W = pic[0].size();
	set<char> ans;
	for(char l : letters){
		int lc = l-'A';
		int h=lbottom[lc]-ltop[lc]+1;
		int w=lright[lc]-lleft[lc]+1;
		if(match_one(pic,l,h,w,ltop[lc],lleft[lc], letters)){
			ans.insert(l);
		}
	}
	return ans;
}

vector<vector<char>> solutions(const vector<string>& pic, set<char>& letters){
	if(letters.empty())
		return vector<vector<char>>{vector<char>()};
	set<char> next=find_next(pic,letters);
	vector<vector<char>> ans;
	for(char c :next){
		letters.erase(c);
		vector<vector<char>> subsols = solutions(pic, letters);
		for(vector<char> s : subsols){
			s.push_back(c);
			ans.push_back(s);
		}
		letters.insert(c);
	}
	return ans;
}

int main(){
	ifstream fin("frameup.in");
	ofstream fout("frameup.out");
	int H,W;
	fin >> H >> W;
	vector<string> pic(H);
	set<char> letters;
	REP(i, H){
		fin >> pic[i];
		for(char c : pic[i])
			if(c != '.') letters.insert(c);
	}
	REP(i, H){
		REP(j, W){
			if(pic[i][j] == '.') continue;
			int c = pic[i][j]-'A';
			ltop[c] = min(ltop[c], i);
			lleft[c] = min(lleft[c], j);
			lbottom[c] = max(lbottom[c], i);
			lright[c] = max(lright[c], j);
		}
	}



	auto sols = solutions(pic, letters);
	sort(sols.begin(), sols.end());
	for(vector<char> s : sols){
		for(char c : s){
			fout << c;
		}
		fout << endl;
	}
	return 0;
}