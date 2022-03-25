#include <iostream>
#include <list>
#include <fstream>
using namespace std;

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

void Stavka::ispis()
{
    cout << "\nNaziv proizvoda: " << naziv << "\nKolicina proizvoda: " << kolicina << endl;
}

Stavka Stavka::unos()
{
    Stavka s;
    cin.ignore();
    cout << "\nNaziv proizvoda: ";
    cin.getline(s.naziv, 30);
    cout << "Kolicina proizvoda: ";
    cin >> s.kolicina;
    return s;
}

void Stavka::promjeni(string naziv, list<Stavka> &stavke)
{
    for (list<Stavka>::iterator it = stavke.begin(); it != stavke.end(); it++)
    {
        if (naziv == it->naziv)
        {
            cin.ignore();
            cout << "\nNovi naziv proizvoda: ";
            cin.getline(it->naziv, 32);
            cout << "Nova kolicina proizvoda: ";
            cin >> it->kolicina;
            break;
        }
    }
}

void spremi_datoteku(ofstream &outfile, list<Stavka> &stavke)
{
    outfile.open("stavke.dat", ios::binary | ios::out | ios::app);
    if (!outfile)
        return;

    for (list<Stavka>::iterator it = stavke.begin(); it != stavke.end(); it++)
    {
        outfile.write((char *)&*it, sizeof(*it));
    }

    outfile.close();
    cout << "\nSpremljeno u datoteku!" << endl;
}

list<Stavka> ucitaj_datoteku(ifstream &infile)
{
    infile.open("stavke.dat", ios::binary | ios::in);
    if (!infile)
        return list<Stavka>();

    list<Stavka> stavke;

    while (true)
    {
        Stavka s;
        infile.read((char *)&s, sizeof(s));
        if (infile.eof())
            break;
        stavke.push_back(s);
    }

    infile.close();
    cout << "\nUcitano iz datoteke!" << endl;
    return stavke;
}

int main()
{
    int izbor;
    list<Stavka> stavke;
    Stavka s;
    ofstream outfile;
    ifstream infile;
    do
    {
        cout << "1. Ispis svih stavki\n2. Dodavanje nove stavke\n3. Promjena stavke\n4. Spremanje liste u datoteku\n5. Upis liste iz datoteke\n6. Izlaz" << endl;
        cout << "\nVas izbor: ";
        cin >> izbor;

        switch (izbor)
        {
        case 1:
        {
            for (list<Stavka>::iterator it = stavke.begin(); it != stavke.end(); it++)
            {
                it->ispis();
            }
            break;
        }
        case 2:
        {
            stavke.push_back(s.unos());
            break;
        }
        case 3:
        {
            string naziv;

            cout << "\nNaziv proizvoda za promjenu: ";
            cin >> naziv;

            s.promjeni(naziv, stavke);
            break;
        }
        case 4:
        {
            spremi_datoteku(outfile, stavke);
            break;
        }
        case 5:
        {
            stavke = ucitaj_datoteku(infile);
            break;
        }
        case 6:
        {
            cout << "\nIzlaz iz programa" << endl;
            break;
        }
        default:
        {
            cout << "\nKrivi unos!\n"
                 << endl;
            break;
        }
        }
        cout << endl;
    } while (izbor != 6);
    return 0;
}