/*
ID: holger1
PROG: schlnet
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
#define INF 200000000
#define mp make_pair
#define len(s) (int)((s).size())
using namespace std;
typedef long long ll;
typedef unsigned int uint;
using vi = vector<int>;
using vii = vector<vector<int>>;
using pii = pair<int,int>;

struct node{
	int id;
	bool visited;
	int component;
	vector<node*> neighbors;
	node(int id) : id(id), visited(false), component(-1), neighbors(vector<node*>()) {}
};


void dfs(node* v, stack<int>& S){
	if(!v->visited){
		v->visited = true;
		for(node* w : v->neighbors){
			dfs(w, S);
		}
		S.push(v->id);
	}
}

bool set_component(node* v, int c, vector<int>& component){
	if(component[v->id] == -1){
		component[v->id] = c;
		for(node* w : v->neighbors){
			set_component(w,c, component);
		}
		return true;
	}
	return false;
}


vector<node*> get_transposed(vector<node*> G){
	vector<node*> ans(G.size());
	REP(i,len(G)) ans[i] = new node(i);
	for(node* v : G){
		for(node* w : v->neighbors){
			ans[w->id]->neighbors.push_back(ans[v->id]); 
		}
	}
	return ans;
}

int ssc(vector<node*> G, vector<int>& component){
	stack<int> S;
	for(node* v : G){
		if(!v->visited){
			dfs(v, S);
		}
	}
	int c=0;
	vector<node*> Gt = get_transposed(G);
	while(!S.empty()){
		int i=S.top();
		S.pop();
		if(set_component(Gt[i],c, component)){
			c++;
		}
	}
	return c;
}


int main(){
	ifstream fin("schlnet.in");
	ofstream fout("schlnet.out");
	int N;
	fin >> N;
	vector<node*> G(N);
	for(int i=0;i<N;i++)
		G[i] = new node(i);
	for(int i=0;i<N;i++){
		while(true){
			int w;
			fin >> w;
			if(w==0) break;
			w--;
			G[i]->neighbors.push_back(G[w]);
		}
	}
	vector<int> component(N,-1);
	int num_components = ssc(G, component);
	vector<int> in_degree(num_components, 0);
	vector<int> out_degree(num_components, 0);

	for(node* v : G){
		//cout<<v->id<<" "<<component[v->id]<<endl;
		for(node* w : v->neighbors){
			if(component[v->id] != component[w->id]){
				in_degree[component[w->id]]++;
				out_degree[component[v->id]]++;
			}
		}
	}
	int ans1=0;
	int ans2=0;
	for(int i=0;i<num_components;i++){
		//cout<<i<<" "<<in_degree[i]<<endl;
		if(in_degree[i] == 0)
			ans1++;
		if(out_degree[i] == 0)
			ans2++;
	}

	fout<<ans1<<endl;
	if(num_components == 1)
		fout<<0<<endl;
	else
		fout<<max(ans1,ans2)<<endl;

	return 0;
}