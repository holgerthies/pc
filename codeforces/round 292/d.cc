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

int nn(vector<vector<char>>& g, int i, int j){
	return (i > 0 && g[i-1][j] == '.')+(i+1<len(g) && g[i+1][j] == '.') + 
			(j > 0 && g[i][j-1] == '.')+(j+1<len(g[0]) && g[i][j+1] == '.');
}

pii gn(vector<vector<char>>& g, int i, int j){
	if(i > 0 && g[i-1][j] == '.')
		return mp(i-1, j);
	if(i+1<len(g) && g[i+1][j] == '.')
		return mp(i+1, j);
	if(j > 0 && g[i][j-1] == '.')
		return mp(i,j-1);
	return mp(i, j+1);
}

bool cand(vector<vector<char>>& g, int i, int j){
	return i >= 0 && j >= 0 && i < len(g) && j < len(g[0]) && g[i][j] == '.' && nn(g,i,j)==1;
}
int main(){
	int n,m;
	cin >> n >> m;
	vector<vector<char>> g(n, vector<char>(m));
	REP(i, n){
		string x;
		cin >> x;
		REP(j, m){
			g[i][j] = x[j];
		}
	}
	queue<pii> q;
	REP(i,n){
		REP(j,m){
			if(cand(g, i,j)){
				q.push(mp(i,j));
			}
		}
	}
	while(!q.empty()){
		int i,j;
		tie(i,j) = q.front();
		q.pop();
		if(g[i][j] == '.'){
			//cout << i << " "<<j<<endl;
			int ni, nj;
			tie(ni,nj) = gn(g,i,j);
			if(g[ni][nj] != '.') continue;
			if(i == ni){
				g[i][min(j,nj)] = '<'; 
				g[i][max(j,nj)] = '>'; 
			} else{
				g[min(i,ni)][j] = '^';
				g[max(i,ni)][j] = 'v';
			}
			for(int k=-1; k<=1;k++){
				if(cand(g, i+k,j))
					q.push(mp(i+k,j));
				if(cand(g, ni+k,nj))
					q.push(mp(ni+k,nj));
				if(cand(g, i,j+k))
					q.push(mp(i,j+k));
				if(cand(g, ni,nj+k))
					q.push(mp(ni,nj+k));
			}
		}		
	}
	bool valid=true;
	REP(i, n){
		if(!valid) break;
		REP(j,m){
			if(g[i][j] == '.'){
				valid=false;
				break;
			}
		}
	}

	if(valid){
		REP(i,n){
			REP(j,m){
				cout << g[i][j];
			}
			cout << endl;
		}
	} else {
		cout << "Not unique" << endl;
	}

	return 0;
}