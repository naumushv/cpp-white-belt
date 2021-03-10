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


class ReversibleString {
public:
	ReversibleString() {
		 str ="";
	}
	ReversibleString(string inp) {
		str = inp;
	}
	 void Reverse (){
		reverse(str.begin(), str.end());
	}
	string ToString() const{
		return str;
	}


private:
  string str;
};


int main() {

	ReversibleString s("live");
	  s.Reverse();
	  cout << s.ToString() << endl;

	  s.Reverse();
	  const ReversibleString& s_ref = s;
	  string tmp = s_ref.ToString();
	  cout << tmp << endl;

	  ReversibleString empty;
	  cout << '"' << empty.ToString() << '"' << endl;

	return 0;
	};


