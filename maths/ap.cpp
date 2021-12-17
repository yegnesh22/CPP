#include <iostream>

using namespace std;

int main()
{
	int A1, A2, AN;
	int D;
	int N;

	cin >> A1;
	cin >> A2;
	cin >> N;

	D = A2 - A1;
	AN = A1 + (N - 1) * D;

	cout << AN << endl;

	return 0;
}

