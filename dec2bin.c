/* dec2bin.c
 * Source: http://web.math.princeton.edu/math_alive/1/Lab1/Conversion.html
 * 		   https://www.cs.cornell.edu/~tomf/notes/cps104/twoscomp.html
 * Created: Nov, 2017
 * Author: Viktor Stoev
 */

#include <stdio.h>
#include <math.h>

#define ZERO 	'0'
#define ONE		'1'
#define MAXLEN  sizeof(char)

void print_dec2bin(char);

char bin_num[MAXLEN];

int main(){
	char n = 85;

	print_dec2bin(n);

	printf("The number %d in binary is: %s\n", n, bin_num);

	return 0;
}

/* Function: print_dec2bin:
 * ------------------------
 * Display the binary representation of a decimal number:
 * - using powers of two method for positive numbers
 * - using two's complement for negative numbers
 *
 * n: the decimal number
 *
 * returns: void
 *
 */

void print_dec2bin(char n)
{
	int p;
	char flag = 0;
	unsigned char q;
	char *cptr = bin_num;

	p = (sizeof(n) * 8) - 1;

	if(n < 0){
		n = -1*n;
		flag = 1;
	}

	// Handle the normal "positive" conversion
	while(p >= 0){
		if((q = pow(2, p--)) > n)
			flag ? (*cptr++ = ONE) : (*cptr++ = ZERO);
		else{
			flag ? (*cptr++ = ZERO) : (*cptr++ = ONE);
			n -= q;
		}
	}

	// Handle the negative numbers
	if(flag){
		while(cptr != bin_num && *--cptr == ONE)
			*cptr = ZERO;
		*cptr = ONE;
	}
}
