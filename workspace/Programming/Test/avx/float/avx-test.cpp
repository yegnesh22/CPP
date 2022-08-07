#include <bits/stdc++.h>
#include "input.h"
#include <immintrin.h>

#define ARRAY_SIZE(x) ((sizeof(x) / sizeof(x[0])))

using namespace std;

extern float a[INPUT_SIZE];
extern float b[INPUT_SIZE];

__m256 result;

int main()
{
	float s = 0;
	size_t ds = ARRAY_SIZE(a);
#ifdef __AVX__
	cout << "avx.." << endl;
	for (size_t i = 0; i < ds; i+= 8) {
		__m256 A = _mm256_loadu_ps(&a[i]);
		__m256 B = _mm256_loadu_ps(&b[i]);
		__m256 S = _mm256_add_ps(A, B);
		result = _mm256_add_ps(result, S);
	}

	s += _mm_extract_ps(result,0);
#else
	cout << "noavx.." << endl;
	for (size_t i = 0; i < ds; i++)
		s += a[i] + b[i];
#endif

	cout << "total sum:" << s << endl;
	return 0;
}
