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

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
	  fn[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
	  ln[year] = last_name;
  }
  string GetFullName(int year) {
	  string result,n="",f="";
	  /*bool empty = ln.empty() && fn.empty();
	  if ((year<=fn.begin()->first && year<=ln.begin()->first) || empty){
		  return "Incognito";
	  }
	  else {*/
		  for (auto i:fn)
			  if (i.first<=year) n=i.second;
		  for (auto k:ln)
			  if (k.first<=year) f=k.second;
		  if (n=="" && f=="")
			  return "Incognito";
		  else
			  if (n!="" && f=="")
				  return {n + " with unknown last name"};
			  else
				  if(n=="" && f!="")
					  return { f + " with unknown first name"};
				  else return { n + " " + f};
//	  }

  }
private:
  map<int, string> fn;
  map<int, string> ln;
};


int main() {
	Person person;

	person.ChangeLastName(3, "3_2nd");
	person.ChangeLastName(6, "6_2nd");

	for (int year : {3, 4, 5, 6}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeFirstName(-1, "-1_1st");
	person.ChangeFirstName(2, "2_1st");

	for (int year : {-1, 0, 1, 2, 3, 6}) {
		cout << person.GetFullName(year) << endl;
	}

//	hmn[1970][0] = "shit";

/*

	map<int,string, std::greater<int>> m ={
			{1930, "Sasha"},
			{1940, "Anton"},
			{1950, "Ivan"},
			{1960, "Nikolai"},
			{1970, "Anatolii"},
			{1980, "Petr"},
			{1990, "Timofey"}

	};
	map<int,string>::iterator it = 	m.lower_bound(1929);
	cout << endl << endl;
	cout << it->first << it->second << endl << endl;
	cout  << distance(m.end(), it) << endl << distance(m.begin(), it) << endl;
	cout << "next and prev" << endl <<  next(it)->first << endl << prev(it)->first << endl;
	for (auto l:m)
		cout << l.first << endl;
	bool rrr = it==m.end() || it==m.begin();
	cout << rrr << endl;
	cout << m.end()->first << endl << it->first << endl;
*/

/*		map<int,string>::iterator fn = 	min_element(first_names.begin(), first_names.end());
	map<int,string>::iterator sn = 	min_element(last_names.begin(), last_names.end());
	if ((fn->first>year && sn->first>year) || ( first_names.empty() && last_names.empty() ))
		return "Incognito";
	else if ( (sn->first<=year) && (fn->first > year || first_names.empty()) )
		return { sn->second + " with unknown first name"};
	else if ( fn->first<=year && (sn->first > year || last_names.empty()))
		return { fn->second + " with unknown last name"};
	else if (!(first_names.empty() || last_names.empty())){
		string name,last;

		if (first_names.empty()) name = "true";
		return { name + "  "};
	}
	else return "error";  */


	return 0;
	};


