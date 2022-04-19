#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Razlomak
{
private:
    int m_brojnik;
    int m_nazivnik;
    void Skrati();

public:
    Razlomak() : m_brojnik(0), m_nazivnik(1) {}
    Razlomak(int brojnik, int nazivnik = 1)
    {
        m_brojnik = brojnik;
        m_nazivnik = nazivnik;
    }
    Razlomak operator+(const Razlomak &);
    Razlomak operator-=(const Razlomak &);
    friend ostream &operator<<(ostream &, const Razlomak &);
    Razlomak operator++();
    bool operator<(const Razlomak &);
};

void Razlomak::Skrati()
{
    int nManji, nVeci, nRez;
    nManji = (((abs(m_brojnik)) < (abs(m_nazivnik))) ? (abs(m_brojnik)) : (abs(m_nazivnik)));
    nVeci = (((abs(m_brojnik)) > (abs(m_nazivnik))) ? (abs(m_brojnik)) : (abs(m_nazivnik)));
    do
    {
        nRez = nVeci % nManji;
        nVeci = nManji;
        nManji = nRez;
    } while (nRez > 0);
    m_brojnik /= nVeci;
    m_nazivnik /= nVeci;
}

Razlomak Razlomak::operator+(const Razlomak &r)
{
    Razlomak temp((m_brojnik * r.m_nazivnik) + (r.m_brojnik * m_nazivnik), m_nazivnik * r.m_nazivnik);
    temp.Skrati();
    return temp;
}

Razlomak Razlomak::operator-=(const Razlomak &r)
{
    m_brojnik = (m_brojnik * r.m_nazivnik) - (r.m_brojnik * m_nazivnik);
    m_nazivnik = m_nazivnik * r.m_nazivnik;
    Skrati();
    return *this;
}

ostream &operator<<(ostream &os, const Razlomak &r)
{
    os << r.m_brojnik << "/" << r.m_nazivnik;
    return os;
}

Razlomak Razlomak::operator++()
{
    m_brojnik += m_nazivnik;
    return *this;
}

bool Razlomak::operator<(const Razlomak &r)
{
    return (((m_brojnik * r.m_nazivnik) - (m_nazivnik * r.m_brojnik)) > 0) ? true : false;
}

int main()
{
    Razlomak r1(1, 4);
    Razlomak r2(2, 6);
    cout << r1 << " " << r2 << endl;
    Razlomak r3 = r1 + r2;
    cout << r3 << endl;
    Razlomak r4(1, 5);
    r4 -= r1;
    cout << r4 << endl;
    ++r1;
    cout << r1 << endl;
    bool prviManji = r1 < r2;
    bool prviVeci = r2 < r1;
    // boolalpha dolazi iz iomanip library-a,
    // koristimo ga da se bool varijable printaju kao 'true' i 'false' umjesto '1' u '0'
    cout << boolalpha << prviManji << " " << prviVeci << endl;
    return 0;
}