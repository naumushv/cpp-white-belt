#include <iostream>
#include <sstream>
#include <stdexcept>
#include <exception>
using namespace std;


int gcd(int a,int b){
    if(b==0)return a;
    else return gcd(b,a%b);
}

int lcm(int a, int b)
  {
     return (a*b)/gcd(a, b);
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

// Реализуйте для класса Rational операторы ==, + и -

Rational operator+(Rational one, Rational two){
	if (one.Denominator()==two.Denominator()){
		Rational res(one.Numerator()+two.Numerator(), one.Denominator());
		return res;
	}
	else{
		int lm = abs(lcm(one.Denominator(), two.Denominator()));
		int mp_one = lm/one.Denominator();
		int mp_two = lm/two.Denominator();
				Rational res((one.Numerator()*mp_one)+(two.Numerator()*mp_two),
						lm);
				return res;
	}
}

bool operator==(Rational one, Rational two){
	int dv_one = abs( gcd(one.Numerator(),one.Denominator()));
	int dv_two = abs( gcd(two.Numerator(),two.Denominator()));
	if (one.Numerator()==two.Numerator() && one.Denominator()==two.Denominator()){
		return true;
	}
	else if ((one.Numerator()/dv_one)==(two.Numerator()/dv_two)
			&& (one.Denominator()/dv_one)==(two.Denominator()/dv_two))
		return true;
	else return false;
}

Rational operator-(Rational one, Rational two){
	if (one.Denominator()==two.Denominator()){
		Rational res(one.Numerator()-two.Numerator(), one.Denominator());
		return res;
	}
	else{
		int lm = abs(lcm(one.Denominator(), two.Denominator()));
		int mp_one = abs(lm/one.Denominator());
		int mp_two = abs(lm/two.Denominator());
				Rational res((one.Numerator()*mp_one)-(two.Numerator()*mp_two),
						lm);
				return res;
	}
}

// Реализуйте для класса Rational операторы * и /

Rational operator*(Rational one, Rational two){
	Rational res (one.Numerator()*two.Numerator(), one.Denominator()*two.Denominator());
	return res;
}

Rational operator/(Rational one, Rational two){
	Rational res (one.Numerator()*two.Denominator(), one.Denominator()*two.Numerator());
	return res;
}

int main() {
	//pizdec part
	string input, oper, tmp;
	int one_nom, one_denom, two_nom, two_denom;
	char slash_one, slash_two;
	cin >> input;
	stringstream ss(input);
	input.clear();
	ss >> one_nom >> slash_one >> one_denom;
	cin >> oper;
	ss.clear();
	ss.str((string()));
	cin >> input;
	ss << input;
	ss >> two_nom >> slash_two >> two_denom;

//	cout << one_nom << slash_one << one_denom << oper <<  two_nom << slash_two << two_denom << endl;

	Rational res;
	Rational one(one_nom, one_denom), two(two_nom, two_denom);
	if (slash_one !='/' || slash_two != '/' || one_denom==0 || two_denom==0){
		cout << "Invalid argument" << endl;
		return 0;
	}
	if (oper=="+"){
		res = one + two;
		cout << res.Numerator() << "/" << res.Denominator();
	}
	else if (oper=="-"){
		res = one - two;
		cout << res.Numerator() << "/" << res.Denominator();
	}
	else if (oper=="*"){
		res = one * two;
		cout << res.Numerator() << "/" << res.Denominator();
	}
	else if(oper=="/"){
		if (two.Numerator()==0){
			cout << "Division by zero" << endl;
			return 0;
		}
		else {
			res = one / two;
			cout << res.Numerator() << "/" << res.Denominator();
		}
	}
	else {
		cout << "Invalid argument" << endl;
				return 0;
	}

    return 0;
}
