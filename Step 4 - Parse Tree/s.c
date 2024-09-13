#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

#define typename(x) _Generic((x), int: "int", float: "float", default: "other")
#define print_any(X) _Generic((X), int: print_int, char *: print_pchar, char: print_char, float: print_float)(X)

int print_int(int i) { return printf("%d", i); }

int print_float(float f) { return printf("%f", f); }

int print_pchar(char *c) { return printf("%s", c); }

int print_char(char c) { return printf("%s", c); }

int main(void) {

	int integer, i;

	char *str;
	scanf("%s", str);
	if(typename(integer) == "other")
		integer = *str;
	else if(typename(integer) == "int")
		integer = atoi(str);
	else if(typename(integer) == "float")
		integer = atof(str);


	if (integer <= 5 || integer >= 12) {
		print_any(integer);
	}

	print_any((36-1));
	printf("\n");

	for ( integer = -1; integer < -5; integer = integer + -1) {
		print_any(integer);
		printf("\n");
	}

	i = -1;

	for ( integer = i * i * i; i < i * i * (i + i + i + i + i); i = i + i * i * i * i * i) {
		print_any(integer);
		printf("\n");
	}


}
