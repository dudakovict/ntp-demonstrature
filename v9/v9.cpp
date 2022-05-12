#include <iostream>
using namespace std;

class Pravokutnik
{
protected:
    double x_p, y_p;

public:
    Pravokutnik();
    Pravokutnik(double, double);
    friend ostream &operator<<(ostream &, const Pravokutnik &);
};

Pravokutnik::Pravokutnik() : x_p(0), y_p(0) {}
Pravokutnik::Pravokutnik(double x, double y) : x_p(x), y_p(y) {}

ostream &operator<<(ostream &os, const Pravokutnik &p)
{
    os << p.x_p << " " << p.y_p;
    return os;
}

class Kvadar : public Pravokutnik
{
protected:
    double z_kv;

public:
    Kvadar();
    Kvadar(Pravokutnik &, double);
    double volumen();
    double oplosje();
};

Kvadar::Kvadar() : Pravokutnik(), z_kv(0) {}
Kvadar::Kvadar(Pravokutnik &p, double z) : Pravokutnik(p), z_kv(z) {}

double Kvadar::volumen()
{
    return x_p * y_p * z_kv;
}

double Kvadar::oplosje()
{
    return 2 * ((x_p * y_p) + (x_p * z_kv) + (y_p * z_kv));
}

class Kocka : public Kvadar
{
public:
    Kocka();
    Kocka(Kvadar &);
    double volumen();
    double oplosje();
};

Kocka::Kocka() : Kvadar() {}
Kocka::Kocka(Kvadar &k) : Kvadar(k) {}

double Kocka::volumen()
{
    return x_p * x_p * x_p;
}

double Kocka::oplosje()
{
    return 6 * x_p * x_p;
}

int main()
{

    Pravokutnik p1;
    Pravokutnik p2(10, 5);

    cout << p1 << endl;
    cout << p2 << endl;

    Kvadar kv(p2, 6);
    cout << "Volumen kvadra: " << kv.volumen() << endl;
    ;
    cout << "Oplosje kvadra: " << kv.oplosje() << endl;

    Kocka k(kv);
    cout << "Volumen kocke: " << k.volumen() << endl;
    ;
    cout << "Oplosje kocke: " << k.oplosje() << endl;

    return 0;
}
