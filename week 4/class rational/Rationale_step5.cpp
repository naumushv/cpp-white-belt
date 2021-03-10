#include <iostream>
#include <map>
#include <set>
#include <vector>
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

// Реализуйте для класса Rational операторы << и >>
ostream& operator<<(ostream& ostr, Rational one){
	ostr << one.Numerator() << '/' << one.Denominator();
	return ostr;
}

istream& operator >> (istream& s, Rational& n) {
		int a, b;
		char c;

		s >> a >> c >> b;

		if (s && c == '/')
			n = Rational(a, b);
		return s;
}

// Реализуйте для класса Rational оператор(ы), необходимые для использования его
// в качестве ключа map'а и элемента set'а

bool operator<(const Rational one, const Rational two){
	int ld, ld_one, ld_two;
	if (one == two) return false;
	ld = abs( lcm(one.Denominator(),two.Denominator()) );
	ld_one = abs(ld/one.Denominator());
	ld_two = abs(ld/two.Denominator());
	int first =one.Numerator()*ld_one;
	int second = two.Numerator()*ld_two;
	if (first<second){
		return true;
	}
	else return false;
}

int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << rs.size() <<  endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
