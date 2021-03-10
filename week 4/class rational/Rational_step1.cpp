#include <iostream>
//#include <numeric>
#include <cmath>
using namespace std;

int gcd(int a,int b){
    if(b==0)return a;
    else return gcd(b,a%b);
}

class Rational {
public:
    Rational() {
    	numer = 0;
    	denumer = 1;
    }

    Rational(int numerator, int denominator) {
    	int dv;
    	if (numerator == 0){
    		numer =0;
    		denumer =1;
    	}
    	else if ((numerator>0 && denominator<0) || (numerator<0 && denominator<0)){
    		dv = abs( gcd(numerator,denominator) );
        	numer=numerator*(-1)/dv;
        	denumer=denominator*(-1)/dv;
    	}
    	else {
    		dv = abs( gcd(numerator,denominator) );
    		numer=numerator/dv;
    		denumer=denominator/dv;
    	}

    }

    int Numerator() const {
        return numer;
    }

    int Denominator() const {
    	return denumer;
    }

private:
    int numer, denumer;
};

int main() {
    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }

    cout << "OK" << endl;
    return 0;
}
