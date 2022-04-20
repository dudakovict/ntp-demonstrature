# Specifikatori pristupa, princip apstrakcije i enkapsulacije
Zadatak se zasniva na dobivanju informacije o unesenoj IP adresi. Svaki uređaj spojen na mrežu ima svoju javnu IP adresu s kojom ostvaruje komunikaciju s ostalim uređajima. IP adresa sastoji se od 4 okteta odvojenih točkom (npr. 192.168.1.5). Isto tako postoje 5 razreda odnosno klasa **IP** gdje se za usporedbu gleda samo prvi oktet:
- A – od 1 do 127
- B – od 128 do 191
- C – od 192 do 223
- D – od 224 do 239
- E – od 240 do 255

Za potrebe ovoga zadatka uzmimo da su sve ostale vrijednosti nevaljane (manje od 1 ili veće od 255).
Definirajte klasu **IP** koja ima sljedeće atribute:
- Oktete **a**, **b**, **c** i **d** tipa **int**
- Metodu **print** koja pomoću okteta ispiše danu IP adresu u uobičajenom formatu gdje su okteti odvojeni točkom. Metoda ne prima nikakve argumente već sve oktete dobiva iz same instance objekta. Metoda ne vraća nikakav rezultat (void).
- Metodu **className** koja vraća jednu od 5 mogućih klasa IP adrese ili **"–"** ako je adresa neispravna. Metoda ne prima nikakve argumente već sve što joj je potrebno uzima iz instance objekta. Metoda vraća jedno slovo odnosno znak, stoga je povratni tip metode **char**.
```c++
class IP
{
public:
    int octet_A, octet_B, octet_C, octet_D;
    void print();
    char className();
};
```
Napišite  main funkciju  koja će od korisnika tražiti unos IP adrese na način da korisnik mora unijeti četiri okteta koji se pritom trebaju prenijeti u objekt klase **IP**. Funkcija zatim ispisuje IP adresu u njenom čitljivom obliku pomoću metode **print** te ispisuje kojoj klasi pripada.

---

Definirajte klasu **Datum** koja ima sljedeće atribute:
- Cjelobrojne atribute **dan**, **mjesec** i **godina**.
- Privatnu metodu **void ispis()** koja ispisuje datum u formatu **dan.mjesec.godina**.
- Javnu metodu **void postavi(int a, int b, int c)** koja postavlja datum na vrijednosti parametara **a**, **b** i **c**. Za **dan** dozvoljene vrijednosti su **0-30**, za **mjesec** **0-12** i za **godinu** **0-2022**. Ako su parametri neispravni datum se postavlja na **01.01.2020**. Nakon postavljanja, funkcija ispisuje postavljeno vrijeme koristeći funkciju **ispis**.
- Javnu metodu **void razlika(Datum a, Datum b)** koja izračuna i ispiše razliku između datuma **a** i **b** u danima.
```c++
class Datum
{
private:
    int dan, mjesec, godina;
    void ispis();

public:
    void postavi(int, int, int);
    void razlika(Datum, Datum);
};
```
Nadopunite glavni program s funkcijom koja od korisnika traži unos datuma rođenja i trenutnog datuma, te funkcijom koja ispisuje njegovu trenutnu starost (u danima). Radi jednostavnosti proračuna pretpostavljamo da sve godine imaju **365** dana.

---

Definirajte klasu **Kvadratna** koja služi za rješavanje kvadratne jednadžbe i ima sljedeće atribute:
- Koeficijente **a**, **b**, **c** te rezultate **x1** i **x2** tipa **double**.
- Metodu **calculate** koja pomoću koeficijenata izračunava kvadratnu jednadžbu i rješenja zapisuje u **x1** i **x2** atribute. Metoda ne prima nikakve argumente već sve što joj treba za izračun uzima iz atributa klase. Metoda ne vraća nikakvu vrijednost (void).
- Metodu **diskriminanta** koja izračunava diskriminantu kvadratne jednadžbe. Metoda ne prima nikakve argumente već sve što joj treba za izračun uzima iz atributa klase. Metoda vraća izračun tipa **double**.
```c++
class Kvadratna
{
public:
    double a, b, c, x1, x2;
    void calculate();

private:
    double diskriminanta();
};
```
Nadopunite glavni program s funkcijom koja od korisnika traži unos koeficijenata **a**, **b** i **c** te, pomoću klase **Kvadratna**, izračunava i ispisuje rezultat kvadratne jednadžbe.

Koeficijenti **a**, **b**, i **c** koje je korisnik unio trebaju biti postavljeni kao atributi klase. Nakon toga pomoću metode **calculate**, a interno i metode **diskriminanta**, vrši se izračun i u konačnici rezultati moraju biti u atributima **x1** i **x2** koje ispisujete kao rješenje.

Slika prikazuje kvadratnu jednadžbu. Diskriminanta je izraz ispod korijena.

![Quadratic Equation](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQV6KVC0dLauFCA6UqLlYevNv8F1EeiRX8gyA&usqp=CAU "Quadratic Equation")