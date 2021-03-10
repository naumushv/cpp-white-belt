#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <iomanip>
#include <istream>
using namespace std;

struct student{
	string name, family;
	int day, month, year;
};

int main() {

	int stud_num, query_num, stud_id_query;
	string query;
	vector<student> stud_vec;

	cin >> stud_num;
	for (int i=0; i<stud_num; i++){
		stud_vec.push_back(student());
		cin >> stud_vec[i].name >> stud_vec[i].family >> stud_vec[i].day >>
		stud_vec[i].month >> stud_vec[i].year;
	}

	cin >> query_num;

	for (int i=0;i<query_num;i++){
		cin >> query >> stud_id_query;
		if (query == "name"){
			if (stud_id_query < 1 || stud_id_query > ((int)stud_vec.size()))
			{ cout << "bad request" << endl;}
			else {
			--stud_id_query;
			cout << stud_vec[stud_id_query].name << " " <<
					stud_vec[stud_id_query].family << endl;
			}
		}

		else if (query == "date"){
			if (stud_id_query < 1 || stud_id_query > ((int)stud_vec.size()))
				cout << "bad request" << endl; else{
			--stud_id_query;
			cout << stud_vec[stud_id_query].day << "." <<
					stud_vec[stud_id_query].month << "." <<
					stud_vec[stud_id_query].year << endl;
			}
		}

		else cout << "bad request" << endl;

	}










//	string way = "input.txt", out = "output.txt";
//	ifstream input(way);

	return 0;
}
