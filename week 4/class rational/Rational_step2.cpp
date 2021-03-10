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

int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
