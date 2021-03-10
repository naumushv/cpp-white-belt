
#include <iostream>
#include <map>
#include <vector>
//#include <utility>
#include <set>
using namespace std;



int main() {
	int quer=0, route=1;
	map<set<string>, int> stops;
	cin >> quer;
	for (int i=0; i<quer;i++){
		int stop_num;
		string inp;
		set<string> v;
		cin >> stop_num;
		for (int k=0;k<stop_num;k++){
			cin >> inp;
			v.insert(inp);
		}
		if (stops.count(v)) cout << "Already exists for " << stops[v] << endl;
		else {
			cout << "New bus " << route << endl;
			stops[v] = route;
			route++;
		}

//		stops[tmp].insert(v.begin(),v.end());

	}

	return 0;
	};



