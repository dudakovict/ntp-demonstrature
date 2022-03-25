#include <iostream>
#include <fstream>
#include <list>
using namespace std;

struct vino
{
    int sifra;
    char naziv[16];
    float cijena;
};

int main()
{
    int izbor;
    vino temp;
    list<vino> podaci;
    fstream dat("listavina.dat", ios::in | ios::out | ios::binary);
    dat.seekg(0, ios::beg);
    dat.read((char *)&temp, sizeof(vino));
    while (!dat.eof())
    {
        podaci.push_back(temp);
        cout << temp.sifra << " " << temp.naziv << " " << temp.cijena << endl;
        dat.read((char *)&temp, sizeof(vino));
    }
    dat.close();
    dat.open("listavina.dat", ios::in | ios::out | ios::binary);
    do
    {
        cout << "===========================" << endl;
        cout << "1. Ispis liste vina" << endl;                     // ispocetka ucita sadrzaj datoteke u listu i ispise ga na zaslon
        cout << "2. Dodavanje novog vina na listu" << endl;        // dodaje novo vino u listu i datoteku
        cout << "3. Izmjena cijene vina" << endl;                  // za jedno od vina na listi i u datoteci se mijenja sifra
        cout << "4. Brisanje vina sa liste" << endl;               // vino sa upisanom sifrom se brise iz liste i datoteke
        cout << "5. Sortiranje liste vina po sifri" << endl;       // sortiraju se podaci o vinima u listi i datoteci po sifri
        cout << "6. Zamjena redoslijede dva vina u listi" << endl; // mijenja redoslijed dva vina u listi i datoteci
        cout << "0. Izlaz" << endl
             << endl;
        cout << "Izbor: ";
        cin >> izbor;
        switch (izbor)
        {
        case 1:
            // code block
            break;
        case 2:
            // code block
            break;
        case 3:
            // code block
            break;
        case 4:
            // code block
            break;
        case 5:
            // code block
            break;
        case 6:
            // code block
            break;
        }

    } while (izbor != 0);

    return 0;
}
