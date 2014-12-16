/*
ID: holger1
PROG: heritage
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <stack>
#include <algorithm>
#include <limits>
#include <queue>
using namespace std;

string post_order(string in_order, string pre_order){
	if(in_order.length() <= 1)
		return in_order;
	char root=pre_order[0];
	
	string in_order_left="";
	string in_order_right="";
	bool l=true;
	for(char s : in_order){
		if(s == root){
			l = false;
		}
		else{
			l ? in_order_left+=s : in_order_right += s;
		}
	}

	string pre_order_left="";
	string pre_order_right="";
	for(char s : pre_order){
		if(s == root) continue;
		if(in_order_left.find(s) != string::npos){
			pre_order_left += s;
		} 
		else{
			pre_order_right += s;
		}
	}

	return post_order(in_order_left, pre_order_left)+post_order(in_order_right, pre_order_right)+root;
}

int main(){
	ifstream fin("heritage.in");
	ofstream fout("heritage.out");
	string in_order, pre_order;
	fin >> in_order >> pre_order;
	fout << post_order(in_order, pre_order) << endl;

}