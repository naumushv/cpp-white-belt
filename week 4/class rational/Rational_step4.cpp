#include <iostream>
#include <sstream>
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

int main() {

/*
	string whatisee, sum;
	vector<int> vv;
    istringstream input("5/7 4/5 11/120 838/39299");
    int number;
    stringstream ss;
	while (input >> whatisee){
//		getline(input, whatisee, '/');
//		getline(input, whatisee);
//		input >> whatisee;
		cout << whatisee << "    __1__" << endl;
		ss << whatisee;
		//		if (istringstream(whatisee) >> number) vv.push_back(number);
	}

	while (ss >> number){
				cout << number << "     __2__" << endl;
	}
*/
	{
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }


    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("");
        Rational r;
        bool correct = !(input >> r);
        if (!correct) {
            cout << "Read from empty stream works incorrectly" << endl;
            return 3;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 4;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 5;
        }
    }

    {
        istringstream input1("1*2"), input2("1/"), input3("/4");
        Rational r1, r2, r3;
        input1 >> r1;
        input2 >> r2;
        input3 >> r3;
        bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
        if (!correct) {
            cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
                 << r1 << " " << r2 << " " << r3 << endl;

            return 6;
        }
    }

    cout << "OK" << endl;
	return 0;
}




/*
string as,sm;
	int num1, num2, i;
	while (getline(istr, as, '/')){
		sm.append(as);
		++i;
	}
	if (i!=0){
		istringstream ss(sm);
		ss >> num1;
		ss >> num2;
	}
//	Rational one(num1, num2);
*/


