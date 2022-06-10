#include <iostream>
#include <ctype.h>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

template <class T, class U>
void print_pair(pair<T, U> p)
{
    cout << p.first << ": " << p.second << ", ";
}

int main()
{
    vector<pair<char, int>> znakovi;
    char c;
    while (true)
    {
        cout << "Upisite znak: ";
        cin >> c;

        if (c == '.' || c == '?' || c == '!')
            break;
        if (!isalpha(c))
            continue;

        auto el = find_if(znakovi.begin(), znakovi.end(), [c](const pair<char, int> &p)
                          { return p.first == c; });

        if (el != znakovi.end())
        {
            el->second++;
        }
        else
        {
            znakovi.push_back(make_pair(c, 1));
        }
    }
    cout << "[";
    for_each(znakovi.begin(), znakovi.end(), print_pair<char, int>);
    cout << "\b\b]" << endl;

    vector<pair<string, int>> rijeci;
    string s;
    int i = 0;
    while (true)
    {
        cout << "Upisite rijec: ";
        cin >> s;

        if (s == "kraj")
            break;
        rijeci.push_back(make_pair(s, ++i));
    }
    int counter = 0;
    vector<int> redni_brojevi;
    cout << "Upisite zadnju rijec: ";
    cin >> s;
    for (unsigned int i = 0; i < rijeci.size(); i++)
    {
        if (rijeci[i].first == s)
        {
            counter++;
            redni_brojevi.push_back(rijeci[i].second);
        }
    }
    if (counter > 0)
    {
        cout << "Rijec " << s << " je bila upisana " << counter << " puta i redni brojevi tih upisa su: [";
        for (int i = 0; i < redni_brojevi.size(); i++)
        {
            cout << redni_brojevi[i] << ", ";
        }
        cout << "\b\b]" << endl;
    }

    map<char, int> mapa_znakova;
    map<string, int> mapa_stringova;

    while (true)
    {
        cout << "Upisite rijec: ";
        cin >> s;

        if (s == "kraj")
            break;

        for (unsigned int i = 0; i < s.length(); i++)
        {
            char c = s[i];
            if (!isalpha(c))
                continue;
            auto p = mapa_znakova.find(c);
            if (p != mapa_znakova.end())
                p->second++;
            else
                mapa_znakova.insert(make_pair(c, 1));
        }

        auto p = mapa_stringova.find(s);
        if (p != mapa_stringova.end())
            p->second++;
        else
            mapa_stringova.insert(make_pair(s, 1));
    }

    auto znak = max_element(mapa_znakova.begin(), mapa_znakova.end(),
                            [](const pair<char, int> &p1, const pair<char, int> &p2)
                            { return p1.second < p2.second; });
    auto rijec = max_element(mapa_stringova.begin(), mapa_stringova.end(),
                             [](const pair<string, int> &p1, const pair<string, int> &p2)
                             { return p1.second < p2.second; });
    if (!mapa_znakova.empty() && !mapa_stringova.empty())
        cout << "Najcesci znak: " << znak->first << "\nNajcesca rijec: " << rijec->first << endl;
    return 0;
}