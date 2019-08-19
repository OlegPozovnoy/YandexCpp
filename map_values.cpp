#include <iostream>
#include <sstream> 
#include <map>
#include <set>
#include <vector>
using namespace std;

class Rational {
public:
	Rational() {
		numerator = 0;
		denominator = 1;
		// � еализуйте конструктор по умолчанию
	}

	Rational(int numerator, int denominator) {
		// � еализуйте конструктор
		if (denominator < 0)
		{
			denominator /= -1;
			numerator /= -1;
		}

		if (denominator == 0)
			throw invalid_argument("Invalid argument");
		else {
			Rational::numerator = numerator / nod(numerator, denominator);
			Rational::denominator = denominator / nod(numerator, denominator);
		}

	}

	int Numerator() const {
		// � еализуйте этот метод
		return numerator;
	}

	int Denominator() const {
		// � еализуйте этот метод
		return denominator;
	}

private:
	// Добавьте поля

	int nod(int num, int den) {
		num = (num < 0) ? -num : num;
		den = (den < 0) ? -den : den;
		
		while (num  > 0 && den>0) {
			if (num > den)
				num %= den;
			else
				den %= num;
		}
		return num + den;


	}

	int numerator;
	int denominator;
};

bool operator==(const Rational & a1, const Rational &a2) {
	return(a1.Numerator() == a2.Numerator()) && (a1.Denominator() == a2.Denominator());
}

Rational operator+(const Rational & a1, const Rational &a2) {
	return Rational(a1.Numerator() * a2.Denominator() + a2.Numerator() * a1.Denominator(), a1.Denominator() * a2.Denominator());
}

Rational operator-(const Rational & a1, const Rational &a2) {
	return Rational(a1.Numerator() * a2.Denominator() - a2.Numerator() * a1.Denominator(), a1.Denominator() * a2.Denominator());
}

Rational operator*(const Rational & a1, const Rational &a2) {
	return Rational(a1.Numerator() * a2.Numerator() , a1.Denominator() * a2.Denominator());
}

Rational operator/(const Rational & a1, const Rational &a2) {

	if (a2.Numerator() == 0)
		throw domain_error("Division by zero");
	return Rational(a1.Numerator() * a2.Denominator() , a1.Denominator() * a2.Numerator());
}

istream& operator>>(istream& in, Rational & r) {
	
	string str;
	in >> str;

	if (str.length() == 0)
		return in;

	stringstream t(str);

	int numerator;
	int denominator;

	t >> numerator;
	t.ignore(1);
	t >> denominator;
	r = Rational(numerator, denominator);
	return in;
}

ostream& operator<<(ostream& out, const Rational & r){

	out << r.Numerator() << "/" << r.Denominator();
	return out;
}

bool operator<(const Rational& arg1, const Rational& arg2) {

	return arg1.Numerator() * arg2.Denominator() < arg2.Numerator() * arg1.Denominator();
}

int main() {
	Rational r1, r2;
	char act;


	try {
		cin >> r1 >> act >> r2;

		if (act == '+')
			cout << (r1 + r2);
		else if (act == '-')
			cout << r1 - r2;
		else if (act == '*')
			cout << r1 * r2;
		else if (act == '/')
			cout << r1 / r2;
	}
	catch (exception& e) {
		cout << e.what();
	}

	return 0;
}