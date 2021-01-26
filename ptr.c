#include <stdio.h>

int main() {
	int p[10] = {0};

	for (int i = 0; i < sizeof(p) / sizeof(p[0]); ++i) {
		p[i] = i;
	}

	for (int i = 0; i < sizeof(p) / sizeof(p[0]); ++i) {
		printf("%d ", p[i]);
	}

	printf("\n");

	return 0;
}
