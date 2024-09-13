#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>

#define typename(x) _Generic((x), int: "int", float: "float", default: "other")
#define print_any(X) _Generic((X), int: print_int, char *: print_pchar, char: print_char, float: print_float)(X)

int print_int(int i) { return printf("%d", i); }

int print_float(float f) { return printf("%f", f); }

int print_pchar(char *c) { return printf("%s", c); }

int print_char(char c) { return printf("%c", c); }

int main(void) {

	int a;


	for ( a = 1; a != 13 + (1); a = a + ( 1 )) {
	
	if (!a == 7) {
		print_any(a);
		printf("\n");
	}

	}

	a = 0;

	do {
		a = a + 1;

	if (!a == 6 && a != 8) {
		print_any(a);
	printf("\n");
	}

	} while (a < 14);

	a = 0;

	while (a < 12) {
		print_any(a);
	a = a + 1;
	}

	printf("\n");

}
