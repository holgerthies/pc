/*
ID: holger1
PROG: maze1
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
#include <queue>

using namespace std;

vector<pair<int,int>> neighbors(int y, int x, int W, int H, char maze[201][80]){
	vector<pair<int,int>> ans;
	if(y>0 && maze[y-1][x] == ' '){
		ans.push_back(make_pair(y-1,x));
	}
	if(x>0 && maze[y][x-1] == ' ')
		ans.push_back(make_pair(y,x-1));
	if(x < 2*W && maze[y][x+1] == ' ')
		ans.push_back(make_pair(y,x+1));
	if(y < 2*H && maze[y+1][x] == ' ')
		ans.push_back(make_pair(y+1,x));
	return ans;
}

void bfs(char maze[201][80], int y, int x, int W, int H, int dist[201][80]){
	bool visited[201][80] = {false};
	visited[y][x] = true;
	//int dist[201][80] = {-1};
	dist[y][x] = 0;
	queue<pair<int,int>> Q;
	Q.push(make_pair(y,x));
	while(!Q.empty()){
		pair<int,int> v = Q.front();
		Q.pop();
		for(auto w : neighbors(v.first,v.second,W,H,maze)){
			if(!visited[w.first][w.second]){
				Q.push(w);
				visited[w.first][w.second] = true;
				dist[w.first][w.second] = dist[v.first][v.second]+1;
			}
		}
	}
}
int main(){
	ifstream fin("maze1.in");
	ofstream fout("maze1.out");
	int W,H;
	fin >> W >> H;
	char maze[201][80]; 
	for(int i=0;i<=2*H;i++){
		for(int j=0;j<=2*W;j++){
			fin.get(maze[i][j]);
			if(maze[i][j] == '\n')
				fin.get(maze[i][j]);
		}
	}


	int y1,x1,y2,x2;
	bool first_set=false;
	for(int i=0;i<=2*W;i++){
		int y,x;
		if(maze[0][i] == ' '){
			y=0;
			x=i;
			if(first_set){
				y2=y;x2=x;
				break;
			} else{
				y1=y;x1=x;
				first_set=true;
			}
		}
		if(maze[2*H][i] == ' '){
			y=2*H;
			x=i;
			if(first_set){
				y2=y;x2=x;
				break;
			} else{
				y1=y;x1=x;
				first_set=true;
			}
		}
	}

	for(int i=0;i<=2*H;i++){

		int y,x;
		if(maze[i][0] == ' '){
			y=i;
			x=0;
			if(first_set){

				y2=y;x2=x;
				break;
			} else{
				y1=y;x1=x;
				first_set=true;
			}
		}
		if(maze[i][2*W] == ' '){
			x=2*W;
			y=i;
			if(first_set){

				y2=y;x2=x;
				break;
			} else{
				y1=y;x1=x;
				first_set=true;
			}
		}
	}

	int dist[201][80] ={-1};
	int max_dist=-1;
	bfs(maze, y1,x1, W, H, dist);
	int dist2[201][80] ={-1};
	bfs(maze, y2,x2, W, H, dist2);
	for(int i=0;i<=2*H;i++){
		for(int j=0;j<=2*W;j++){
			dist[i][j] = min(dist[i][j], dist2[i][j]);
		}
	}
	for(int i=0;i<=2*H;i++){
		for(int j=0;j<=2*W;j++){
			max_dist = max(max_dist, dist[i][j]);
		}
	}
	fout << (max_dist+1)/2 << endl;
}