#include <iostream>
#include <list>
using namespace std;

void ucitaj_string(list<string> &L)
{
	string str;

	while (true)
	{
		cout << "Unesite string: ";
		cin >> str;
		if (str == "kraj")
		{
			break;
		}
		L.push_back(str);
	}
}

void ucitaj_int(list<int> &L)
{
	int x;

	while (true)
	{
		cout << "Unesite broj: ";
		cin >> x;
		if (x == 0)
		{
			break;
		}
		if (x % 2 == 0)
		{
			L.push_back(x);
		}
		else
		{
			L.push_front(x);
		}
	}
}

void pomnozi(list<double> &L, double multiplikator)
{
	for (list<double>::iterator iter = L.begin(); iter != L.end(); ++iter)
	{
		*iter *= multiplikator;
	}
}

bool IsSorted(const list<char> &L)
{
	list<char> temp = L;

	temp.sort();

	return temp == L ? true : false;
}

void rastavi_dodaj(list<string> &L)
{
	for (list<string>::iterator iter = L.begin(); iter != L.end(); ++iter)
	{
		string s = *iter;
		for (int i = 0; i < s.size(); i++)
		{
			L.insert(iter, s.substr(i, 1));
		}
	}
}

void ispisi_string(list<string> L)
{
	cout << "\n";
	list<string>::iterator iter;

	for (iter = L.begin(); iter != L.end(); ++iter)
	{
		cout << *iter << " -> ";
	}
	cout << "\n\n";
}

void ispisi_int(list<int> L)
{
	cout << "\n";
	list<int>::iterator iter;

	for (iter = L.begin(); iter != L.end(); ++iter)
	{
		cout << *iter << " -> ";
	}
	cout << "\n\n";
}

void ispisi_double(list<double> L)
{
	cout << "\n";
	list<double>::iterator iter;

	for (iter = L.begin(); iter != L.end(); ++iter)
	{
		cout << *iter << " -> ";
	}
	cout << "\n\n";
}

void ispisi_char(list<char> L)
{
	cout << "\n";
	list<char>::iterator iter;

	for (iter = L.begin(); iter != L.end(); ++iter)
	{
		cout << *iter << " -> ";
	}
	cout << "\n\n";
}

int main()
{

	cout << "Zadatak 1.\n===========================================" << endl;
	list<string> lista_string;

	ucitaj_string(lista_string);
	ispisi_string(lista_string);

	cout << "Zadatak 2.\n===========================================" << endl;
	list<int> lista_int;

	ucitaj_int(lista_int);
	ispisi_int(lista_int);

	cout << "Zadatak 3.\n===========================================" << endl;
	list<double> lista_double;
	double multiplikator;

	lista_double.push_back(1.5);
	lista_double.push_back(3.0);
	lista_double.push_back(4.5);
	lista_double.push_back(5.5);
	lista_double.push_back(7.3);

	cout << "Unesite multiplikator: ";
	cin >> multiplikator;

	cout << "Lista prije mnozenja:";
	ispisi_double(lista_double);
	pomnozi(lista_double, multiplikator);
	cout << "Lista nakon mnozenja:";
	ispisi_double(lista_double);

	cout << "Zadatak 4.\n===========================================" << endl;
	list<char> lista_char;

	lista_char.push_front('e');
	lista_char.push_front('d');
	lista_char.push_front('c');
	lista_char.push_front('b');
	lista_char.push_front('a');
	ispisi_char(lista_char);

	if (IsSorted(lista_char))
	{
		cout << "Lista je sortirana!\n\n";
	}
	else
	{
		cout << "Lista nije sortirana!\n\n";
	}

	cout << "Zadatak 5.\n===========================================" << endl;
	list<string> lista_string_v2;

	ucitaj_string(lista_string_v2);
	rastavi_dodaj(lista_string_v2);
	ispisi_string(lista_string_v2);

	system("pause");
	return 0;
}

// Alternativno rješenje za IsSorted funckiju
bool IsSortedAlt(const list<char> &L)
{
	for (list<char>::const_iterator iter = L.begin(); iter != L.end();)
	{
		char tekuci = *iter;
		if (tekuci == L.back())
			break;
		else
		{
			char sljedeci = *++iter;
			if (tekuci > sljedeci)
			{
				return false;
			}
		}
	}
	return true;
}
