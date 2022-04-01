#include <iostream>
#include <math.h>
using namespace std;

class IP
{
public:
    int octet_A, octet_B, octet_C, octet_D;
    void print();
    char className();
};

void IP::print()
{
    cout << this->octet_A << "." << this->octet_B << "." << this->octet_C << "." << this->octet_D << endl;
}

char IP::className()
{
    char cn;

    switch (octet_A)
    {
    case 1 ... 127:
    {
        cn = 'A';
        break;
    }
    case 128 ... 191:
    {
        cn = 'B';
        break;
    }
    case 192 ... 223:
    {
        cn = 'C';
        break;
    }
    case 224 ... 239:
    {
        cn = 'D';
        break;
    }
    case 240 ... 255:
    {
        cn = 'E';
        break;
    }
    default:
    {
        cn = '-';
        break;
    }
    }

    return cn;
}

class Datum
{
private:
    int dan, mjesec, godina;
    void ispis();

public:
    void postavi(int, int, int);
    void razlika(Datum, Datum);
};

void Datum::ispis()
{
    cout << dan << "." << mjesec << "." << godina << endl;
}

void Datum::postavi(int a, int b, int c)
{
    if ((a < 1 || a > 30) || (b < 1 || b > 12) || (c < 1 || c > 2022))
    {
        dan = 1;
        mjesec = 1;
        godina = 2022;
    }
    else
    {
        dan = a;
        mjesec = b;
        godina = c;
    }

    ispis();
}

void Datum::razlika(Datum a, Datum b)
{
    int godine = abs(a.godina - b.godina);
    int mjeseci = abs(a.mjesec - b.mjesec);
    int dani = abs(a.dan - b.dan);

    cout << dani + (mjeseci * 30) + (godine * 365) << endl;
}

class Kvadratna
{
public:
    double a, b, c, x1, x2;
    void calculate();

private:
    double diskriminanta();
};

void Kvadratna::calculate()
{
    double D = diskriminanta();

    if (D < 0)
    {
        D *= -1;
    }

    x1 = (-b + sqrt(D)) / (2 * a);
    x2 = (-b - sqrt(D)) / (2 * a);
}

double Kvadratna::diskriminanta()
{
    return pow(b, 2) - (4 * a * c);
}

int main()
{
    cout << "===========================================" << endl;
    cout << "                ZADATKAK 1                 " << endl;
    cout << "===========================================" << endl;

    int A, B, C, D;

    cout << "Unesite oktet A: ";
    cin >> A;
    cout << "Unesite oktet B: ";
    cin >> B;
    cout << "Unesite oktet C: ";
    cin >> C;
    cout << "Unesite oktet D: ";
    cin >> D;

    IP ip = {A, B, C, D};

    cout << "\nIP adresa: ";
    ip.print();
    cout << "IP klasa: " << ip.className() << endl;

    cout << "\n===========================================" << endl;
    cout << "                ZADATKAK 2                 " << endl;
    cout << "===========================================" << endl;

    int dr_dan, dr_mjesec, dr_godina, tr_dan, tr_mjesec, tr_godina;

    cout << "Unesite dan datuma rodenja: ";
    cin >> dr_dan;
    cout << "Unesite mjesec datuma rodenja: ";
    cin >> dr_mjesec;
    cout << "Unesite godinu datuma rodenja: ";
    cin >> dr_godina;
    cout << "\nUnesite trenutan dan: ";
    cin >> tr_dan;
    cout << "Unesite trenutan mjesec: ";
    cin >> tr_mjesec;
    cout << "Unesite trenutnu godinu: ";
    cin >> tr_godina;
    cout << endl;

    Datum a, b;
    a.postavi(dr_dan, dr_mjesec, dr_godina);
    b.postavi(tr_dan, tr_mjesec, tr_godina);
    cout << "\nStarost osobe (u danima): ";
    a.razlika(a, b);

    cout << "\n===========================================" << endl;
    cout << "                ZADATKAK 3                 " << endl;
    cout << "===========================================" << endl;

    double koef_a, koef_b, koef_c;

    cout << "Unesite koeficijent a: ";
    cin >> koef_a;
    cout << "Unesite koeficijent b: ";
    cin >> koef_b;
    cout << "Unesite koeficijent c: ";
    cin >> koef_c;
    Kvadratna k = {koef_a, koef_b, koef_c};
    k.calculate();
    cout << "\nx1: " << k.x1 << "\nx2: " << k.x2 << endl;

    return 0;
}