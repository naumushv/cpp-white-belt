#include <iostream>
using namespace std;


int gcd(int a,int b){
    if(b==0)return a;
    else if (a==b && a==0) return 0;
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
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    {
            Rational a(1, 3);
            Rational b(2, 3);
            Rational c = a * b;
            bool equal = c == Rational(2, 9);
            if (!equal) {
                cout << "  assert(Rational(2, 3) * Rational(1, 3) == Rational(2, 9)" << endl;
                return 3;
            }
        }

    cout << "OK" << endl;
    return 0;
}
