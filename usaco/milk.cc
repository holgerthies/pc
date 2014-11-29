/*
ID: holger1
PROG: milk
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main(){
	ifstream fin("milk.in");
	ofstream fout("milk.out");
	int units, m;
	fin >> units >> m;
	multiset<pair<int,int>> pricelist;
	for(int i=0; i<m; i++){
		int price, amount;
		fin >> price >> amount;
		pricelist.insert(make_pair(price,amount));
	}
	int total_price=0;
	for(auto p : pricelist){
		int buy=min(units, p.second);
		total_price += buy*p.first;
		units -= buy;
	}
	fout << total_price << endl;
	return 0;
}