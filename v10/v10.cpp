#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.1415926535

class Tocka
{
public:
    float x, y;
    Tocka();
    Tocka(float x, float y);
};

Tocka::Tocka() : x(0), y(0) {}
Tocka::Tocka(float x, float y) : x(x), y(y) {}

class Lik
{
public:
    void status();
    virtual float povrsina() = 0;
    virtual float opseg() = 0;
    virtual float radiusUpKruz() = 0;
};

void Lik::status()
{
    cout << "Povrsina: " << povrsina() << "\nOpseg: " << opseg() << "\nRadius: " << radiusUpKruz() << endl;
}

class Trokut : public Lik
{
private:
    Tocka A, B, C;

public:
    Trokut();
    Trokut(Tocka &A, Tocka &B, Tocka &C);
    float radiusUpKruz();
    float opseg();
    float povrsina();
};

Trokut::Trokut() : A(0, 0), B(0, 0), C(0, 0) {}
Trokut::Trokut(Tocka &A, Tocka &B, Tocka &C) : A(A), B(B), C(C) {}

float Trokut::radiusUpKruz()
{
    float a = sqrt((pow(B.x - C.x, 2) + pow(B.y - C.y, 2)));
    float b = sqrt((pow(A.x - C.x, 2) + pow(A.y - C.y, 2)));
    float c = sqrt((pow(A.x - B.x, 2) + pow(A.y - B.y, 2)));

    float s = (a + b + c) / 2;

    return sqrt(((s - a) * (s - b) * (s - c)) / 2);
}

float Trokut::opseg()
{
    float a = sqrt((pow(B.x - C.x, 2) + pow(B.y - C.y, 2)));
    float b = sqrt((pow(A.x - C.x, 2) + pow(A.y - C.y, 2)));
    float c = sqrt((pow(A.x - B.x, 2) + pow(A.y - B.y, 2)));

    return a + b + c;
}

float Trokut::povrsina()
{
    float aSquare = pow(B.x - C.x, 2) + pow(B.y - C.y, 2);
    float bSquare = pow(A.x - C.x, 2) + pow(A.y - C.y, 2);
    float cSquare = pow(A.x - B.x, 2) + pow(A.y - B.y, 2);

    float a = sqrt(aSquare);
    float b = sqrt(bSquare);
    float c = sqrt(cSquare);

    float alpha = acos((bSquare + cSquare - aSquare) / (2 * b * c)) * 180 / PI;
    float beta = acos((aSquare + cSquare - bSquare) / (2 * a * c)) * 180 / PI;
    float gamma = acos((aSquare + bSquare - cSquare) / (2 * a * b)) * 180 / PI;

    float h = b * sin(gamma);

    return (a * h) / 2;
}

class Krug : public Lik
{
private:
    Tocka S;
    float radius;

public:
    Krug();
    Krug(Tocka &S, float r);
    float radiusUpKruz();
    float opseg();
    float povrsina();
};

Krug::Krug() : S(0, 0), radius(0) {}
Krug::Krug(Tocka &S, float r) : S(S), radius(r) {}

float Krug::radiusUpKruz()
{
    return radius;
}

float Krug::opseg()
{
    return 2 * PI * radius;
}

float Krug::povrsina()
{
    return PI * pow(radius, 2);
}

class PravilniPoligon : public Lik
{
private:
    int N;
    Tocka *vrhovi;

public:
    PravilniPoligon();
    PravilniPoligon(Tocka *vrhovi, int N);
    float radiusUpKruz();
    float opseg();
    float povrsina();
};

PravilniPoligon::PravilniPoligon() : N(0), vrhovi(nullptr) {}
PravilniPoligon::PravilniPoligon(Tocka *vrhovi, int N) : vrhovi(vrhovi), N(N) {}

float PravilniPoligon::radiusUpKruz()
{
    float d = sqrt((pow(vrhovi[0].x - vrhovi[1].x, 2) + pow(vrhovi[0].y - vrhovi[1].y, 2)));

    return d / (2 * tan(PI / N));
}

float PravilniPoligon::opseg()
{
    float d = sqrt((pow(vrhovi[0].x - vrhovi[1].x, 2) + pow(vrhovi[0].y - vrhovi[1].y, 2)));

    return N * d;
}

float PravilniPoligon::povrsina()
{
    float d = sqrt((pow(vrhovi[0].x - vrhovi[1].x, 2) + pow(vrhovi[0].y - vrhovi[1].y, 2)));
    float cot = 1 / tan(PI / N);

    return 1 / float(4) * N * pow(d, 2) * cot;
}

int main()
{
    Tocka A(2, 3);
    Tocka B(5, 1);
    Tocka C(2, 4);

    Trokut T(A, B, C);
    T.status();

    Krug K(A, 3);
    K.status();

    int N = 3;
    Tocka *vrhovi = new Tocka[N];
    vrhovi[0] = A;
    vrhovi[1] = B;
    vrhovi[2] = C;

    PravilniPoligon P(vrhovi, N);
    P.status();

    Lik *L[N] = {&T, &K, &P};
    for (int i = 0; i < N; i++)
    {
        L[i]->status();
    }
    return 0;
}