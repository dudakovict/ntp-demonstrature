#include <iostream>
#include <math.h>
using namespace std;

class Krug
{
protected:
	double radius;

public:
	Krug(double r = 0);
	double povrsina() const;
};

Krug::Krug(double r) : radius(r) {}

double Krug::povrsina() const
{
	return pow(radius, 2) * 3.14;
}

class Stozac : public Krug
{
private:
	double height;

public:
	Stozac();
	Stozac(double, double);
	Stozac(Krug &, double);
	double volumen() const;
};

Stozac::Stozac() : Krug(0), height(0) {}
Stozac::Stozac(Krug &k, double h) : Krug(k), height(h) {}
Stozac::Stozac(double r, double h) : Krug(r), height(h) {}

double Stozac::volumen() const
{
	return povrsina() * height / 3;
}

class Kugla : public Krug
{
public:
	Kugla();
	Kugla(Krug &);
	Kugla(double);
	double volumen() const;
};

Kugla::Kugla() : Krug(0) {}
Kugla::Kugla(Krug &k) : Krug(k) {}
Kugla::Kugla(double r) : Krug(r) {}

double Kugla::volumen() const
{
	return 4 / 3 * pow(radius, 3) * 3.14;
}

int main()
{
	Krug kr(5.2);
	cout << "Povrsina kruga: " << kr.povrsina() << endl;

	Stozac st(kr, 5.8);
	cout << "Volumen stosca: " << st.volumen() << endl;

	Kugla ku(3.5);
	cout << "Volumen kugle: " << ku.volumen() << endl;

	return 0;
}
