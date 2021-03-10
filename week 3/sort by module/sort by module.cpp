
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

bool func(int x, int y) {return ( abs(x)<abs(y) );}

int main() {
	vector<int> nums;
	int quer,num;
	cin >> quer;
	for (int i=0; i<quer;i++){
		cin >> num;
		nums.push_back(num);
	}
	sort (nums.begin(), nums.end(), func);
	for (const auto& i:nums)
		cout << i << endl;
	//	string v1 = {"abs"}, v2 = {"dkdkd"};
	//	 sort (v1.begin(),v1.end());




	return 0;
	};



