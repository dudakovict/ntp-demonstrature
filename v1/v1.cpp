#include <iostream>
#include "pravokutnik.h"
using namespace std;

int main()
{
    pravokutnik P = {2, 4};
    cout << povrsina(P) << endl;
    povecaj_za(P, 3);
    smanji_za(P, 2);
    ispisi(P);
    system("pause");
    return 0;
}