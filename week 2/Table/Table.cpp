#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <iomanip>
#include <istream>
using namespace std;



int main() {
	string way = "input.txt", out = "output.txt";
	ifstream input(way);

	int  n=0, m=0, line;

	if (!input){
		cout << "some prob with reading input";
		return 0;
	}
	input >> n >> m;
	for (int k=0; k < n; k++){
		for (int i=0;i<m;i++){
		 input >> line;
		            input.ignore(1);
		            if(i == m-1)
		                cout << setw(10) << line;
		            else
		                cout << setw(10) << line << " ";
		        }
		        cout << endl;
	}

	return 0;
}
