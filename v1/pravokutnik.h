#include <iostream>
using namespace std;

struct pravokutnik {
	double a, b;
};

double povrsina(pravokutnik P) {
	return P.a * P.b;
}

void povecaj_za(pravokutnik &P, double x) {
	P.a += x;
	P.b += x;
}

void smanji_za(pravokutnik &P, double x) {
	P.a -= x;
	P.b -= x;
}

void ispisi(pravokutnik P) {
	cout << "Stranica a: " << P.a << endl;
	cout << "Stranica b: " << P.b << endl;
}