#include <bits/stdc++.h>

using namespace std;

class NoDefaultConstructor
{
	public:
		NoDefaultConstructor( int num )	: number(num) {}

		int GetNumber() const { return number; }

	private:
		int number;
};



int main()
{
	NoDefaultConstructor* n = new NoDefaultConstructor();

	return 0;
}
