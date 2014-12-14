/*
ID: holger1
PROG: shopping
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

#define INF 50000000
using namespace std;

struct offer{
	int price;
	map<int,int> products; 
};

int encode(const vector<int>& nums){
	int ans=0;
	int b = 1;
	for(int n : nums){
		ans += n*b;
		b *= 6; 
	}
	return ans;
}


vector<int> decode(int n){
	vector<int> ans;
	while(n > 0){
		ans.push_back(n % 6);
		n /= 6;
	}
	return ans;
}

void print(const vector<int>& a){
	for(int n : a){
		cout <<  n << " ";
	}
	cout << endl;
}

void print(const offer& off){
	cout << "OFFER::"<<endl;
	for(auto c  = off.products.begin(); c != off.products.end(); c++){
		cout << c->first << " "<< c->second << endl;
	}
	cout << off.price << endl;
	cout << endl;
}


vector<int> use_offer(int ids[5], vector<int> nums, offer off){
	vector<int> ans(nums.size());
	for(int i=0; i<nums.size(); i++){
		int c=ids[i];
		//cout << c << endl;
		if(off.products.find(c) == off.products.end())
			off.products[c] = 0;
		if(c == -1 || (off.products.find(c) == off.products.end() && nums[i] != 0) || off.products[c] > nums[i]){
			vector<int> invalid;
			invalid.push_back(-1);
			return invalid;
		}
		ans[i] = nums[i]-off.products[c];
	}

	return ans;
}

int main(){
	ifstream fin("shopping.in");
	ofstream fout("shopping.out");
	int s;
	fin >> s;
	vector<offer> offers(s);
	for(int i=0;i<s;i++){
		int n;
		fin >> n;
		offer off;
		off.products = map<int,int>();
		for(int j=0;j<n;j++){
			int c, k;
			fin >> c>> k;
			off.products[c] = k;
		}
		fin >> off.price;
		offers[i] = off;
	}

	map<int,int> orig_price;
	map<int, int> num;
	int ids[5] = {-1};
	int b;
	fin >> b;
	for(int i=0;i<b;i++){
		int c,k,p;
		fin >> c >> k >> p;
		orig_price[c] = p;
		num[c] = k;
		ids[i] = c;
	}

	num[-1] = 0;
	int best_price[10000];
	for(int i=0; i<10000; i++)
		best_price[i] = INF;
	best_price[0] = 0;
	for(int i=1; i<10000; i++){
		vector<int> nums = decode(i);
		if(nums.size() > 5) break;
		int price=INF;
		for(offer off : offers){
			vector<int> nums_after_offer = use_offer(ids, nums, off);
			if(nums_after_offer[0] != -1){

				int offer_price = best_price[encode(nums_after_offer)]+off.price;
				price = min(price, offer_price);
			}
		}
		for(int j=0; j<nums.size();j++){
			if(nums[j] > 0){
				//vector<int> del_one = vector<int>(nums);
				nums[j] -= 1;
				//print(nums);
				//cout << encode(del_one) << endl;
				vector<int> only_one(5,0);
				only_one[j] = 1;
				price = min(price, best_price[encode(nums)]+
					min(best_price[encode(only_one)], orig_price[ids[j]]));
				nums[j] +=1;
				//break;
			}
		}
		best_price[i] = price;
		//if(best_price[i] == INF) break;

		//print(decode(i));
		//cout << ", "<<best_price[i]<<endl;
	}
	vector<int> shopping_nums;
	for(int i=0; i<b;i++){
		shopping_nums.push_back(num[ids[i]]);
	}

	//print(shopping_nums);
	//cout << encode(shopping_nums)<<endl;
	fout << best_price[encode(shopping_nums)]<<endl;
	return 0;
}