#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

class Complex {
private:
	double Real, Im;

public:
	Complex(double Real, double Im) {
		this->Real = Real;
		this->Im = Im;
	}
	
	double getRe() {
		return Real;
	}

	double getIm() {
		return Im;
	}


	virtual string Info() {
		string temp = "";
		std::ostringstream ostr;
		ostr << Real;
		ostr << "+i*";
		ostr << Im;
		return ostr.str();
	}

};

class ComplexResist : public Complex {
private:
	double Angle;

public:
	ComplexResist (double Real, double Im, double Angle) : Complex(Real, Im){
		this->Angle = Angle;
	}

	double absCoduct() {
		double a, b, res;
		a = 1 / getRe();
		b = 1 / getIm();
		return sqrt(a * a + b * b);
	}

	double argConduct() {
		return atan((1 / getRe()) * (1 / getRe()) + (1 / getIm()) * (1 / getIm()));
	}

	string Info() {
		string temp = "";
		std::ostringstream ostr;
		ostr << getRe();
		ostr << "+i*";
		ostr << getIm();
		ostr << "  ";
		ostr << Angle;
		ostr << " ";
		ostr << absCoduct();
		ostr << " ";
		ostr << argConduct();
		return ostr.str();
	}



};
int main()
{
	double Re, Im, Angle;
	cin >> Re >> Im >> Angle;
	Complex num(Re, Im);
	ComplexResist res(Re, Im, Angle);
	
	cout << num.Info() << endl;
	cout << res.Info() << endl;


	return 0;
}