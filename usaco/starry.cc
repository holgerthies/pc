/*
ID: holger1
PROG: starry
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
#define FOR(k,a,b) for(typeof(a) k=(a); k <= (b); ++k)
#define REP(k,a) for(int k=0; k < (a); ++k)
#define INF 20000000000000000L
using namespace std;
using vi=vector<int>;
using vii=vector<vector<int>>;


int W,H;

struct pattern{
	pair<int,int> start;
	vector<vector<bool>> pattern;
	int letter;
	int top;
	int left;
	int count;
};
vector<pair<int,int>> neighbors(pair<int,int> v){
	std::vector<pair<int,int>> ans;
	for(int i=-1;i<=1;i++){
		int w1 = v.first+i;
		for(int j = -1; j<=1;j++){
			int w2 = v.second+j;
			if(w1 >= 0 && w1 <H && w2 >= 0 && w2 <W){
				ans.push_back(make_pair(w1,w2));
			}
		}
	}
	return ans;
}

/*pattern make_pattern(vector<pair<int,int>> pattern_points, int left, int right, int top, int bottom){
	if(left==right && top==bottom){
		return pattern(make_pair(top,left), make_pair(1,1), 1, NULL, NULL, NULL, NULL);
	} else{
		int count = pattern_points.size();
		vector<pair<int,int>> tlp, trp, blp, brp;
		int v = top+1;
		int h = left+1;
		

	}
}*/

bool match_rot(vector<vector<bool>>& p1, vector<vector<bool>>& p2, int rot){
	for(int mirror=0; mirror<=1;mirror++){
		bool match=true;
		for(int i=0; i<p1.size(); i++){
			for(int j=0; j<p1[0].size(); j++){
				int k=i, l=j;	
				if(rot == 1){
					k=j; l=i;
				}
				if(rot == 2){
					k=p1.size()-i-1;
					l = p1[0].size()-j-1;
				}
				if(rot == 3){
					k = p1[0].size()-j-1;
					l = p1.size()-i-1;
				}
				if(mirror){
					l = p2[0].size()-l-1;
				}
				if(p1[i][j] != p2[k][l]){
					match=false;
					break;
				}
			}
			if(match == false)
				break;
		}
		if(match)
			return true;
	}
	return false;
}

bool pattern_match(pattern& p1, pattern& p2){
	if(p1.count != p2.count)
		return false;
	int n1 = p1.pattern.size();
	int m1 = p1.pattern[0].size();
	int n2 = p2.pattern.size();
	int m2 = p2.pattern[0].size();
	if(n1 == n2 && m1 == m2){
		if(match_rot(p1.pattern,p2.pattern,0) || match_rot(p1.pattern,p2.pattern,2))
			return true;
	}
	if(n1 == m2 && m1 == n2){
		if(match_rot(p1.pattern,p2.pattern,1) || match_rot(p1.pattern,p2.pattern,3))
			return true;
	}
	return false;
}


int main(){
	ifstream fin("starry.in");
	ofstream fout("starry.out");
	fin >> W>>H;
	vii M(H, vi(W, 0));
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			char c;
			fin.get(c);
			if(c == '\n') fin.get(c);
			M[i][j] = c-'0';
		}
	}
	vector<vector<bool>> visited(H, vector<bool>(W,false));
	vector<pair<int,int>> pattern_starts;
	vector<vector<int>> num(H, vi(W,0));
	vector<pattern> patterns;
	
	for(int i=0; i<H;i++){
		for(int j=0; j<W;j++){
			if(!visited[i][j] && M[i][j] == 1){
				int left=j,right=j,top=i,bottom=i;
				auto start=make_pair(i,j);
				pattern_starts.push_back(start);
				vector<pair<int,int>> pattern_points{start};
				pattern pat;
				pat.start = start;
				queue<pair<int,int>> q;
				q.push(make_pair(i,j));
				visited[i][j] = true;
				while(!q.empty()){
					pair<int,int> v=q.front();
					q.pop();
					for(auto w : neighbors(v)){
						if(M[w.first][w.second] == 1 && !visited[w.first][w.second]){
							left = min(left, w.second);
							right = max(right, w.second);
							top = min(top, w.first);
							bottom = max(bottom, w.first);
							pattern_points.push_back(w);
							visited[w.first][w.second] = true;
							q.push(w);
						}
					}
				}
				pat.count = pattern_points.size();
				pat.pattern = vector<vector<bool>>(bottom-top+1, vector<bool>(right-left+1, 0));
				for(auto p : pattern_points){
					pat.pattern[p.first-top][p.second-left] = true;
				}
				pat.top = top;
				pat.left = left;
				pat.letter = -1;
				patterns.push_back(pat);
			}

		}
	}
	int next_letter=0;
	vii ans(H, vi(W, '0'-'a'));
	for(int i=0; i<patterns.size();i++){
		int letter=next_letter;
		patterns[i].letter = letter;
		for(int j=0;j<i;j++){
			if(pattern_match(patterns[i], patterns[j])){
				letter = patterns[j].letter;
				patterns[i].letter = letter; 
			}
		}
		if(letter == next_letter)
			next_letter++;

		for(int t=0; t<patterns[i].pattern.size(); t++){
			for(int l=0; l<patterns[i].pattern[0].size(); l++){
				if(patterns[i].pattern[t][l]){
					ans[t+patterns[i].top][l+patterns[i].left] = letter;
				}
			}
		}
		
	}
	for(int i=0; i<H;i++){
		for(int j=0; j<W;j++)
			fout << (char)(ans[i][j]+'a');
		fout << endl;



	}
	return 0;
}