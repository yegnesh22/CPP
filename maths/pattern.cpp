#include <iostream>

using namespace std;

int main()
{
	int N;

	cin >> N;

	for (int i = N; i > 0; i--) {
		for (int j = N; j > 0; j--) {
			for (int k = i; k > 0; k--)
				cout << j << " ";
		}
		cout << endl;
	}
	return 0;
}
