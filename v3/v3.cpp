#include <iostream>
#include <list>
#include <fstream>
#include <string.h>

using namespace std;

struct vino
{
	int sifra;
	char naziv[16];
	double cijena;
};

// Zadatak 1.
list<vino> ispis(ifstream &infile)
{
	list<vino> vina;

	infile.open("listavina.dat", ios::binary | ios::in);
	if (!infile)
		return list<vino>();

	while (true)
	{
		vino temp;
		infile.read((char *)&temp, sizeof(temp));
		if (infile.eof())
			break;
		vina.push_back(temp);
	}

	for (list<vino>::iterator it = vina.begin(); it != vina.end(); it++)
	{
		cout << "Sifra: " << it->sifra << endl;
		cout << "Naziv: " << it->naziv << endl;
		cout << "Cijena: " << it->cijena << endl;
	}

	infile.close();

	return vina;
}

// 2. Zadatak
void unos(ofstream &outfile)
{
	vino temp;
	cout << "Sifra: ";
	cin >> temp.sifra;
	cin.ignore();
	cout << "Naziv: ";
	cin.getline(temp.naziv, 16);
	cout << "Cijena: ";
	cin >> temp.cijena;

	outfile.open("listavina.dat", ios::binary | ios::out | ios::app);
	if (!outfile)
		return;

	outfile.write((char *)&temp, sizeof(temp));

	outfile.close();
}

// 3. Zadatak
void izmjena_cijene(fstream &file, list<vino> &vina, int sifra, double cijena)
{
	vino temp;

	file.open("listavina.dat", ios::binary | ios::in | ios::out);
	if (!file)
		return;

	for (list<vino>::iterator it = vina.begin(); it != vina.end(); it++)
	{
		if (sifra == it->sifra)
		{
			it->cijena = cijena;
		}
	}

	file.seekg(0, ios::beg);

	while (!file.eof())
	{
		int pos = file.tellg();
		file.read((char *)&temp, sizeof(temp));
		if (sifra == temp.sifra)
		{
			temp.cijena = cijena;
			file.seekp(pos);
			file.write((char *)&temp, sizeof(temp));
			break;
		}
	}

	file.close();
}

// 4. Zadatak
void brisi(ifstream &infile, ofstream &outfile, list<vino> &vina, int sifra)
{
	for (list<vino>::iterator it = vina.begin(); it != vina.end(); it++)
	{
		if (sifra == it->sifra)
		{
			vina.erase(it);
		}
	}

	infile.open("listavina.dat", ios::binary | ios::in);
	outfile.open("novalista.dat", ios::binary | ios::out);
	if (!infile || !outfile)
		return;

	while (true)
	{
		vino temp;
		infile.read((char *)&temp, sizeof(temp));
		if (infile.eof())
			break;
		if (sifra != temp.sifra)
		{
			outfile.write((char *)&temp, sizeof(temp));
		}
	}

	infile.close();
	outfile.close();

	remove("listavina.dat");
	rename("novalista.dat", "listavina.dat");
}

bool usporedba(vino a, vino b)
{
	/* Ternarni operator
		return a.sifra < b.sifra ? true : false;
	*/

	if (a.sifra < b.sifra)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// 5. Zadatak
void sortiraj(ofstream &outfile, list<vino> &vina)
{
	vina.sort(usporedba);

	outfile.open("listavina.dat", ios::binary | ios::out);
	if (!outfile)
		return;

	outfile.clear();

	outfile.seekp(0, ios::beg);

	for (list<vino>::iterator it = vina.begin(); it != vina.end(); it++)
	{
		vino temp;
		temp.sifra = it->sifra;
		strcpy(temp.naziv, it->naziv);
		temp.cijena = it->cijena;

		outfile.write((char *)&temp, sizeof(temp));
	}

	outfile.close();
}

// Zadatak 6.
void zamjena_redoslijeda(ofstream &outfile, list<vino> &vina, int sifra_1, int sifra_2)
{
	list<vino>::iterator i1 = vina.begin();
	list<vino>::iterator i2 = vina.end();
	i2--;

	while (i1 != i2)
	{
		if ((i1->sifra == sifra_1 || i1->sifra == sifra_2) && (i2->sifra == sifra_1 || i2->sifra == sifra_2))
		{
			iter_swap(i1, i2);
			break;
		}
		else
		{
			if (i1->sifra != sifra_1 || i1->sifra != sifra_2)
				i1++;
			if (i2->sifra != sifra_1 || i2->sifra != sifra_2)
				i2--;
		}
	}

	outfile.open("listavina.dat", ios::binary | ios::out);
	if (!outfile)
		return;

	outfile.clear();

	outfile.seekp(0, ios::beg);

	for (list<vino>::iterator it = vina.begin(); it != vina.end(); it++)
	{
		vino temp;
		temp.sifra = it->sifra;
		strcpy(temp.naziv, it->naziv);
		temp.cijena = it->cijena;

		outfile.write((char *)&temp, sizeof(temp));
	}

	outfile.close();
}

int main()
{
	int izbor;
	list<vino> vina;
	ifstream infile;
	ofstream outfile;
	fstream file;
	do
	{
		cout << "1. Ispis liste vina" << endl;					   // ispo?etka u?ita sadr?aj datoteke u listu i ispi?e ga na zaslon
		cout << "2. Dodavanje novog vina na listu" << endl;		   // dodaje novo vino u listu i datoteku
		cout << "3. Izmjena cijene vina" << endl;				   // za jedno od vina na listi i u datoteci se mijenja ?ifra
		cout << "4. Brisanje vina sa liste" << endl;			   // vino sa upisanom sifrom se bri?e iz liste i datoteke
		cout << "5. Sortiranje liste vina po sifri" << endl;	   // sortiraju se podaci o vinima u listi i datoteci po sifri
		cout << "6. Zamjena redoslijede dva vina u listi" << endl; // mijenja redoslijed dva vina u listi i datoteci
		cout << "0. Izlaz" << endl
			 << endl;
		cout << "Izbor: ";
		cin >> izbor;
		switch (izbor)
		{
		case 1:
		{
			vina = ispis(infile);
			break;
		}
		case 2:
		{
			unos(outfile);
			break;
		}
		case 3:
		{
			int sifra;
			double cijena;
			cout << "Sifra: ";
			cin >> sifra;
			cout << "Cijena: ";
			cin >> cijena;
			izmjena_cijene(file, vina, sifra, cijena);
			break;
		}
		case 4:
		{
			int sifra;
			cout << "Sifra: ";
			cin >> sifra;
			brisi(infile, outfile, vina, sifra);
			break;
		}
		case 5:
		{
			sortiraj(outfile, vina);
			break;
		}
		case 6:
		{
			int sifra_1, sifra_2;
			cout << "Sifra 1: ";
			cin >> sifra_1;
			cout << "Sifra 2: ";
			cin >> sifra_2;
			zamjena_redoslijeda(outfile, vina, sifra_1, sifra_2);
			break;
		}
		}
	} while (izbor != 0);
	return 0;
}
