# Osnovni koncepti OOP
Napišite program za upravljanje listom za kupnju. U programu treba biti definirana klasa **Stavka** koja predstavlja jednu stavku liste za kupnju koja se sastoji od naziva proizvoda i količine. Klasa treba sadržavati i funkciju za unos nove stavke, ispis stavke i promjenu stavke.
```c++
class Stavka
{
private:
    char naziv[30];
    int kolicina;

public:
    void ispis();
    Stavka unos();
    void promjeni(string, list<Stavka> &);
};
```
## Program preko izbornika treba omogućiti slijedeće opcije
-  Ispisivanje svih stavki
-  Dodavanje nove stavke 
-  Promjena stavke
-  Spremanje liste u datoteku
-  Upis liste iz datoteke
-  Izlaz

Sve stavke se u programu moraju čuvati u listi (koristiti predložak liste iz **STL-a**), a kad se odabere opcija za spremanje u datoteku podaci se upisuju u binarnu datoteku.