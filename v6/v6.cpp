#include <iostream>
using namespace std;

class Node
{
public:
    float key;
    Node *prev;
    Node *next;
    Node();
    Node(float val, Node *prev, Node *next);
    Node(const Node &x);
};

Node::Node() : key(0), prev(nullptr), next(nullptr) {}

Node::Node(float val, Node *prev, Node *next) : key(val), prev(prev), next(next) {}

Node::Node(const Node &x)
{
    key = x.key;
    prev = new Node(*(x.prev));
    next = new Node(*(x.next));
}

class Krug
{
private:
    float *radius;

public:
    Krug();
    Krug(float r);
    Krug(const Krug &k);
    ~Krug();
    void set_radius(float r) { *radius = r; };
    float get_radius() { return *radius; };
    void print();
};

Krug::Krug() : radius(new float(0)) {}

Krug::Krug(float r) : radius(new float(r)) {}

Krug::Krug(const Krug &k)
{
    radius = new float(*(k.radius));
}

Krug::~Krug()
{
    delete radius;
}

void Krug::print()
{
    cout << "Radius: " << get_radius() << endl;
}

int main()
{
    Node *n1 = new Node();
    n1->key = 10;
    Node *n2 = new Node();
    n2->key = 20;
    Node *n3 = new Node();
    n3->key = 30;
    n1->prev = n3;
    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;
    n3->next = n1;

    cout << "n1: " << n1->key << " " << n1->prev << " " << n1->next << endl;
    cout << "n2: " << n2->key << " " << n2->prev << " " << n2->next << endl;
    cout << "n3: " << n3->key << " " << n3->prev << " " << n3->next << endl;

    delete n1;
    delete n2;
    delete n3;

    Krug k1;
    Krug k2(5.0);
    Krug k3(k2);
    k1.print();
    k2.print();
    k3.print();

    system("PAUSE");
    return 0;
}