# Konstruktor i destruktor, **this** pointer
Definirajte klasu **Node** koja predstavlja element ili čvor dvostruko vezane liste, dakle, varijabla **key** sadrži neku vrijednost, pokazivači **prev** i **next** sadrže adresu prethodnog odnosno sljedećeg člana u listi.
```c++
class Node
{
public:
    float key;
    Node *prev, *next;
    Node();
    Node(float val, Node *prev, Node *next);
    Node(const Node &);
};
```
Definirajte sljedeće elemente za klasu **Node**:
```c++
// Implementirajte defaultni konstruktor koji postavlja key na 0.0,
// a pokazivače na NULL
Node();
```
```c++ 
// Implementirajte konstruktor koji postavlja vrijednost key na val,
// i pokazivače Node::prev na prev odnosno Node::next na next
Node(float val, Node *prev, Node *next);
```
```c++ 
// Implementirajte kopirni konstruktor
Node(const Node &);
```
Napravite barem 3 dinamički alocirana objekta klase **Node** i postavite im proizvoljne vrijednosti na atribut **key**, a za **prev** i **next** odaberite adrese postojećih objekata. Za svaki objekt ispišite sadržaj varijable **key**, **prev** i **next** koristeći pristup preko pokazivača. Na kraju dealocirajte objekte iz memorije.

---

Definirajte klasu **Krug** koja se sastoji od **radijusa** (pokazivač na **float**).
```c++
class Krug
{
private:
    float *radius;
};
```
Klasa treba sadržavati i sljedeće elemente:
```c++
// Defaultni konstruktor koji dinamički alocira memoriju za radijus,
// i postavlja vrijednost atributa na 0
Krug();
```
```c++ 
// Konstruktor sa argumentima koji dinamički alocira memoriju za atribut
// i postavlja vrijednost atributa na vrijednost argumenta funcije
Krug(float r);
```
```c++ 
// Kopirni konstruktor
Krug(const Krug &);
```
```c++ 
// Destruktor koji dealocira memoriju
~Krug();
```
```c++ 
// set i get funkcije
void set_radius(float r) { *radius = r; };
float get_radius() { return *radius; };
```
```c++ 
// Funkciju print koja ispisuje vrijednost radijusa na ekran
void print();
```
U **main** funkciji treba demonstrirati rad svih elemenata klase. 