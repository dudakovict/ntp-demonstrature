#include <iostream>
#include <cmath>
using namespace std;

class Razlomak
{
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
};

void Razlomak::Skrati()
{
    int nManji, nVeci, nRez;
    nManji = (((abs(m_brojnik)) < (abs(m_nazivnik))) ? (abs(m_brojnik)) : (abs(m_nazivnik)));
    nVeci = (((abs(m_brojnik)) < (abs(m_nazivnik))) ? (abs(m_brojnik)) : (abs(m_nazivnik)));
    do
    {
        nRez = nVeci % nManji;
        nVeci = nManji;
        nManji = nRez;
    } while (nRez > 0);
    m_brojnik /= nVeci;
    m_nazivnik /= nVeci;
}

int main()
{
}