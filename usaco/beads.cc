/*
ID: holger1
PROG: beads
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
	ifstream fin("beads.in");
	ofstream fout("beads.out");
	int n;
	fin >> n;
	string bead;
	fin >> bead;
	int front=0, back=0;
	int i=0;
	char front_color = 'w';
	while(bead[i]=='w' || bead[i]==front_color || front_color=='w'){
		if(i>=n) break;
		if(front_color == 'w' && bead[i] != 'w') front_color = bead[i];
		front++; i++;
	}

	if(front>=bead.length()){
		fout << front << endl;
		return 0;
	}
	
	i = bead.length()-1;
	char back_color = 'w';
	while(bead[i]=='w' || bead[i]==back_color || back_color=='w'){
		if(back_color == 'w' && bead[i] != 'w') back_color = bead[i];
		back++; i--;
	}
	int m = back+front;
	for(int i=1; i<=n; i++){
		if(bead[i-1] == 'w' || bead[i-1] == back_color)
			back += 1;
		else{
			back = 1;
			back_color = bead[i-1];
			int j = i-2;
			while(j>0 && bead[j] == 'w'){
				back +=1;
				j--;
			}
		}
		front_color = 'w';
		int j=i;
		front=0;
		while(bead[j]=='w' || bead[j]==front_color || front_color=='w'){
			if(front_color == 'w' && bead[j] != 'w') front_color = bead[j];
			front++; j++;
			j %= n;
		}
		if(back+front > m) m = back+front;
	}
	fout << min(n,m) << endl;
	return 0;
}