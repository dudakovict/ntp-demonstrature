# Odnosi između klasa
Deklarirane su klase **Krug**, **Stozac** i **Kugla** koje predstavljaju geomotrijski lik kruga i geometrijska tijela stošca i kugle.
```c++
class Krug
{
protected:
	double radius;

public:
	Krug(double r = 0);
	double povrsina() const;
};
```
```c++
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
```
```c++
class Kugla : public Krug
{
public:
	Kugla();
	Kugla(Krug &);
	Kugla(double);
	double volumen() const;
};
```
Odredite koja je klasa bazna klasa, a koje su nasljeđenje klase i dodajte nasljeđivanje u predložak, te u skladu s tim implementirajte konstruktore za sve tri klase.

Definirajte metode koje računaju površinu, odnosno i volumen odgovarajućeg geometrijskog lika ili tijela u svakoj klasi.

Napravite u glavnom programu primjer u kojem imate barem po jedan objekt svake klase i za sve njih ispišite njihovu površinu odnosno volumen.