#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;



int main() {
	string way = "input.txt", out = "output.txt";
	ifstream input(way);
//	ofstream outp(out);
	double line;

	cout << fixed << setprecision(3);
	if (input){
		while (input >> line){
			cout << line << endl;
//			outp << line << endl;
		}
	}
	/*
	if (input){
		cout << fixed << setprecision(3);
		while(getline(input, line)){
			cout << line;
		}
	}*/


	return 0;
}
