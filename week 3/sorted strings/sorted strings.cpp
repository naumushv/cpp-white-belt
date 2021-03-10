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

class SortedStrings {
public:
  void AddString(const string& s) {
	  v1.push_back(s);
  }
  vector<string> GetSortedStrings() {
//	  sort(v1.begin()), v1.end());
	  makeitsort();
	  return v1;
  }
private:
  vector<string> v1;
  void makeitsort(){
	  sort(v1.begin(),v1.end());
  }
};

void PrintSortedStrings(SortedStrings& strings) {
  for (const string& s : strings.GetSortedStrings()) {
    cout << s << " ";
  }
  cout << endl;
}
/*
int main() {

	vector<string> v = {"third", "first", "second"};
	sort(v.begin(), v.end());
	for (auto& k:v)
		cout << k << endl;
	SortedStrings strings;

	  strings.AddString("first");
	  strings.AddString("third");
	  strings.AddString("second");
	  PrintSortedStrings(strings);

	  strings.AddString("second");
	  PrintSortedStrings(strings);



	return 0;
	};*/



