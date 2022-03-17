#include <iostream>
#include <list>
using namespace std;

void ucitajString(list<string> &L)
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

void ucitajInt(list<int> &L)
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

void rastaviDodaj(list<string> &L)
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

void ispisiString(list<string> L)
{
	cout << "\n";
	list<string>::iterator iter;

	for (iter = L.begin(); iter != L.end(); ++iter)
	{
		cout << *iter << " -> ";
	}
	cout << "\n\n";
}

void ispisiInt(list<int> L)
{
	cout << "\n";
	list<int>::iterator iter;

	for (iter = L.begin(); iter != L.end(); ++iter)
	{
		cout << *iter << " -> ";
	}
	cout << "\n\n";
}

void ispisiDouble(list<double> L)
{
	cout << "\n";
	list<double>::iterator iter;

	for (iter = L.begin(); iter != L.end(); ++iter)
	{
		cout << *iter << " -> ";
	}
	cout << "\n\n";
}

void ispisiChar(list<char> L)
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
	list<string> listaString;

	ucitajString(listaString);
	ispisiString(listaString);

	cout << "Zadatak 2.\n===========================================" << endl;
	list<int> listaInt;

	ucitajInt(listaInt);
	ispisiInt(listaInt);

	cout << "Zadatak 3.\n===========================================" << endl;
	list<double> listaDouble;
	double multiplikator;

	listaDouble.push_back(1.5);
	listaDouble.push_back(3.0);
	listaDouble.push_back(4.5);
	listaDouble.push_back(5.5);
	listaDouble.push_back(7.3);

	cout << "Unesite multiplikator: ";
	cin >> multiplikator;

	cout << "Lista prije mnozenja:";
	ispisiDouble(listaDouble);
	pomnozi(listaDouble, multiplikator);
	cout << "Lista nakon mnozenja:";
	ispisiDouble(listaDouble);

	cout << "Zadatak 4.\n===========================================" << endl;
	list<char> listaChar;

	listaChar.push_front('e');
	listaChar.push_front('d');
	listaChar.push_front('c');
	listaChar.push_front('b');
	listaChar.push_front('a');
	ispisiChar(listaChar);

	if (IsSorted(listaChar))
	{
		cout << "Lista je sortirana!\n\n";
	}
	else
	{
		cout << "Lista nije sortirana!\n\n";
	}

	cout << "Zadatak 5.\n===========================================" << endl;
	list<string> listaStringV2;

	ucitajString(listaStringV2);
	rastaviDodaj(listaStringV2);
	ispisiString(listaStringV2);

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
