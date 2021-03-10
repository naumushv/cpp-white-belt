#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <sstream>
#include <algorithm>
#include <iomanip>
using namespace std;

class Date {
public:
	Date(int Year, int Month, int Day){
		year = Year;
		month = Month;
		day = Day;
	}
  int GetYear() const{
	  return year;
  }
  int GetMonth() const{
	  return month;
  }
  int GetDay() const{
	  return day;
  }
private:
  int year, month, day;
};

void sort_print(set<string>& input, bool& first){
	long unsigned int size = input.size()-1;
	int i = 0;
	for (auto it:input){
		if (!(i == 0 && size==0) && !first)
		cout << endl;
		cout <<  it;
		first = false;
		i++;
	}
}

struct checker_result{
	checker_result(int code){
		result_code = code;
		year = 0, month = 0, day = 0;
	}
	checker_result(int code,int year_i,int month_i, int day_i){
		result_code = code;
		year = year_i;
		month = month_i;
		day = day_i;
	}
	checker_result(int code, string msg, int year_i,int month_i, int day_i){
		result_code = code;
		message = msg;
		year = year_i;
		month = month_i;
		day = day_i;
	}
	checker_result(int code, string msg){
			result_code = code;
			message = msg;
			year = 0, month = 0, day = 0;
	}
	checker_result(){
		year = 0, month = 0, day = 0, result_code = 0;
	}
	int result_code;
	string message;
	int year, month, day;
};

bool operator<(const checker_result& lhs, const checker_result& rhs){
	if (lhs.year < rhs.year) return true;
	else if (lhs.year == rhs.year && lhs.month < rhs.month) return true;
	else if (lhs.year == rhs.year && lhs.month == rhs.month && lhs.day < rhs.day)
		return true;
	else return false;
}

bool operator<(const Date& left_date, const Date& right_date){
	if (left_date.GetYear() < right_date.GetYear()) return true;
	else if (left_date.GetYear() == right_date.GetYear() &&
			left_date.GetMonth() < right_date.GetMonth()) return true;
	else if (left_date.GetYear() == right_date.GetYear() &&
			left_date.GetMonth() == right_date.GetMonth() &&
			left_date.GetDay() < right_date.GetDay()) return true;
	else return false;
}

bool operator==(const Date& left_date, const Date& right_date){
	if (left_date.GetYear() == right_date.GetYear() &&
			left_date.GetMonth() == right_date.GetMonth() &&
			left_date.GetDay() == right_date.GetDay())
		return true;
	else return false;

}

class Database {
public:

  void AddEvent(Date& date, string& event){
	  dtb[date].insert(event);
  }

  bool DeleteEvent(const Date& date, string& event){
	  return dtb[date].erase(event);
  }

  int DeleteDate(const Date& date){
//	  if (dtb.count(date)) {
		  try{
			  int size = dtb.at(date).size();
			  if (dtb.erase(date)) return size;
		  }
		  catch(exception& ex){
			  return 0;
		  }
//	  }
	  return 0;
  }

  set<string> Find(const Date& date) const{
	  if (dtb.count(date)) return dtb.at(date);
	  else {
		  set<string> empt;
		  return empt;
	  }
  }

  void Print(bool& first) const{
	  long unsigned int count = 0;
	  for (auto aut:dtb){
		  long unsigned int size_dtb = dtb.size()-1;
		  long unsigned int size_vec = aut.second.size()-1;
		  if (count == 0 && !first) cout << endl;
		  first = false;
		  if (aut.first.GetYear() < 0){}
		  else {
			  long unsigned int i=0;
			for (auto brr:aut.second){
				cout << setw(4) << setfill('0') << aut.first.GetYear() << '-';
				cout << setw(2) << setfill('0') << aut.first.GetMonth() << '-';
				cout << setw(2) << setfill('0') << aut.first.GetDay() << ' ';
				if (i == size_vec && count == size_dtb)
					cout << brr;
				else cout << brr << endl;
				i++;
			}
		  }
		  ++count;
	  }
  }
private:
  map<Date, set<string>> dtb;
};



