#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void Printmap(const map<char, int>& pr){
	for (auto& c: pr){
		cout << c.first << " ";
	}
}



int main() {

	vector<string> operations = {"CHANGE_CAPITAL", "RENAME", "ABOUT", "DUMP"};
	map<string, string> country_list;


/*
	map<string, string> co = {{"Russia", "Moscow"},
			{"Norway", "Oslo"},
			{"Norway", "London"},
			{"Norway", "Moscow"},
			{"Norway", "Oslo"},
			{"UK", "London"},
			{"UK", "London"}
	};

//	cout << co.count("UK") << endl;
//	cout << co.count("Norway") << endl;
//	cout << co.count("dfsfsf") << endl;

	for (auto& it : co){
		cout << it.first << " " << it.second << endl;
	}
*/

	int req_num=0;
	cin >> req_num;
	for (int i=0; i < req_num; i++){

	//iteration for operations
	string oper;
	cin >> oper;
	if (oper == operations[0]){
		string country, new_capital;

		cin >> country >> new_capital;

		if (country_list.count(country)){
			if (country_list[country]==new_capital) cout << "Country " << country << " hasn't changed its capital" << endl;
			else {
				cout << "Country " << country << " has changed its capital from " << country_list[country];
				country_list[country]=new_capital;
				cout << " to " << new_capital <<endl;
			}
		}
		else {
			cout << "Introduce new country " << country << " with capital "<< new_capital << endl;
			country_list[country] = new_capital;
		}
	}
	//change capital

		//change capital if country exits

		//add new country and new capital if not exits

		//old capitall == new capital


	else
		if (oper == operations[1]){
			string old_country_name, new_country_name;
			cin >> old_country_name >> new_country_name;
			if (country_list.count(old_country_name)==0 || old_country_name == new_country_name || country_list.count(new_country_name))
				cout << "Incorrect rename, skip" << endl;
			else {
				country_list[new_country_name]=country_list[old_country_name];
				country_list.erase(old_country_name);
				cout << "Country " << old_country_name << " with capital " << country_list[new_country_name] << " has been renamed to " << new_country_name << endl;
			}
		}

	//rename country
		//if old country name == new country name

		//has been renamed

		else
			if (oper == operations[2]) {
				string country;
				cin >> country;
				if (country_list.count(country)==0) cout << "Country " <<  country << " doesn't exist" << endl;
				else
					cout << "Country " << country << " has capital " << country_list[country] << endl;
			}

	//ABOUT output capital of country
		//doesnt exist

		//has capital


			else
				if (oper == operations[3]){
					if (country_list.empty()) cout << "There are no countries in the world" << endl;
					else
						for (auto& it:country_list){
							cout << it.first << "/" << it.second << endl;
						}
				}

	//output all capitals
		//no countries

		//country capital
	}


	return 0;
}
