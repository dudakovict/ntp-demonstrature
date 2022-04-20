# Preopterećenje operatora, prijatelji klase
Deklarirana je klasa **Razlomak**, kojom se definira objekt razlomka određen cjelobrojnim brojnikom i nazivnikom. Predložak zadatka nalazi se u [template.cpp](template.cpp) datoteci.
```c++
class Razlomak
{
    int m_brojnik;
    int m_nazivnik;

public:
    Razlomak() : m_brojnik(0), m_nazivnik(1) {}
    Razlomak(int brojnik, int nazivnik = 1)
    {
        m_brojnik = brojnik;
        m_nazivnik = nazivnik;
    }
};
```
Preopteretite sljedeće operatore za klasu **Razlomak**:
```c++
// Ovaj operator zbraja dva razlomka
Razlomak operator+(const Razlomak &);
```
```c++ 
// Ovaj operator umanjuje prvi razlomak za vrijednost drugog
Razlomak operator-=(const Razlomak &);
```
```c++ 
// Ovaj operator ispisuje razlomak
friend ostream &operator<<(ostream &, const Razlomak &);
```
```c++ 
// Ovo je prefiksni operator koji uvećava vrijednost razlomka za 1
Razlomak operator++();
```
```c++
// Ovaj operator uspoređuje dali je prvi razlomak manji od drugog 
bool operator<(const Razlomak &);
```
Napišite **main** funkciju u kojoj trebate demonstrirati rad svih operatera.