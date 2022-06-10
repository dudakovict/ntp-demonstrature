#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 10

struct najveci
{
    int operator()(int arr[])
    {
        return *max_element(arr, arr + MAX);
    }
};

struct najmanji
{
    int operator()(int arr[])
    {
        return count(arr, arr + MAX, *min_element(arr, arr + MAX));
    }
};

bool isPotencyOfTwo(int x)
{
    return x > 0 && ((x & (x - 1)) == 0);
}

struct potencije
{
    int operator()(int arr[])
    {
        return count_if(arr, arr + MAX, isPotencyOfTwo);
    }
};

int digitSum(int x)
{
    if (x == 0)
        return 0;
    int lastDigit = x % 10;
    return lastDigit + digitSum(x / 10);
}

struct najmanjaSuma
{
    int temp[MAX];
    int operator()(int arr[])
    {
        transform(arr, arr + MAX, temp, digitSum);
        int *idx = min_element(temp, temp + MAX);
        int smallest = arr[idx - temp];
        delete idx;
        return smallest;
    }
};

bool isNotTwoDigit(int x)
{
    return !(x > 9 && x < 100) && !(x < -9 && x > -100);
}

struct dvoznamenkasti
{
    int temp[MAX];

    int *operator()(int arr[])
    {
        copy_if(arr, arr + MAX, temp, isNotTwoDigit);
        return temp;
    }
};

template <class T>
struct print
{
    void operator()(T x)
    {
        cout << x << ", ";
    }
};

int main()
{
    int arr[MAX];
    for (int i = 0; i < MAX; i++)
    {
        cout << "arr[" << i << "]:";
        cin >> arr[i];
    }

    cout << "\nUneseni niz: [";
    for_each(arr, arr + MAX, print<int>());
    cout << "\b\b]" << endl;

    najveci nv;
    cout << "\nNajveci element niza: " << nv(arr) << endl;

    najmanji nm;
    cout << "Najmanji element u nizu se pojavljuje " << nm(arr) << " puta" << endl;

    potencije pot;
    cout << "U nizu cijelih brojeva ima " << pot(arr) << " broja koji su potencije broja 2" << endl;

    najmanjaSuma ns;
    cout << "Element sa najmanjom sumom znamenki: " << ns(arr) << endl;

    dvoznamenkasti dz;
    int *temp = dz(arr);
    int size = count_if(arr, arr + MAX, isNotTwoDigit);
    cout << "Elementi niza koji nisu dvoznamenkasti: [";
    for_each(temp, temp + size, print<int>());
    cout << "\b\b]" << endl;
    delete temp;
    return 0;
}