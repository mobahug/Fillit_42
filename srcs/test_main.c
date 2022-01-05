#include <stdio.h>
#include <stdint.h>
#include "fillit_bw.h"

uint64_t encode()
{
	uint64_t tetri = 0;
	char input[16] = {'.','#','.','.', '#','#','#','.', '.','.','.','.', '.','.','.','.'};
	int i;
	int count;
	uint64_t pow = 1;

	i = 0;
	count = 0;
	
	while (i < 64)
	{
		
		if (i % 16 < 4)
		{
			if (input[count] == '#')
				tetri += pow;
			count++;
		}
		pow *= 2;
		i++;
	}
	return (tetri);
}

void print_tetri(uint64_t tetri)
{
	int i;
	int size;
	//uint64_t flag = 2147483648
	uint64_t flag = 1;

	size = 64;
	i = 0;
	while (i < size)
	{
		if (tetri & flag)
			printf("1 ");
		else
			printf("0 ");
		if (i % 16  == 15)
			printf("\n");
		flag <<= 1;
		i++;
	}
}

void print_map(uint16_t map[16])
{
	int i = 0;
	int j = 0;
	uint16_t flag = 0xFFFF;

	while (i < 16)
	{
		j = 0;
		while (j < 16)
		{
			if (map[i] & flag)
				printf("1 ");
			else
				printf("0 ");
			flag >>= 1;
			j++;
		}
		flag = 0xFFFF;
		printf("\n");
		i++;
	}
}

int main()
{
	uint64_t tetri = encode();
	uint16_t map[16];

	ft_bzero(map, 256);
	print_map(map);
	printf("\n");
	print_tetri(tetri);
	printf("\n");
	tetri <<= 45;
	print_tetri(tetri);
	printf("\n");
	printf("\n");



	return (0);
}
