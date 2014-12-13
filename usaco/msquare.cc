/*
ID: holger1
PROG: msquare
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <stack>
#include <algorithm>
#include <limits>
#include <unordered_set>

using namespace std;

struct node{
	int row1[4];
	int row2[4];
	char transform;
};

node copy(const node& v){
	node n;
	for(int i=0;i<4;i++){
		n.row1[i] = v.row1[i];
		n.row2[i] = v.row2[i];
	}
	return n;
}

node transformA(const node& v){
	node n=copy(v);
	for(int i=0; i<4;i++){
		n.row1[i] = v.row2[i];
		n.row2[i] = v.row1[i];
	}
	return n;
}

node transformB(const node& v){
	node n=copy(v);
	for(int i=0;i<4;i++){
		n.row1[i] = v.row1[(4+i-1)%4];
		n.row2[i] = v.row2[(4+i-1)%4];
	}
	return n;
}


node transformC(const node& v){
	node n=copy(v);
	int temp1 = n.row1[1];
	int temp2 = n.row1[2];
	n.row1[1] = n.row2[1];
	n.row2[1] = n.row2[2];
	n.row1[2] = temp1;
	n.row2[2] = temp2;
	return n;
}

int representation(const node& n){
	int result=0;
	for(int i=0;i<4;i++){
		result *= 10;
		result += n.row1[i];
		result *= 10;
		result += n.row2[i];
	}
	return result;
}

string bfs(const node& startNode, int goal){
	queue<node> Q;
	unordered_set<int> visited;
	Q.push(startNode);
	map<int, int> parent;
	map<int, char> transform;
	while(!Q.empty()){
		node v = Q.front();
		Q.pop();
		if(representation(v) == goal){
			string ans = "";
			int curr = representation(v);
			while(curr != representation(startNode)){
				ans = transform[curr]+ans;
				curr = parent[curr];
			}
			return ans;
		}
		visited.insert(representation(v));
		node n1=transformA(v);
		if(visited.find(representation(n1)) == visited.end()){
			visited.insert(representation(n1));
			transform[representation(n1)] = 'A';
			parent[representation(n1)] = representation(v);
			Q.push(n1);
		}
		node n2=transformB(v);
		if(visited.find(representation(n2)) == visited.end()){
			visited.insert(representation(n2));
			transform[representation(n2)] = 'B';
			parent[representation(n2)] = representation(v);
			Q.push(n2);

		}
		node n3=transformC(v);
		if(visited.find(representation(n3)) == visited.end()){
			visited.insert(representation(n3));
			transform[representation(n3)] = 'C';
			parent[representation(n3)] = representation(v);
			Q.push(n3);
		}
	}
}

int main(){
	ifstream fin("msquare.in");
	ofstream fout("msquare.out");
	node start;
	for(int i=0;i<4;i++){
		start.row1[i] = i+1;
		start.row2[i] = 8-i;
	}
	node goal;
	for(int i=0;i<4;i++){
		fin >> goal.row1[i];
	}
	for(int i=0;i<4;i++){
		fin >> goal.row2[3-i];
	}
	string ans= bfs(start, representation(goal));
	fout << ans.length() << endl;
	for(int i=0; i<ans.length(); i++){
		if(i>0 && i % 60 == 0)
			fout << endl;
		fout << ans[i];
	}
	fout << endl;
}