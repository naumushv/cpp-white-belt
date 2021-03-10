
#include <iostream>
#include <string>
#include <vector>
using namespace std;


void print_ordinary(vector<string>& p){

	for (int i=0; i < p.size();i++)
		cout << p[i];

}

int main() {

	vector<int> calendar {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	vector<string>oper {"ADD", "DUMP", "NEXT"};
	vector<vector<string>> task_list;
	int day=0,month=0, operations=0;
	string task, current;
//	calendar[-1]=calendar[0];

	for (int i=0; i < 31; i++){
		task_list.push_back(vector<string>());
	}

/*
	task_list = { {"str1", "sfsds", "fsdfsdfs"},
		{"aaaaaa", "aaaaaas", "aaaa"},
		{"bbbb", "bbb"}};
	cout << end(task_list) ;
	cout << end(task_list[1]);
*/

/*
	vector<string> v1, v2;
				v1 = {"shit", "nigga", "fuck"};
				v2 = {"holy", "boy"};
				v1.insert(end(v1), begin(v2), end(v2));
			task_list[0].insert(end(task_list[0]), begin(task_list[1]), end(task_list[1]));
			task_list[calendar[month]-1].insert(
					end(task_list[calendar[month]-1]),
					begin(task_list[calendar[month-1]-1]),
					end(task_list[calendar[month-1]-1])
					);
*/


	/*
	for (int i=0; i < 31; i++){
			task_list[i].assign(31,"");
	}

	cin >> task;
	task_list[5].push_back(task);
*/


	cin >> operations;
	for (int l=0;l<operations;l++){

	cin >> current;

	if (current == oper[0]){
	//	add operation

	cin >> day;
	day--;
	cin >> task;
	task_list[day].push_back(task);
	}

	if (current == oper[1]){
//	dump operation

	cin >> day;
	day--;
	cout
			<< task_list[day].size()
			<< " ";
	for (int i=0; i < task_list[day].size();i++)
			cout << task_list[day][i] << " ";
		cout << endl;
	}

	if (current == oper[2]){
//	next opeartion

	if (month==11) month=-1;
	++month;
	if (calendar[month-1] <= calendar[month]){
		task_list.resize(calendar[month]);
	}
	else {
		for (int i=0; i < (calendar[month-1]-calendar[month]); i++){

			task_list[calendar[month]-1].insert(
								end(task_list[calendar[month]-1]),
								begin(task_list[calendar[month-1]-1-i]),
								end(task_list[calendar[month-1]-1-i])
								);

			/*task_list[10].insert("fdsfsd");
	task_list[calendar[month]-1].insert(
			end(task_list[month]-1),
			begin(task_list[month-1]-1),
			end(task_list[month-1]-1));*/

		//			for (int j=0; j < task_list[calendar[month-1]-1-i].size(); i++){
//			task_list[calendar[month]-1].push_back(task_list[calendar[month-1]-1-i][j]);
//		}
	}
	task_list.resize(calendar[month]);
	}
	}

	}


	/*vector<int> rrr1 { 1, 2 , 3, 4, 5, 6};
	vector<int> b;

	Print(rrr1);
	rrr1.resize(4);
	cout << endl;
	Print(rrr1);
	rrr1.resize(8);
	cout << endl;
	Print(rrr1);
*/

	return 0;
}