checker_result checker(string& inp, vector<string> const op){
	bool there_oper = false;
	int year, month, day;
	char df1, df2;
	string tt, rr;
	if (inp == "") {return {1};}
	stringstream ss(inp);
	string operation;
	ss >> operation;
	// unknown command format
	for (auto a:op){
		if (operation == a) there_oper = true;
	}
	if (there_oper == false){
		inp = "Unknown command: " + operation;
		return {2, inp};
	}
	//print operation
	else if (operation == "Print") {
		return {9};
	}

	ss >> tt;
	stringstream aa(tt);
	if (tt == ""){
		inp = "Wrong date format: " + tt;
		return  {3, inp};
	}

	for (int i=0; i < 5; i++){
		if (aa.fail() || aa.eof() || aa.peek() == EOF){
			inp = "Wrong date format: " + tt;
			return  {3, inp};
		}
		else if (i == 0 ) {
			aa >> year;
		}
		else if (i == 1){
			aa >> df1;
		}
		else if (i == 2){
			aa >> month;
		}
		else if (i == 3){
			aa >> df2;
		}
		else if (i == 4){
			aa >> day ;
		}

	}

	//data format invalid
	if (aa.peek() != EOF || df1 != '-' || df2 != '-' || !aa.eof() ){
		inp = "Wrong date format: " + tt;
		return  {3, inp};
	}
	else if (month < 1 || month > 12){
			inp = "Month value is invalid: " + to_string(month);
			return {3, inp};
	}
	else if (day < 1 || day > 31 ){
			inp = "Day value is invalid: " + to_string(day);
			return {3, inp};
	}
	//find operation
	else if (operation == "Find"){
			return {6, year, month, day};
	}
	if (ss.eof() && operation == "Del"){
		return {8, year, month, day};
	}
	ss >> rr;
	if (rr == ""){}
	else if (operation == "Del"){
		return {7, rr, year, month, day};
	}
	else if (operation == "Add"){
		return {4, rr, year, month, day};
	}
}

int main() {



  Database db;
  vector<string> operations = {"Add", "Del", "Find", "Print"};
  string command;
  bool first_command = true;
  checker_result res;
  while (getline(cin, command)) {
	  res = checker(command, operations);
	  switch(res.result_code){
	  case 1 : {
		  //empty code
		  break;}
	  case 2 : {
		  // unproper command input
		  cout << res.message<< endl;
		  return 0;
		  break;
	  }
	  case 3 : {
		  //date format invalid
		  cout << res.message << endl;
		  break;
	  }
	  case 4:{
		  //add operation, success
		  Date dd(res.year, res.month, res.day);
		  db.AddEvent(dd, res.message);
//		  cout << "Add operation contains: " << res.message << res.year << res.month << res.day << endl;
		  break;
	  }
	  case 6 : {
		  //find
		  Date date(res.year, res.month, res.day);
		  auto ret = db.Find(date);
		  if (ret.size() > 0){
			  sort_print(ret, first_command);
			  first_command = false;
		  }
		  break;
	  }
	  case 7 : {
		  //long del
		  Date ret(res.year, res.month, res.day);
		  if (db.DeleteEvent(ret, res.message)){
			  if (!first_command){
			  cout << endl << "Deleted successfully";
			  }
			  else cout << "Deleted successfully";
		  }
		  else if (!first_command) {
			  cout << endl << "Event not found" ;
		  }
		  else cout << "Event not found" ;
//		  cout << "long Detele has following:" <<  res.message << "  " << res.year << res.month << res.day << endl;
		  first_command = false;
		  break;
	  }
	  case 8 : {
		  //short del
		  Date ret(res.year, res.month, res.day);
		  if (!first_command)
		  cout << endl << "Deleted " << db.DeleteDate(ret) << " events";
		  else cout << "Deleted " << db.DeleteDate(ret) << " events";
//		  cout << res.year << res.month << res.day << endl;
		  first_command = false;
		  break;
	  }
	  case 9 : {
		  //print
//		  cout << endl;
		  db.Print(first_command);
		  first_command = false;
//		  cout << "there is print oper" << endl;
		  break;
	  }

	  }

  }

  return 0;
}
