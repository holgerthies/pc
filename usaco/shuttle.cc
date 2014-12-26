/*
ID: holger1
PROG: shuttle
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


void print(const vector<char>& v){
	for(char c : v)
		cout << c;
	cout <<endl;
}
/*
vector<state> neighbors(state S){
	vector<state> ans;
	int N = S.N;
	if(S.hole > 1){
		state n(S);
		swap(n.marbles[n.hole], n.marbles[n.hole-2]);
		n.hole -= 2;

		ans.push_back(n);
	}	
	if(S.hole != 0){
		state n(S);
		swap(n.marbles[n.hole], n.marbles[n.hole-1]);
		n.hole = n.hole-1;

		ans.push_back(n);
	}	
	if(S.hole < 2*N){
		state n(S);
		swap(n.marbles[n.hole], n.marbles[n.hole+1]);
		n.hole++;

		ans.push_back(n);
	}
	if(S.hole < 2*N-1){
		state n(S);
		swap(n.marbles[n.hole], n.marbles[n.hole+2]);
		n.hole+=2;

		ans.push_back(n);
	}
	return ans;
}*/

vector<string> neighbors(string& s){
	vector<string> ans(4,"");
	int N=(s.size()-1)/2;
	int p = s.find(' ');
	if(p > 1){// && (s[p-2]=='W' && p>=N || p<=N)){
		swap(s[p],s[p-2]);
		ans[0] = s;
		swap(s[p],s[p-2]);
	}
	if(p > 0){// && (s[p-1]=='W' && p>=N || p<=N)){
		swap(s[p],s[p-1]);
		ans[1] = s;
		swap(s[p],s[p-1]);

	}
	if( p < s.size()-1){// && (s[p+1]=='B' && p<=N || p>=N)){
		swap(s[p],s[p+1]);
		ans[2] = s;
		swap(s[p],s[p+1]);

	}
	if(p < s.size()-2){// && (s[p+2]=='B' && p<=N || p>=N)){
		swap(s[p],s[p+2]);
		ans[3] = s;
		swap(s[p],s[p+2]);
	}
	return ans;
}

vector<string> bfs(const string start, const string goal,unordered_map<string, int>& move ){
	unordered_set<string> visited;
	unordered_map<string, string> parent;
	queue<string> q;
	q.push(start);
	visited.insert(start);
	bool found=false;
	while(!q.empty() && !found){
		string v=q.front();
		q.pop();
		vector<string> nbs=neighbors(v);
		for(int i=0; i<nbs.size();i++){
			string w = nbs[i];
			if(w == "") continue;
			if(visited.find(w) == visited.end()){
				visited.insert(w);
				parent[w] = v;
				move[w] = i;
				if(w == goal){
					found = true;
					break;
				}
				q.push(w);

			}
		}
	}
	if(found){
		vector<string> ans;
		string curr=goal;
		while(curr != start){
			ans.push_back(curr);
			curr=parent[curr];
		}
		ans.push_back(start);
		reverse(ans.begin(), ans.end());
		return ans;	
	}
	return vector<string>();
}


vector<int> restore(vector<int> moves, int p){
	vector<int> ans;
	for(int m : moves){
		if(m == 0){
			p-=2;
		}
		if(m == 1){
			p -= 1;
		}
		if(m == 2)
			p += 1;
		if(m==3) 
			p += 2;
		ans.push_back(p);
	}
	return ans;
}

unordered_set<string> visited;
unordered_map<string, string> parent;
// bool dfs(string start, const string goal, const int max_depth){
// 	//cout << start<<endl;
// 	if(start == goal){
// 		return true;
// 	}
// 	if(max_depth == 0) return false;
// 	vector<string> nbs=neighbors(start);
// 	for(int i=0; i<nbs.size(); i++){
// 		string w=nbs[i];
// 		//cout << i<<" "<<w<<endl;
// 		parent[w] = start;
// 		if(dfs(w, goal, max_depth-1))
// 			return true;
// 	}
// 	//visited.insert(start);
// 	return false;
// }
int main(){
	ifstream fin("shuttle.in");
	ofstream fout("shuttle.out");
	int N;
	fin >> N;
	vector<char> marbles(2*N+1, ' ');
	vector<char> goal_marbles(2*N+1, ' ');
	vector<int> steps_fh;
	for(int i=0; i<N;i++){
		marbles[i] = 'W';
		marbles[N+1+i] = 'B';
		goal_marbles[i] = 'B';
		goal_marbles[N+1+i] = 'W';
	}
	string start,goal;
	start.resize(2*N+1);
	goal.resize(2*N+1);

	for(int i=0; i<N/2; i++){
		steps_fh.push_back(1);
		for(int j=0;j<2*i+1;j++)
			steps_fh.push_back(3);
		steps_fh.push_back(2);
		for(int j=0;j<2*i+2;j++){
			steps_fh.push_back(0);
		}
	}
	vector<int> steps(steps_fh);
	steps.resize((N+1)*(N+1)-1);
	copy(steps_fh.begin(), steps_fh.end(), steps.rbegin());
	if(N % 2 == 1){
		int start=steps_fh.size();
		steps[start] = 1;
		for(int i=1; i<=N;i++)
			steps[start+i] = 3;
		steps[start+N+1] = 1;
	}
	vector<int> moves=restore(steps, N+1);
	fout << moves[0];

	for(int i = 1; i<moves.size();i++){
		if(i % 20 == 0)
			fout << endl;
		else
			fout << " ";
		fout << moves[i];
	}
	fout << endl;
	return 0;
}