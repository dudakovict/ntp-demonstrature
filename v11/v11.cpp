#include <iostream>
#include <string>
using namespace std;

#define MAX 1000

template <class T>
class stack
{
private:
    int pos, count;
    T data[MAX];

public:
    stack();
    void push(T);
    void pop();
    T top();
    int size();
};

template <class T>
stack<T>::stack() : pos(-1), count(0) {}

template <class T>
void stack<T>::push(T x)
{
    if (pos >= MAX - 1)
        return;
    data[++pos] = x;
    count++;
}

template <class T>
void stack<T>::pop()
{
    if (pos < 0)
        return;
    T x = data[pos--];
    count--;
}

template <class T>
T stack<T>::top()
{
    if (pos < 0)
        return 0;
    T x = data[pos];
    return x;
}

template <class T>
int stack<T>::size()
{
    return count;
}

int main()
{
    stack<int> stogIntova;
    stack<string> stogStringova;

    stogIntova.push(3);
    stogStringova.push("abc");

    int a = stogIntova.top();
    string b = stogStringova.top();

    stogIntova.pop();

    cout << "broj clanova: " << stogIntova.size() << endl;
    return 0;
}