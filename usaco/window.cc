/*
ID: holger1
PROG: window
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

struct window{
	int x;
	int y;
	int X;
	int Y;
	bool deleted;
	char id;
	window* next;
	window* prev;
};

struct rectangle{
	int x;
	int y;
	int X;
	int Y;
};



struct screen{
	window* first;
	window* last;
};

void print(screen& s){
	window* w=s.first;
	int count=0;
	while(w != nullptr && ++count<20){
		cout<<w->id<<" ";
		w = w->next;
	}
	cout<<endl;
}

bool line_intersects(const int x1, const int x2, const int y1, const int y2){
	int start = max(x1,y1);
	int end = min(x2,y2);
	return end>start;
}

bool intersects(const rectangle& r1, const rectangle& r2){
	return (line_intersects(r1.x, r1.X, r2.x, r2.X) && line_intersects(r1.y,r1.Y, r2.y,r2.Y));

}

tuple<rectangle,rectangle,rectangle,rectangle> non_intersecting(const rectangle& r1, const rectangle& r2){
	rectangle top, left, right,bottom;
	top.x = r1.x;
	top.X = r1.X;
	top.y = r1.y;
	top.Y = min(r1.Y, r2.y);
	bottom.x = r1.x;
	bottom.X = r1.X;
	bottom.y = max(r1.y, r2.Y);
	bottom.Y = r1.Y;
	left.x = r1.x;
	left.X = min(r2.x,r1.X);
	left.y = max(r2.y,r1.y);
	left.Y = min(r2.Y, r1.Y);
	right.x = max(r1.x, r2.X);
	right.X = r1.X;
	right.y = max(r2.y,r1.y);
	right.Y = min(r2.Y, r1.Y);
	return make_tuple(top,right,bottom,left);
}

bool valid(const rectangle& r){
	return r.x<r.X && r.y<r.Y;
}

void print(vector<rectangle>& rects){
	if(!rects.empty()){
		int x=rects[0].x,X=rects[0].X,y=rects[0].y,Y=rects[0].Y;
		for(auto r : rects){
			x=min(r.x,x);
			X=max(r.X,X);
			y=min(r.y,y);
			Y=max(r.Y,Y);
		}
		vector<vector<bool>> F(X-x, vector<bool>(Y-y,false));
		for(auto r : rects){
			for(int i=r.x;i<r.X;i++){
				for(int j=r.y;j<r.Y;j++){
					F[i][j] = true;
				}
			}
		}
		for(auto f : F){
			for(bool b : f){
				if(b) cout<<"*";
				else cout<<" ";
			}
			cout<<endl;
		}
	}

}
void insert_rect(const rectangle& r, vector<rectangle>& rects){
	bool has_intersection = false;
	for(rectangle r2 : rects){
		if(intersects(r2,r)){
			has_intersection = true;
			auto c = non_intersecting(r,r2);
			rectangle top = get<0>(c), right = get<1>(c), bottom = get<2>(c), left= get<3>(c);
			//cout<<"r1:"<<r.x<<" "<<r.X<<" "<<r.y<<" "<<r.Y<<endl;
			//cout<<"r2:"<<r2.x<<" "<<r2.X<<" "<<r2.y<<" "<<r2.Y<<endl;

			//cout<<right.x<<" "<<right.X<<endl;
			if(valid(left))
				insert_rect(left, rects);
			if(valid(right))
				insert_rect(right, rects);
			if(valid(top))
				insert_rect(top, rects);
			if(valid(bottom))
				insert_rect(bottom, rects);
			break;
		}
	}
	if(!has_intersection){
		rects.push_back(r);
	}
}

void push_back(screen& s, window* w){
	if(s.first == nullptr){
		s.first = s.last= w;
		w->next=nullptr;
		w->prev=nullptr;
	}else{
		w->next = nullptr;
		w->prev = s.last;
		s.last->next = w;
		s.last = w;

	}
}

void push_front(screen& s, window* w){
	if(s.first == nullptr){
		s.first = s.last= w;
		w->next=nullptr;
		w->prev=nullptr;
	}else{
		s.first->prev = w;
		w->next = s.first;
		s.first = w;
		w->prev = nullptr;

	}
}

long long area(const rectangle& r){
	return (long long)(r.X-r.x)*(r.Y-r.y);
}

long long area(const vector<rectangle>& v){
	long long ans=0;
	for(auto r : v){
		ans += area(r);
	}
	return ans;
}

double area(window* w){
	window* curr=w->next;
	rectangle outer;
	outer.x = w->x;
	outer.X = w->X;
	outer.y = w->y;
	outer.Y = w->Y;
	vector<rectangle> subtract;
	while(curr != nullptr){
		rectangle r;
		r.x = max(w->x, curr->x);
		r.X = min(w->X, curr->X);
		r.y = max(w->y, curr->y);
		r.Y = min(w->Y, curr->Y);
		if(valid(r))
			insert_rect(r, subtract);
		//cout<<subtract.size()<<endl;
		//print(subtract);
		curr = curr->next;
	}
	return 100.0*(double(area(outer)-area(subtract))/double(area(outer)));

}

void del(screen& s, char id, map<char,window*>& M){
	if(M[id]->next == nullptr && M[id]->prev == nullptr){
		s.first = nullptr;
		s.last = nullptr;
	}
	else if(M[id]->next == nullptr && M[id]->prev != nullptr){
		M[id]->prev->next = nullptr;
		s.last = M[id]->prev;

	}
	else if(M[id]->next != nullptr && M[id]->prev == nullptr){
		M[id]->next->prev = nullptr;
		s.first = M[id]->next;
	}
	else if(M[id]->next != nullptr && M[id]->prev != nullptr){
		M[id]->next->prev = M[id]->prev;
		M[id]->prev->next = M[id]->next;
	}
}

int main(){
	ifstream fin("window.in");
	ofstream fout("window.out");
	screen S;
	S.first = nullptr;
	S.last = nullptr;

	string c;
	map<char, window*> M;
	while(getline(fin,c)){
		char id = c[2];
		int x,y,X,Y;
		string r(c, 4, c.find(')')-4);
		stringstream ss(r);
		switch(c[0]){
			case 'w':
				ss >> x;
				ss.ignore();
				ss >> y;
				ss.ignore();
				ss >> X;
				ss.ignore();
				ss >> Y;
				M[id] = new window;
				M[id]->x=min(x,X);M[id]->y=min(y,Y);M[id]->X=max(x,X);M[id]->Y=max(y,Y);
				M[id]->id = id;
				push_back(S, M[id]);
			break;
			case 't':
				del(S,id,M);
				push_back(S, M[id]);
			break;
			case 'b':
				del(S,id,M);
				push_front(S, M[id]);
			break;
			case 'd':
				del(S, id,M);
				delete M[id];
			break;
			case 's':
				fout<<setprecision(3)<<fixed<<area(M[id])<<endl;
			break;
		}
	}
	return 0;
}