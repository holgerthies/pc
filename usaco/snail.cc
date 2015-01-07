/*
ID: holger1
PROG: snail
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
#include <complex>

#define FOR(k,a,b) for(typeof(a) k=(a); k <= (b); ++k)
#define REP(k,a) for(int k=0; k < (a); ++k)
#define INF 200000000
using namespace std;
using vi=vector<int>;
using vii=vector<vector<int>>;

pair<int,int> next(int x, int y, int dir){
	switch(dir){
		case 0:
			return make_pair(x, y-1);
		case 1:
			return make_pair(x+1, y);
		case 2:
			return make_pair(x,y+1);
		case 3:
			return make_pair(x-1,y);
	}
}

bool free(int x, int y, int N,vector<vector<bool>>& box){
	return x>=0 && y>=0 && x < N && y < N && !box[x][y];
}

vector<tuple<int,int,int>> possible_next(int x, int y, int dir, int N, vector<vector<bool>>& visited, vector<vector<bool>>& box){
	vector<tuple<int,int,int>> ans;
	if(dir == 0 || dir == 2){
		auto n1 = next(x,y,1);
		auto n2 = next(x,y,3);
		if(free(n1.first, n1.second, N, box) && !visited[n1.first][n1.second]){
			ans.push_back(make_tuple(n1.first, n1.second, 1));
		}
		if(free(n2.first, n2.second, N, box) && !visited[n2.first][n2.second]){
			ans.push_back(make_tuple(n2.first, n2.second, 3));
		}
	}
	if(dir == 1 || dir == 3){
		auto n1 = next(x,y,0);
		auto n2 = next(x,y,2);
		if(free(n1.first, n1.second, N, box) && !visited[n1.first][n1.second]){
			ans.push_back(make_tuple(n1.first, n1.second, 0));
		}
		if(free(n2.first, n2.second, N, box) && !visited[n2.first][n2.second]){
			ans.push_back(make_tuple(n2.first, n2.second, 2));
		}
	}
	return ans;
}
int backtrack(int x, int y, int dir, int N, vector<vector<bool>>& visited, vector<vector<bool>>& box){
//	cout << x <<" "<<y<<endl;
	auto n = next(x,y,dir);
	int nx=n.first, ny=n.second;
	if(free(nx,ny,N,box)){
		if(visited[nx][ny]) return 1;
		visited[nx][ny] = true;
		int ans = backtrack(nx,ny,dir, N, visited, box);
		visited[nx][ny] = false;
		return ans+1;
	} else{
		auto ps = possible_next(x,y,dir,N, visited, box);
		int ans = 1;
		for(auto p : ps){
			int nx = get<0>(p), ny=get<1>(p), nd=get<2>(p);
			visited[nx][ny] = true;
			ans = max(ans, 1+backtrack(nx,ny,nd, N, visited, box));
			visited[nx][ny] = false;
		}
		return ans;
	}
}

int main(){
	ifstream fin("snail.in");
	ofstream fout("snail.out");
	int N, B;
	fin >> N >> B;
	vector<vector<bool>> box(N, vector<bool>(N));
	for(int i=0; i<B;i++){
		string in;
		fin >> in;
		int x = in[0]-'A';
		int y = 0;
		for(int j=1; j<in.size(); j++){
			y = 10*y+(in[j]-'0');
		}
		box[x][y-1] = true;
	}
	int ans=0;
	for(int i=0; i<4; i++){
		vector<vector<bool>> visited(N, vector<bool>(N, false));
		visited[0][0] = true;
		ans = max(ans, backtrack(0,0,i,N,visited, box));
	}
	fout << ans<<endl;
	return 0;
}