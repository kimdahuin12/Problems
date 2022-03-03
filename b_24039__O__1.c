#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char* argv[]) {
	int N;
	int res = 0;
	int prePrime = 0;
	scanf("%d", &N);
	int max = 10001;
	bool* noPrimeNum = (bool*)malloc(sizeof(bool) * max);
	for (int i = 0; i < max; i++)
	{
		noPrimeNum[i] = false;
	}
	noPrimeNum[0] = true; noPrimeNum[1] = true;

	for (int i = 2; i <= (max-1)/2; i++) {
		if (!noPrimeNum[i]) {//소수라면
			for (int j = i+i; j < max; j += i) {
				noPrimeNum[j] = true;
			}
			if (prePrime * i > N) {
				res = prePrime * i;
				break;
			}
			prePrime = i;
		}
	}

	printf("%d\n", res);
	return 0;
}
