/* dec2bin.c
 * Info: http://web.math.princeton.edu/math_alive/1/Lab1/Conversion.html
 * 		 https://www.cs.cornell.edu/~tomf/notes/cps104/twoscomp.html
 * Created: Nov, 2017
 * Author: Viktor Stoev
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "csamples.h"

#define ZERO 	'0'
#define ONE		'1'

#define MAXLEN sizeof(char) * 8

char bin_num[MAXLEN];

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

char *print_dec2bin(char n)
{
	int p;
	char flag = 0;
	unsigned char q;
	char *cptr = bin_num;

	p = MAXLEN - 1;

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

	return bin_num;
}
