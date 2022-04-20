# Pokazivači, Vezana lista
- Napišite program koji učitava i stavlja na kraj liste stringove sve dok se ne učita string **"kraj"**.
- Napišite program koji učitava i stavlja na kraj liste parne brojeve, a na početak liste neparne brojeve. Unos se završava kada se upiše **0**.
- Napišite funkciju: 
  ```c++
  void pomnozi(list <double> L, double mulitplikator)
  ```
  kojom se svi elementi liste **L** množe s vrijednošću parametra **multiplikator**.
- Lista sadrži niz znakova. Napišite funkciju:
  ```c++
  bool IsSorted(const list<char>& L)
  ```
  koja vraća **true** ako su elementi liste sortirani uzlazno, inače vraća **false**. 
- Napišite program koji ispred svakog stringa **S** u listi dodaje još onoliko čvorova koliko **S** ima slova, u svaki od čvorova upišite po jedno slovo od **S**. 
  Na primjer, ako je učitana lista bila ```["NTP", "Jupi"]```, onda rezultantna lista treba biti ```["N", "T", "P", "NTP", "J", "u", "p", "i", "Jupi"]```.