#include "Complex.h"

Complex::Complex() : Complex(0, 0) {
}

Complex::Complex(double real, double imag) {
	this->real_data = real;
	this->imag_data = imag;
}

bool Complex::is_real() const {
	return imag() == 0;
}

double Complex::real() const {
	return this->real_data;
}

double Complex::imag() const {
	return this->imag_data;
}

double Complex::abs() const {
	return sqrt(real() * real() + imag() * imag());
}

Complex Complex::conjugate() const {
	return { real(), -imag() };
}

Complex operator+(const Complex& l, const Complex& r)
{
	return { l.real() + r.real(),l.imag() + r.imag() };
}

Complex operator+(const Complex& l, double r)
{
	return { l.real() + r,l.imag() };
}

Complex operator+(double l, const Complex& r)
{
	return { l + r.real(),r.imag() };
}

Complex operator-(const Complex& obj)//unary
{
	return { -obj.real(),-obj.imag() };
}

Complex operator-(const Complex& l, const Complex& r)
{
	return { l.real() - r.real(),l.imag() - r.imag() };
}

Complex operator-(const Complex& l, double r)
{
	return { l.real() - r,l.imag() };
}

Complex operator-(double l, const Complex& r)
{
	return { l - r.real(),r.imag() };
}

Complex operator*(const Complex& l, const Complex& r)
{
	double real = l.real() * r.real() - l.imag() * r.imag();
	double imag = l.real() * r.imag() + l.imag() * r.real();
	return { real,imag };
}

Complex operator*(const Complex& l, double r)
{
	return { l.real() * r,l.imag() };
}

Complex operator*(double l, const Complex& r)
{
	return { l * r.real(),r.imag() };
}

bool operator==(const Complex& l, const Complex& r)
{
	return (l.real() == r.real() && l.imag() == r.imag());
}

bool operator!=(const Complex& l, const Complex& r)
{
	return (l.real() != r.real() || l.imag() != r.imag());
}

std::ostream& operator<<(std::ostream& out, const Complex& complex)
{
	if (complex.real() != 0)
	{
		out << complex.real();
		if (complex.imag() > 0)
		{
			out << " + " << complex.imag();
		}
		else if (complex.imag() < 0)
		{
			out << " - " << -complex.imag();
		}
		out << "i";
	}
	else
	{
		out << complex.imag();
	}
	return out;
}

Complex& Complex::operator++()
{
	this->real_data++;
	return (*this);
}

Complex Complex::operator++(int)
{
	return ++(*this);
}

Complex& Complex::operator--()
{
	this->real_data--;
	return (*this);
}

Complex Complex::operator--(int)
{
	return --(*this);
}

Complex& Complex::operator()(double real, double imag)
{
	this->real_data = real;
	this->imag_data = imag;
	return (*this);
}

