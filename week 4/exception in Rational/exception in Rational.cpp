#include <iostream>
#include <sstream>
#include <stdexcept>
#include <exception>
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
    	else if (denominator == 0){
    		throw invalid_argument("message supposed to be there");
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

Rational operator/(Rational one, Rational two){
	if (one.Denominator() == 0 || two.Numerator() == 0) throw domain_error("constructor is guilty here");
	Rational res (one.Numerator()*two.Denominator(), one.Denominator()*two.Numerator());
	return res;
}


int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}
