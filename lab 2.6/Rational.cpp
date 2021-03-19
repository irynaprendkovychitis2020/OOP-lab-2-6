#include "Rational.h"
Rational::Pair::Pair()
{
    first = 0;
    second = 0;
}
Rational::Pair::Pair(int f = 0, int s = 0)
{
    first = f;
    second = s;
}
Rational::Pair::Pair(const Pair& r)
{
    first = r.first;
    second = r.second;
}
Rational::Pair::~Pair() { }

void Rational::Read()
{
    Pair pair1(1, 1), pair2(1, 1);
    cout << " pair (a,b) - ?"; cin >> pair1;
    cout << " ( a , b )";
    cout << pair1;

    cout << " pair (c,d) - ?"; cin >> pair2;
    cout << " ( c , d )";
    cout << pair2;

    Pair a = pair1 - pair2;
    cout << "(a, b) - (c, d) = (a - c), (b - d)";
    cout << a;

    if (pair1.equal(pair1, pair2))
        cout << "values  are equal " << endl;
    else
        cout << "values  are not equal" << endl;

    Display(pair1, pair2);

    Pair z(1, 1);
    cout << endl << endl;
    cout << " a  " << z << endl;
    cout << " a++  " << z++;
    cout << " a--  " << z--;
    cout << " ++a  " << ++z;
    cout << " --a  " << --z;
}

void Rational::Pair::Init(int F, int S)
{
    SetFirst(F);
    SetSecond(S);
}

Rational::Pair operator - (const Rational::Pair& a, const Rational::Pair& b)
{
    return Rational::Pair(a.first - b.first, a.second - b.second);
}

Rational::Pair& Rational::Pair::operator = (const Rational::Pair& r)
{
    first = r.first;
    second = r.second;
    return *this;
}
bool Rational::Pair::equal(Pair a, Pair b)
{

    if (a.first == b.first && a.second == b.second)
        return true;
    else
        return false;
}
ostream& operator << (ostream& out, const Rational::Pair& r)
{
    out << string(r);
    return out;
}

istream& operator >> (istream& in, Rational::Pair& r)
{
    cout << " "; in >> r.first;
    cout << " "; in >> r.second;
    r.Init(r.first, r.second);
    return in;
}

void Rational::Display(Pair pair1, Pair pair2)
{
    Rational l;
    cout << "(a, b) * (c, d) = (a * c), (b * d)" << endl;
    cout << " ( " << l.Multiply_1(pair1, pair2) << " , " << l.Multiply_2(pair1, pair2) << " )" << endl << endl;

    cout << "(a, b) - (c, d) = (a - c), (b - d)" << endl;
    cout << " ( " << l.Diff_1(pair1, pair2) << " , " << l.Diff_2(pair1.GetSecond(), pair2.GetSecond()) << " )" << endl;

    cout << "(a, b) + (c, d) = (ad + bc, bd)" << endl;
    cout << " ( " << l.Plus_1(pair1, pair2) << " , " << l.Plus_2(pair1, pair2) << " )" << endl << endl;

    cout << "(a, b) / (c, d) = (ad / bc)" << endl;
    cout << " ( " << l.div_1(pair1, pair2) << " , " << l.div_2(pair1, pair2) << " )" << endl << endl;
}

int Rational::Multiply_1(Pair a, Pair b) { return a.GetFirst() * b.GetFirst(); }

int Rational::Multiply_2(Pair a, Pair b) { return a.GetSecond() * b.GetSecond(); }

int Rational::Diff_1(Pair a, Pair b) { return a.GetFirst() * b.GetSecond() - a.GetSecond() * b.GetFirst(); }
int Rational::Diff_2(int a, int b) { return a * b; }

int Rational::Plus_1(Pair a, Pair b) { return a.GetFirst() * b.GetSecond() + a.GetSecond() * b.GetFirst(); }
int Rational::Plus_2(Pair a, Pair b) { return a.GetSecond() * b.GetSecond(); }

int Rational::div_1(Pair a, Pair b) { return a.GetFirst() * b.GetSecond(); }
int Rational::div_2(Pair a, Pair b) { return a.GetSecond() * b.GetFirst(); }

Rational::Pair::operator string () const
{
    stringstream sstr;
    sstr << endl << " ( " << first << " , " << second << " )" << endl << endl;
    return sstr.str();
}

Rational::Pair& Rational::Pair::operator ++()
{
    first++;
    return *this;
}
Rational::Pair& Rational::Pair::operator --()
{
    first--;
    return *this;
}
Rational::Pair Rational::Pair::operator ++(int)
{
    Pair t(*this);
    second++;
    return t;
}
Rational::Pair Rational::Pair::operator --(int)
{
    Pair t(*this);
    second--;
    return t;
}