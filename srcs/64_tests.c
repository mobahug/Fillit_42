#include <stdio.h>
#include <stdint.h>

int main()
{
	uint64_t test;
	uint64_t flag;
	int i;

	test = 1;
	test <<= 63;
	flag = 1;
	i = 0;
	flag <<= 63;
	while (i < 64)
	{
		if (flag & test)
			printf("1 ");
		else 
			printf("0 ");
		if (i % 16 == 15)
			printf("\n");
		flag >>= 1;
		i++;
	}
	printf("\n");


	return (0);
}
//9223372036854775808