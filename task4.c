#include <stdio.h>
#include <math.h>


unsigned short int mask(int nrBits) {
	unsigned short int ret = 0;
	nrBits = nrBits - 1;
	while (nrBits >= 0) {
		ret = (1 << nrBits) | ret;
		nrBits--;
	}
	return ret;
}

int main() {
	unsigned int inst;
	unsigned short int nre;
	char vecOperatii[9];
	int op, n, dim, rez, vecOperanzi[10];
	scanf("%u", &inst);
	n = (inst>>(29))+1;

	for (int i = 1; i <= n; i++) {
		op = (inst >> (29 - i*2)) & 0b11;
		vecOperatii[i-1] = op;
	}

	dim = ((inst >> (29 - (n * 2) - 4)) & 0b1111) + 1;

	rez = (int)(ceil((double)(((n+1)*dim))/16));

	// amount - cati operanzi incap in short
	int amount = 16 / dim;
	int cursor = 0;
	for (int i = 0; i < rez; i++) {
		scanf("%hu", &nre);
		for (int j = amount-1; j >= 0 && cursor < n + 1; j--) {
			vecOperanzi[cursor] =  (int)((nre >> dim*j) & mask(dim));
			cursor++;
		}
	}
	for (int i = 0; i < n; i++) { // * /
		if (vecOperatii[i] == 2) {
			vecOperanzi[i+1] *= vecOperanzi[i];
		} else if (vecOperatii[i] == 3) {
			vecOperanzi[i+1] = (vecOperanzi[i] / vecOperanzi[i+1]);
		}
	}
	for (int k = 0; k < n; k++) {
		while (k < n && vecOperatii[k] != 0 && vecOperatii[k] != 1) k++;
		int j = k;
		while (k < n && vecOperatii[k + 1] != 0 && vecOperatii[k + 1] != 1) k++;
		if (vecOperatii[j] == 0)
			vecOperanzi[k + 1] = vecOperanzi[j] + vecOperanzi[k + 1];
		else
			vecOperanzi[k + 1] = vecOperanzi[j] - vecOperanzi[k + 1];
	}

	printf("%d\n", vecOperanzi[n]);
	return 0;
}