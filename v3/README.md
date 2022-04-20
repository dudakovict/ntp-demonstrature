# Datoteke
Napisati program koji radi sa listom vina u binarnoj datoteci [listavina.dat](listavina.dat). Svako vino sadrži šifru, naziv i cijenu. Predložak zadatka nalazi se u [template.cpp](template.cpp) datoteci.
```c++
struct vino
{
    int sifra;
    char naziv[16];
    float cijena;
};
```
## Potrebno je dopisati slijedeće funkcionalnosti u program:
- Učitavanje sadržaja datoteke u listu i ispis ga na zaslon
- Dodavanje novog vina na listu (i u datoteku)
- Izmjena cijene vina (u listi i datoteci)
- Brisanje vina sa liste (u listi i datoteci)
- Sortiranje liste vina po sifri (u listi i datoteci)
- Zamjena redoslijede dva vina u listi (i datoteci)