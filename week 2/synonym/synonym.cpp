
#include <iostream>
#include <map>
#include <vector>
//#include <utility>
#include <set>
using namespace std;



int main() {
	int quer=0, add=0;
	map<string, set<string>> all_sets;
	vector<string> oper = {"ADD", "COUNT","CHECK"};
	cin >> quer;
	for (int i=0; i<quer;i++){
		string operation;
		cin >> operation;
		if (operation == oper[0]){
			string word1, word2;
			cin >> word1 >> word2;
			if (!all_sets.count(word1)){
				if (!all_sets[word1].count(word2)){
					all_sets[word1].insert(word2);
				}
			}
			else if (!all_sets[word1].count(word2))
				all_sets[word1].insert(word2);
			if (!all_sets.count(word2)){
				if (!all_sets[word2].count(word1)){
									all_sets[word2].insert(word1);
				}
			}
			else if (!all_sets[word2].count(word1))
				all_sets[word2].insert(word1);
		}
		else if (operation == oper[1]){
			string cnt;
			cin >> cnt;
			if (all_sets.count(cnt)) cout << all_sets[cnt].size() << endl;
			else cout << 0 << endl;
		}
		else if (operation == oper[2]){
			string word1, word2;
			bool flag=0;
			cin >> word1 >> word2;
			if (all_sets.count(word1) || all_sets.count(word2))
				if (all_sets[word1].count(word2) || all_sets[word2].count(word1))
					flag = 1;
			if (flag) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}



	return 0;
	};



