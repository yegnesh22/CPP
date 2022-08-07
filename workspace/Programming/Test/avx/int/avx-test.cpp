#include <bits/stdc++.h>
#include <smmintrin.h>
#include <immintrin.h>
#include "input.h"

#define ARRAY_SIZE(x) ((sizeof(x) / sizeof(x[0])))

using namespace std;

extern unsigned int a[INPUT_SIZE];
extern unsigned int b[INPUT_SIZE];

int main()
{
	long long s = 0;
	size_t ds = ARRAY_SIZE(a);
#ifdef __AVX__
	__m128i result = _mm_setr_epi32(0, 0, 0, 0);
	cout << "avx.." << endl;
	for (size_t i = 0; i < ds; i+= 4) {
		__m128i A = _mm_load_si128((__m128i*)&a[i]);
		__m128i B = _mm_load_si128((__m128i*)&b[i]);
		__m128i S = _mm_add_epi32(A, B);
		result = _mm_add_epi32(result, S);
	}

	s += _mm_extract_epi32(result, 0);
	s += _mm_extract_epi32(result, 1);
	s += _mm_extract_epi32(result, 2);
	s += _mm_extract_epi32(result, 3);
#else
	cout << "noavx.." << endl;
	for (size_t i = 0; i < ds; i++)
		s += a[i] + b[i];
#endif

	cout << "total sum:" << s << endl;
	return 0;
}
