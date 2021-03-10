
#include <iostream>
#include <map>
#include <vector>
//#include <utility>
#include <set>
using namespace std;

int main() {
	set<string> shit;
	unsigned int num;
	string for_shit;
	cin >> num;
	for (int i=0; i<num; i++){
		cin >> for_shit;
		shit.insert(for_shit);
	}
	cout << shit.size() << endl;

	return 0;
	};



