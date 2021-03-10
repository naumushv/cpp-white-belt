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

void printvector(const vector<string>& a){
	for (auto b:a)
		cout << b << endl;
}

void printvector2(const vector<int>& a){
	for (auto b:a)
		cout << b << endl;
}

bool isbus(const vector<string>& v, const string& item){
	for (auto h:v){
		if (h == item) return 1;
	}
	return 0;
}


int main() {

	map<map<int,string>,vector<string>> m;
	vector<string> oper = {"NEW_BUS", "BUSES_FOR_STOP", "STOPS_FOR_BUS", "ALL_BUSES"};
	int quer, order=0;
	cin >>quer;

	for (int i=0; i<quer;i++){
		string time_to;
		cin >> time_to;
		if(time_to == oper[0]){
			int  num;
			string stop,bus_num;
			vector<string> bus_stops;
			map<int,string> bus;
			cin >> bus_num >> num;
			for (int j=0; j<num;j++){
				cin >> stop;
				bus_stops.push_back(stop);
			}
			bus[order] = bus_num;
			m[bus] = bus_stops;
			order++;
		}

		else if(time_to == oper[1]){
			vector<string> bb;
			string bus_need;
			cin >> bus_need;
			for (auto h:m){
				for (auto k: h.second){
					if (k == bus_need)
						bb.push_back(h.first.begin()->second);
				}
			}
			if (m.empty() || bb.empty())
				cout << "No stop" << endl;
			else{
				for (auto j:bb){
					cout << j << " ";
				}
				cout << endl;
			}
		}

		else if(time_to == oper[2]){
			string bus;
			cin >> bus;
			vector<string> brr;
			//give stops
			for (auto n:m){
				if (n.first.begin()->second == bus) brr = n.second;
			}
			if (brr.empty()) cout << "No bus" << endl;
			//output stops and interchange buses
			int cnt=0;
			for (auto k:brr){
				int cnr=0;
				cout << "Stop " << k << ": ";
				for (auto n:m){
					if (n.first.begin()->second != bus && isbus(n.second,k)){
						cout << n.first.begin()->second << " ";
					}
					else
//						cout << "no interchange  " << m.size();
						cnr++;

				}
				cnt++;
				if (cnr>=m.size()) cout << "no interchange" ;
				if (brr.size()!=cnt || i!=quer-1) cout << endl;
			}
		}

		else if(time_to == oper[3]){
			map<string, vector<string>> v;
			for (auto k:m){
					v[k.first.begin()->second] = k.second;
				}
			if (v.empty())
				cout << "No buses" << endl;
			else
				for (auto j:v){
					cout << "Bus " << j.first <<":";
					for (auto w:j.second){
						cout << " " << w;
					}
					cout << endl;
				}
		}

	}

	/*cout << endl << endl << endl;
	for (auto k:m){
		cout << k.first.begin()->first << "		" << k.first.begin()->second << endl;
	}*/



	/*map<vector<int>,vector<string>> m;
	m[{1, 950}] = {"vnukovo", "drankovo", "galino", "ivanovo"};
	m[{2, 750}] = {"vnukovo", "drankovo", "mitischi", "krukovo"};
	m[{4, 850}] = {"morozec", "holodec", "galino", "ivanovo"};
	m[{3,1060}] = {"mitischi", "moskva", "stepino", "morozec"};

	for (auto s:m){
		printvector2(s.first);
		cout << " end of first " << endl;
		printvector(s.second);
		cout << " end of second "<< endl << endl  << endl;
	}*/

	return 0;
	};



