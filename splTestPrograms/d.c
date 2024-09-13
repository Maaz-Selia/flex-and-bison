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

	float r1, r2, r3;

	r1 = -2.4;
	r2 = -34.989;
	r3 = r1 * r2 / 7.4;
	print_any(r3);
	printf("\n");
	char str[254];
	printf("Please enter a value: ");
	scanf("%s", str);
	if(typename(r1) == "other")
		r1 = *str;
	else if(typename(r1) == "int")
		r1 = atoi(str);
	else if(typename(r1) == "float")
		r1 = atof(str);

	r3 = r1 + r3;
	print_any(r3);
	printf("\n");

}
