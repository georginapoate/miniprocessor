#include <stdio.h>

int main() {
	unsigned int inst;
	int op;

	// se citeste instructiunea din terminal:
	scanf("%u", &inst);

	// obtinem primii 3 biti cei mai semnificativi
	// shiftand spre dreapta 29 de biti
	int n = (inst>>(29))+1;
	printf ("%d ", n);

	for (int i = 1; i <= n; i++) {
		op = (inst >> (29 - i*2)) & 0b11;
		if (op == 0) printf("+ ");
		else if (op == 1) printf("- ");
		else if (op == 2) printf("* ");
		else if (op == 3) printf("/ ");
	}
	int dim = ((inst >> (29 - (n * 2) - 4)) & 0b1111) + 1;
	printf("%d\n", dim);

	return 0;
}