#include <stdio.h>
#include <math.h>


// pe parcursul programului am adaugst un //ex: ca sa se vada cum se parcurge
// programul cu un exemplu concret.

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
	int cursor, amount, op, n, dim, len, vecOperanzi[10];
	scanf("%u", &inst); // ex: 1149763584
	n = (inst>>(29))+1; // ex: 010


	// se introduce in vectorul de operatii bitii de dupa n
	for (int i = 1; i <= n; i++) {
		op = (inst >> (29 - i*2)) & 0b11;
		vecOperatii[i-1] = op;
	}

	// aflam dimensiunea:

	dim = ((inst >> (29 - (n * 2) - 4)) & 0b1111) + 1; // ex: 2

	// len este numarul de valori care vor trebui citite de la tastatura

	len = (int)(ceil((double)(((n+1)*dim))/16)); //ex: 1 (65280)

	// amount - in cati operanzi va fi impartit shortul
	
	amount = 16 / dim; // ex: 8

	cursor = 0;
	for (int i = 0; i < len; i++) {
		scanf("%hu", &nre); // ex 65280
		for (int j = amount-1; j >= 0 && cursor < n + 1; j--) {
			vecOperanzi[cursor] =  (int)((nre >> dim*j) & mask(dim));
			cursor++;
		}
	}

	// loop-ul face operatii in dependenta de codul op-ului (00,01,10,11)
	for (int i = 0; i < n; i++) {
		if (vecOperatii[i] == 0) {
			vecOperanzi[i+1] += vecOperanzi[i];
		} else if (vecOperatii[i] == 1) {
			vecOperanzi[i+1] = vecOperanzi[i] - vecOperanzi[i+1];
		} else if (vecOperatii[i] == 2) {
			vecOperanzi[i+1] *= vecOperanzi[i];
		} else if (vecOperatii[i] == 3) {
			vecOperanzi[i+1] = (vecOperanzi[i] / vecOperanzi[i+1]);
		}
	}
	printf("%d\n", vecOperanzi[n]);
	return 0;
}