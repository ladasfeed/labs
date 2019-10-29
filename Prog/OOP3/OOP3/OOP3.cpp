#include <iostream>
#include <sstream>

using namespace std;
class rectangle {
protected:
	double a, b;

public:
	virtual double getPerimeter() { return a+a+b+b; }
	virtual double getArea() { return a * b; }
	string Info();
	virtual void Multiply();
	rectangle(double a, double b);
	

	


};


string rectangle::Info() {
	string temp = "";
	std::ostringstream ostr;
	ostr << a;
	ostr << " ";
	ostr << b;
	ostr << " ";
	ostr << getPerimeter();
	ostr << " ";
	ostr << getArea();
	return ostr.str();
}

void rectangle::Multiply() {
	a *= 2;
	b *= 2;
}

rectangle::rectangle(double a, double b) {
	this->a = a;
	this->b = b;
}








class roundRectangle : public rectangle {
private:
	double r;

public:
	double getPerimeter();

	double getArea();

	void Multiply();

	roundRectangle(double a, double b, double r);
};

double roundRectangle::getPerimeter() {
	rectangle Ab(a, b);
	return Ab.getPerimeter() - 8 * r + 6.28 * r;
}

double roundRectangle::getArea() {
	rectangle Ab(a, b);
	return Ab.getArea() - 4 * r * r + 3.14 * r * r;
}

void roundRectangle::Multiply() {
	a *= 2;
	b *= 2;
	r *= 2;
}

roundRectangle::roundRectangle(double a, double b, double r) : rectangle(a, b) {
	this->r = r;
}



int main()
{
	rectangle rec(2, 3);
	roundRectangle fig(2, 3, 1);

	cout << rec.Info() << endl;
	cout << fig.Info() << endl << endl;

	rec.Multiply(); fig.Multiply();

	cout << rec.Info() << endl;
	cout << fig.Info();
}
