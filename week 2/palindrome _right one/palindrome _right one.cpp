
#include <iostream>
#include <string>
using namespace std;

bool IsPalindrom(string s){
	int i=0;

	if (s.empty()) return true;

	for (int i = 0; i < s.size() / 2; ++i) {
	        if (s[i] != s[s.size() - i - 1]) {
	            return false;
	        }
	    }
	    return true;
	}

int main() {

	string a;
	cin >> a;

	cout << IsPalindrom(a) << endl;

	return 0;
}
