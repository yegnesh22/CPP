#include <iostream>
#include <vector>
#include <list>

using namespace std;

struct s_MatchIndex {
	unsigned int start;
	unsigned int end;
};

bool findSubArr(vector<unsigned int> arr, list <struct s_MatchIndex*> &indices, unsigned long long S)
{
	unsigned long long sum;
	unsigned int sIndex;
	unsigned int eIndex;
	unsigned int index;
	bool found = false;

	index = 0;

	for (vector<unsigned int>::iterator it = arr.begin(); it != arr.end();
		it++, index++) {
		sIndex = index;
		eIndex = index;
		sum = 0;
		for (vector<unsigned int>::iterator subIter = it; subIter != arr.end();
			subIter++, eIndex++) {
			sum += *subIter;
			cout << "Elem : " << *it << "Sum : " << sum << endl;
			// 1. If the sum of elements goes beyond the match sum, stop the subarr summing up
			//    and continue with next subarray.
			// 2. If the sum of elements equals to the match sum, add the indices to the match
			//    list and break the substring identification.
			// 3. If the sum of elements is less than the match sum, continue to summing up.
			if (sum > S)
				break;
			else if (sum == S) {
				struct s_MatchIndex *m = new struct s_MatchIndex;
				m->start = sIndex;
				m->end = eIndex;
				indices.push_back(m);
				found = true;
				break;
			}
		}
	}
	cout << "found : " << found << endl;
	return found;
}

int main()
{
	// vector<unsigned int> arr({ 1, 2, 3, 7, 5 });
	vector<unsigned int> arr({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
	list <struct s_MatchIndex *> indices;
	unsigned long long S;
	struct s_MatchIndex *match;
	bool found = false;

	cin >> S;
	found = findSubArr(arr, indices, S);

	if (found == true) {
		for (list <struct s_MatchIndex *>::iterator it = indices.begin();
			it != indices.end(); it++) {
			match = *it;
			cout << "Elements in index: " << match->start << " - " << match->end << endl;
		}
	}

	return 0;
}