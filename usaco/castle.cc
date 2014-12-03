/*
ID: holger1
PROG: castle
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


struct tile {
	bool n, e, s, w;
	int component;
	vector<tile*> neighbors;
};
int M,N;


int bfs(tile* start, int component){
	start->component = component;
	queue<tile*> q;
	q.push(start);
	int size=1;
	while(!q.empty()){
		tile* v = q.front();
		q.pop();
		for(tile* w : v->neighbors){
			if(w->component == -1){
				w->component = component;
				q.push(w);
				size++;
			}
		}
	}
	return size;
}

vector<int> get_component_size(tile floorplan[50][50]){
	vector<int> components;
	int n=0;
	for(int i=0; i<M;i++){
		for(int j=0; j<N;j++){
			if(floorplan[i][j].component == -1){
				n++;
				int size=bfs(&floorplan[i][j], n);
				components.push_back(size);
			}
		}
	}
	return components;
}

int main(){
	ifstream fin("castle.in");
	ofstream fout("castle.out");

	fin >> N >> M;
	tile floorplan[50][50];
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			int x;
			fin >> x;
			tile t;
			t.w = x & 1;
			t.n = x & 2;
			t.e = x & 4;
			t.s = x & 8; 
			t.component = -1;
			t.neighbors = vector<tile*>();
			floorplan[i][j] = t;
		}
	}
	for(int i=0;i<M;i++){
		for(int j=0; j<N;j++){
			tile& t = floorplan[i][j];
			if(!t.n && i>0){
				t.neighbors.push_back(&floorplan[i-1][j]);
			}
			if(!t.w && j>0){
				t.neighbors.push_back(&floorplan[i][j-1]);
			}	
			if(!t.s && i<M-1){
				t.neighbors.push_back(&floorplan[i+1][j]);
			}
			if(!t.e && j<N-1){
				t.neighbors.push_back(&floorplan[i][j+1]);
			}
		}
	}
	vector<int> sizes=get_component_size(floorplan);
	fout << sizes.size() << endl;
	fout << *max_element(sizes.begin(), sizes.end()) << endl;
	int max_remove=0, max_x=0,max_y=0;
	char direction;
	for(int j=0; j<N;j++){
		for(int i=M-1;i>=0; i--){
			if(i > 0 && floorplan[i][j].n){
				int c1 = floorplan[i][j].component, c2=floorplan[i-1][j].component;
				if(c1 != c2){
					int r = sizes[c1-1]+sizes[c2-1];
					if(r > max_remove){
						max_remove = r;
						max_x=j;
						max_y=i;
						direction = 'N';
					}

				}
			}
			if(j < N-1 && floorplan[i][j].e){
				int c1 = floorplan[i][j].component, c2=floorplan[i][j+1].component;
				if(c1 != c2){
					int r = sizes[c1-1]+sizes[c2-1];
					if(r > max_remove){
						max_remove = r;
						max_x=j;
						max_y=i;
						direction = 'E';
					}

				}
			}
		}
	}
	fout << max_remove << endl;
	fout << max_y+1 << " " << max_x+1 << " " << direction << endl;
}