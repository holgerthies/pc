/*
ID: holger1
PROG: ttwo
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

using namespace std;


bool occupied(int i, int j, char board[10][10]){
	return (i<0 || i>=10 || j<0 || j>=10 || board[i][j] == '*');
}

void move(int i, int j, int d, int& next_i, int& next_j){
	switch(d){
		case 0:
			next_i = i-1;
			next_j = j;
			break;
		case 1:
			next_i = i;
			next_j = j+1;
			break;
		case 2:
			next_i = i+1;
			next_j = j;
			break;
		case 3:
			next_i = i;
			next_j = j-1; 
			break;
	}
}

int main(){
	struct state {
		int fx,fy,cx,cy,fdir,cdir;
	} S;
	ifstream fin("ttwo.in");
	ofstream fout("ttwo.out");
	char board[10][10];
	int fy,fx,cy,cx;
	bool visited[10][10][10][10][4][4] = {false};
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			fin >> board[i][j];
			if(board[i][j] == 'F'){
				S.fy = i;
				S.fx = j;
				S.fdir=0;
				board[i][j] = '.';
			}
			if(board[i][j] == 'C'){
				S.cy = i;
				S.cx = j;
				S.cdir=0;
				board[i][j] = '.';
			}
		}
	}
	int steps=0;
	while(true){
		visited[S.fy][S.fx][S.cy][S.cx][S.fdir][S.cdir] = true;
		steps++;
		state next_S;
		next_S.fdir=S.fdir;
		next_S.cdir=S.cdir;
		move(S.fy, S.fx, S.fdir, next_S.fy, next_S.fx);

		if(occupied(next_S.fy,next_S.fx, board)){
			next_S.fy = S.fy;
			next_S.fx = S.fx;
			next_S.fdir += 1;
			next_S.fdir %= 4;
		}
		move(S.cy, S.cx, S.cdir, next_S.cy, next_S.cx);
		if(occupied(next_S.cy,next_S.cx, board)){
			next_S.cy = S.cy;
			next_S.cx = S.cx;
			next_S.cdir += 1;
			next_S.cdir %= 4;
		}		
		S=next_S;
		if(S.cy == S.fy && S.cx == S.fx){
			fout << steps << endl;
			break;
		}
		if(visited[S.fy][S.fx][S.cy][S.cx][S.fdir][S.cdir]){
			fout << 0 <<endl;
			break;
		}
	}
	return 0;
}