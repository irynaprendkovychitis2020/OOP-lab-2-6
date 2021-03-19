#pragma once
#include <iostream>
#include <sstream>

using namespace std;

class Rational
{
public:
	class Pair
	{
	private:
		int first;
		int second;
	public:
		Pair();
		Pair(int, int);
		Pair(const Pair&);
		~Pair();

		int GetFirst() const { return first; }
		int GetSecond() const { return second; }

		void SetFirst(int first) { this->first = first; };
		void SetSecond(int second) { this->second = second; };

		void Init(int F, int S);
		Pair& operator = (const Pair&);
		operator string() const;
		friend ostream& operator << (ostream&, const Pair&);
		friend istream& operator >> (istream&, Pair&);
		friend Pair operator - (const Pair&, const Pair&);
		bool equal(Pair a, Pair b);

		Pair& operator ++();
		Pair& operator --();
		Pair operator ++(int);
		Pair operator --(int);
	};
	int Multiply_1(Pair a, Pair b);
	int Multiply_2(Pair a, Pair b);
	int Diff_1(Pair a, Pair b);
	int Diff_2(int a, int b);
	int Plus_1(Pair a, Pair b);
	int Plus_2(Pair a, Pair b);
	int div_1(Pair a, Pair b);
	int div_2(Pair a, Pair b);
	void Read();
	void Display(Pair pair1, Pair pair2);
};