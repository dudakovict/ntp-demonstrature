# Nasljeđivanje, tipovi nasljeđivanja, višestruko nasljeđivanje
Deklarirane su klase **Pravokutnik**, **Kvadar** i **Kocka**. Klasa **Kvadar** sadrži 2 objekta klase **Pravokutnik** (**baza** i **stranica**), a klasa **Kocka** nasljeđuje klasu **Kvadar**.

```c++
class Pravokutnik
{
protected:
    double x_p, y_p;

public:
    Pravokutnik();
    Pravokutnik(double, double);
    friend ostream &operator<<(ostream &, const Pravokutnik &);
};
```
```c++
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
```
```c++
class Kocka : public Kvadar
{
public:
    Kocka();
    Kocka(Kvadar &);
    double volumen();
    double oplosje();
};
```

Implementirajte konstruktore bez parametara i sa parametrima za sve klase.

Definirajte metode za računanje oplošja i volumena za klasu **Kvadar**.

U main funkciji kreirajte po jedan objekt iz klase **Kvadar** i **Kocka** i izračunajte im oplošje i volumen.