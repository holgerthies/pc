/*
ID: holger1
PROG: camelot
LANG: C++11
*/
#define INF 2000000
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
#define MAXN 10000
#define MAXR 31
#define MAXC 27

using namespace std;
int kx, ky;
int king_dist(int y,int x){
	return max(abs(x-kx), abs(y-ky));
}


struct MinHeap{
	using T = tuple<int,int,int>;
	int elements[MAXN][3];
	int cost[MAXR][MAXC][2];
	int position[MAXR][MAXC][2];
	int size=0;

	int get_cost(int n){
		auto element = elements[n];
		return cost[elements[n][0]][elements[n][1]][elements[n][2]];
	}
	void swap_pos(int n1, int n2){
		swap(elements[n1][0], elements[n2][0]);
		swap(elements[n1][1], elements[n2][1]);
		swap(elements[n1][2], elements[n2][2]);

		int r1=elements[n1][0], c1=elements[n1][1], k1=elements[n1][2];
		int r2=elements[n2][0], c2=elements[n2][1], k2=elements[n2][2];
		int temp = position[r1][c1][k1];
		position[r1][c1][k1] = position[r2][c2][k2];
		position[r2][c2][k2] = temp;
	}
	
	void downHeap(int n){
		int left=2*n+1, right=2*n+2;
		int min_element=n;
		if(left < size && get_cost(left)<get_cost(min_element))
			min_element = left;
		if(right < size && get_cost(right) < get_cost(min_element))
			min_element = right;
		if(min_element != n){
			swap_pos(n, min_element);
			downHeap(min_element);
		}
	}

	void upHeap(int n){
		if(n==0) return;
		int parent = (n-1)/2;
		if(get_cost(parent) > get_cost(n)){
			swap_pos(n, parent);
			upHeap(parent);
		}
	}

	void insert(int row, int col, int k, int c){
		elements[size][0] = row;
		elements[size][1] = col;
		elements[size][2] = k;
		cost[row][col][k] = c;
		position[row][col][k] = size;
		upHeap(size);
		++size;
	}

	void pop(int& row, int& col, int& k){
		row = elements[0][0];
		col = elements[0][1];
		k = elements[0][2];
		for(int i=0;i<3;i++)
			elements[0][i] = elements[size-1][i];
		position[elements[0][0]][elements[0][1]][elements[0][2]] = 0;
		downHeap(0);
		size--;
	}

	void update(int row, int col, int k, int c){
		int old_cost = cost[row][col][k];
		cost[row][col][k] = c;
		int index=position[row][col][k];
		if(old_cost < c){
			downHeap(index);
		}
		if(old_cost > c){
			upHeap(index);
		}
	}
};

void dijkstra(const vector<pair<int,int>> adj[MAXR][MAXC], const int start_row, const int start_col, int dist[MAXR][MAXC][2]){
	MinHeap Q;
	bool in_list[MAXR][MAXC][2];
	for(int i=0;i<MAXR;i++){
		for(int j=0;j<MAXC;j++){
			dist[i][j][0] = INF;
			dist[i][j][1] = INF;
			in_list[i][j][1]=false;
			in_list[i][j][0]=false;
		}
	}
	Q.insert(start_row, start_col, 0,0);
	dist[start_row][start_col][0] = 0;
	in_list[start_row][start_col][0] = true;
	int count=0;
	while(Q.size){
		int vr,vc, has_king;
		Q.pop(vr,vc,has_king);
		//cout << vr <<", "<<vc<<", "<< has_king<<endl;
		for(auto w : adj[vr][vc]){
			int wr=w.first, wc=w.second;
			if(!in_list[wr][wc][has_king]){
				dist[wr][wc][has_king] = dist[vr][vc][has_king]+1;
				Q.insert(wr,wc,has_king, dist[wr][wc][has_king]);
				in_list[wr][wc][has_king]=true;
			}
			else {
				if(dist[vr][vc][has_king] + 1 < dist[wr][wc][has_king]){
					dist[wr][wc][has_king] = dist[vr][vc][has_king] + 1;
					Q.update(wr,wc,has_king, dist[wr][wc][has_king]);
				}
			}
		}
		if(!has_king){
			if(!in_list[vr][vc][1]){
				dist[vr][vc][1] = dist[vr][vc][0]+king_dist(vr,vc);
				in_list[vr][vc][1] = true;
				Q.insert(vr,vc,1, dist[vr][vc][1]);
			}
			else{
				if(dist[vr][vc][0] + king_dist(vr,vc) < dist[vr][vc][1]){
					 dist[vr][vc][1] = dist[vr][vc][0] + king_dist(vr,vc);
					 Q.update(vr,vc,1, dist[vr][vc][1]);
				}
			}
		}
	}
}

int main(){
	ifstream fin("camelot.in");
	ofstream fout("camelot.out");
	int board[31][27];
	int dist[MAXR][MAXC][MAXR][MAXC][2];

	int R,C;
	fin >> R >> C;
	for(int i=0; i<R; i++)
		for(int j=0; j<C;j++)
			board[i][j] = 0;
	char kcc; int kr;
	fin >> kcc >> kr;
	int kc=int(kcc-'A');
	kr--;
	kx = kc;
	ky = kr;
	char c;
	int r;
	while(fin >> c >> r){
			int ci = c;
			ci -= int('A');
			board[r-1][ci]++;
	}
	vector<pair<int,int>> adj[MAXR][MAXC];

	for(int i0=0; i0<R;i0++){
		for(int j0=0; j0<C; j0++){
			for(int i1=0; i1<R;i1++){
				for(int j1=0; j1<C; j1++){
					if(abs(i0-i1) == 1 && abs(j0-j1) == 2 || abs(i0-i1) == 2 && abs(j0-j1) == 1){
						adj[i0][j0].push_back(make_pair(i1,j1));
					}
				}
			}
		}
	}
	
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			dijkstra(adj, i,j,dist[i][j]);
		}
	}

	int min_dist = INF;
	int total_dist[MAXR][MAXC];
	for(int i=0; i<R;i++){
		for(int j=0; j<C;j++){
			int d=0;
			for(int y=0; y<R; y++){
				for(int x=0;x<C;x++){					
					d += board[y][x]*dist[i][j][y][x][0];
				}			
			}
			total_dist[i][j] = d;
		}
	}
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			int min_king_dist=INF;
			for(int y=0;y<R;y++){
				for(int x=0;x<R;x++){
					if(board[y][x] > 0){
						min_king_dist = min(min_king_dist, dist[i][j][y][x][1]-dist[i][j][y][x][0]);
					}
				}
			}
			total_dist[i][j] = total_dist[i][j]+min(min_king_dist, king_dist(i,j));
			min_dist=min(min_dist, total_dist[i][j]);
		}
	}

	fout << min_dist<<endl;
	return 0;
}