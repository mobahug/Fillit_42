#include <stdio.h>
#include <stdint.h>
#include "fillit_bw.h"


uint64_t encode(char input[16])
{
	uint64_t tetri = 0;
	
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
void print_real_tet(uint64_t tetri)
{
	int i;
	int size;
	//uint64_t flag = 2147483648
	uint64_t flag = 1;

	flag <<= 63;
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
		flag >>= 1;
		i++;
	}
}

void print_map(uint16_t map[16])
{
	int i = 0;
	int j = 0;
	uint16_t flag = 32768;

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
		flag = 32768;
		printf("\n");
		i++;
	}
}

/*
void put_tetri(uint64_t *tetri, uint16_t *map)
{
	uint16_t test = 61440;
	*map |= test;
}
*/
int main()
{
	
	char input[16] = {'.','#','.','.', '#','#','#','.', '.','.','.','.', '.','.','.','.'};
	char input2[16] = {'#','#','.','.', '.','#','.','.', '.','#','.','.', '.','.','.','.'};
	uint16_t map[16];
	uint64_t tetri = encode(input);
	uint64_t tetri2 = encode(input2);
	ft_bzero(map, sizeof(uint16_t) * 16);
	//print_real_tet(tetri);
	print_tetri(tetri);
	printf("\n");
	print_tetri(tetri2);
	printf("\n");
	//uint16_t test = 61440;
	//*(map) |= test;
	//tetri <<= 13;
	*(uint64_t *)(map) ^= (tetri2 << 14);
	//*(uint64_t *)(map) ^= (tetri << 13);

	printf("1 means overlap, 0 mean free\n");
	if ((*(uint64_t *)(map)) & ((tetri << 12)))
		printf("1\n");
	else
	{
		printf("0\n");
		*(uint64_t *)(map) ^= (tetri << 12);
	}

	//*(map + 1) = test;
	//printf("\n");
	//printf("\n");
	print_map(map);
	//printf("\n");
	
	//print_real_tet(tetri);
	//print_tetri(tetri);
	

	//tetri <<= 45;
	//print_tetri(tetri);
	//printf("\n");
	//printf("\n");
	
	return (0);
}

/*
	uint16_t i = 1;
	while (i < 17)
	{
		map[i - 1] = i;
		i++;
	}
	i = 0;
	while (i < 15)
		printf("%d ", map[i++]);
	printf("\n");
	printf("\n");
	*/