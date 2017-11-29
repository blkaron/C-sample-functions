#include <stdio.h>
#include "csamples.h"

int main(){

	/*Test print_dec2bin */
	char n = -128;

	for(; n <= 127; n++)
		{
			printf("The number %d in binary:%s\n", n, print_dec2bin(n));
			if(n == 127)
				break;
		}
	/*End of Test print_dec2bin */
	return 0;
}
