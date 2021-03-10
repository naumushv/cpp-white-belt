#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <ctype.h>
#include <cctype>
#include <iterator>
#include <cstring>
#include <cstdio>
using namespace std;

/*bool here(vector<string>& vv, string word){
	for (auto i:vv)
		if (i==word) return false;
	return true;
}*/
//&& here(ss,l.second)    && ll!=it.begin()   ll=next(it.begin())

vector<string> wannait(map<int,string>& it, int& num){
	vector<string> ss;
	if (it.empty()) return ss;
	map<int, string>::iterator ll,dk;
	if (it.begin()->first<=num) ss.push_back(it.begin()->second);
	for (ll=next(it.begin());ll!=it.end();ll++){
			if (ll->first<=num  && prev(ll)->second!=ll->second)
				ss.push_back(ll->second);
//		else break;
	}

	return ss;

	/*string res;
	for (auto l:ss)
		if (l!=ss.back()) res += (l + ", ");
	return res;*/
}

string trans(vector<string> v){
	string s = "";
	v.pop_back();
//	sort(v.begin(),v.end());
//	vector<string>:: iterator r;
	for (auto r=v.rbegin(); r!= v.rend(); r++){
		if (*r!=v.front()) s += (*r + ", ");
		else s += *r;
}
	return s;
}

string itis(vector<string>& v1, vector<string>& v2){
	if (v1.empty() && v2.empty())
		  		return "Incognito";
		  	 else if (v2.empty()){
		  		 if (v1.size()>=2)
		  			 return { v1.back() + " (" + trans(v1) + ") " + "with unknown last name"};
		  		 else return {v1.back() + " with unknown last name"};
		  	 }
		  	 else if (v1.empty()){
		  		 if (v2.size()>=2)
		  			 return { v2.back() + " (" + trans(v2) + ") " + "with unknown first name"};
		  		 else return {v2.back() + " with unknown first name"};
		  	 }
		  	 else{
		  		 string res = "";
		  		 for (auto k:{v1}){
		  			if (k.size()>=2)
		  				res += k.back() + " (" + trans(k) + ") " ;
		  			else res += k.back() + " ";
		  	 }
		  		for (auto k:{v2}){
					if (k.size()>=2)
						res += k.back() + " (" + trans(k) + ")" ;
					else res += k.back();
				 }
				return res;
		  	 }
}

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
  }
  string GetFullNameWithHistory(int year) {
	  	 vector<string> ff,ss;
	  	 ff = wannait(fn,year);
	  	 ss = wannait(ln,year);
	  	 string res;
//	  	 res = ff.back() + "  " + ss.back();
	  	 res = itis(ff,ss);

	  	 /*for (auto k:ff)
	  		 res +=k;
	  	 res += "|    |";
	  	 for (auto kk:ss)
	  		 res +=kk;*/
	  	 return res;
  }
private:
  map<int, string> fn;
  map<int, string> ln;
};


int main() {
	Person person;

	 person.ChangeLastName(1967, "Sergeeva");
		  for (int year : {1965, 1990}) {
		    cout << person.GetFullNameWithHistory(year) << endl;
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


