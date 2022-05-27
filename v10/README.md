# Virtualne metode, polimorfizam, apstraktne klase
Neka su dane 3 klase koje opisuju geometrijski **lik**, **trokut**, **krug** i **pravilni poligon** kako je prikazano u kodu. Za svaku klasu implementirajte sljedeće.

Klasa **Tocka**

```c++
class Tocka
{
public:
    float x, y;
    Tocka();
    Tocka(float x, float y);
};
```

Klasa **Lik**
- Implementirajte funkciju ```status()``` koja će ispisivati informacije o objektu koji poziva u smislu radijusa upisane kružnice, površine i opsega. To napravite tako da unutar meotde pozivate odgovarajuče virtualne funkcije.

```c++
class Lik
{
public:
    void status();
    virtual float povrsina() = 0;
    virtual float opseg() = 0;
    virtual float radiusUpKruz() = 0;
};
```
Klasa **Trokut**
- Definirajte konstruktor koji prima referencu na 3 točke **A**, **B**, **C** i posatvlja ih kao vrhove trokuta.
- Definirajte virtualnu funkciju ```radiusUpKruz()``` koja vraća radijus kruga.
- Implementirajte virtualne funkcije za računanje opsega i površine trokuta.

```c++
class Trokut : public Lik
{
private:
    Tocka A, B, C;

public:
    Trokut();
    Trokut(Tocka &A, Tocka &B, Tocka &C);
    float radiusUpKruz();
    float opseg();
    float povrsina();
};
```

Klasa **Krug**
- Definirajte konstruktor koji prima referencu na točku središta **S** i duljinu radijusa **r**.
- Definirajte virtualnu funkciju ```radiusUpKruz()``` koja vraća radijus kruga.
- Impementirajte virtualne funkcije za računanje opsega i površine kruga.

```c++
class Krug : public Lik
{
private:
    Tocka S;
    float radius;

public:
    Krug();
    Krug(Tocka &S, float r);
    float radiusUpKruz();
    float opseg();
    float povrsina();
};
```

Klasa **PravilniPoligon**
- Definirajte konstruktor koji prima pokazivač na polje od **N** podataka klase **Tocka** i postavlja vrhove mnogokuta koristeći točke iz polja. Točke moraju tvoriti pravilni **N-terokut**.
- Definirajte virtualnu funkciju ```radiusUpKruz()``` koja vraća radijus upisane kružnice pravilnog **N-terokuta**.
- Implementirajte virtualne funkcije za računanje opsega i površine pravilnog mnogokuta.

```c++
class PravilniPoligon : public Lik
{
private:
    int N;
    Tocka *vrhovi;

public:
    PravilniPoligon();
    PravilniPoligon(Tocka *vrhovi, int N);
    float radiusUpKruz();
    float opseg();
    float povrsina();
};
```

Program testirajte tako da napravite barem jedan objekt svake klase.

Pokažite primjenu pozivanja virtualnih funkcija iz klasa koristeći pokazivač tipa bazne klase.