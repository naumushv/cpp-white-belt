
#include <iostream>
#include <cmath>
using namespace std;

int main() {

	int a,b,h;
	cin >> a >> b;
	a = abs(a);
	b = abs(b);

	while (a && b){
		if (a > b)
			a = a % b;
		else
			b = b % a;
	}

	cout << (a + b) << endl;

	return 0;
}
