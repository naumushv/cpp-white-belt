
#include <iostream>
#include <vector>
using namespace std;

int main() {

	int i;
	cin >> i;
	vector<int> v;
	while (i){
	//cout << i % 2 << endl;
	v.push_back(i % 2);
	//cout << i /2 << endl;
	i=i / 2;
	}

	for (int i:v){
		cout << v.back();
		v.pop_back();
	}

	return 0;
}
