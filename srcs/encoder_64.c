#include <stdio.h>
#include <stdint.h>

int main()
{
	uint64_t tetri = 0;
	char input[16] = {'.','#','.','.', '#','#','#','.', '.','.','.','.', '.','.','.','.'};
	int i;
	int pow = 1;

	i = 0;
	while (i < 64)
	{
		if (input[63 - i] == '#')
			tetri += pow;
		pow *= 2;
		i++;
	}
	return (0);
}