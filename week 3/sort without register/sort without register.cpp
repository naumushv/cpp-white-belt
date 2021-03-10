
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <ctype.h>
#include <cctype>
#include <cstring>
#include <cstdio>
using namespace std;

bool func(string x,string y) {
	string x1 = x, y1 =y;
	for (auto& k:x1)
		k = tolower(k);
	for (auto& h:y1)
			h = tolower(h);
	return x1<y1;
}

int main() {
	vector<string> strs;
	int quer;
	cin >> quer;
	for (int i=0; i<quer;i++){
		string str;
		cin >> str;
		strs.push_back(str);
	}
	sort (strs.begin(), strs.end(), func);
	for (const auto& i:strs)
		cout << i << endl;




	return 0;
	};



