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

	map<char, int> words1, words2;
	int oper;
	cin >> oper;
	for (int i = 0; i < oper; i++){
		string str1, str2;
		bool flag=0;
		cin >> str1 >> str2;
		if (str1.length()!=str2.length()) flag = 0;
		else {
			for (auto c:str1){
				words1[c]++;
			}
			for (auto c:str2){
				words2[c]++;
			}
			flag = (words1 == words2);
		}
		if (flag) cout << "YES" << endl; else cout << "NO" << endl;
		words1.clear();
		words2.clear();
	}
	return 0;
}





/*#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char, int> BuildCharCounters(const string& word) {
  map<char, int> counters;
  for (char c : word) {
    ++counters[c];
  }
  return counters;
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    string first_word, second_word;
    cin >> first_word >> second_word;
    if (BuildCharCounters(first_word) == BuildCharCounters(second_word)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}*/
