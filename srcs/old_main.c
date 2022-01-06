#include "fillit_bw.h"
#include <stdio.h>

void	free_list(t_tetri *head)
{
	t_tetri	*cur;
	t_tetri	*next;

	cur = head;
	while (cur)
	{
		next = cur->next;
		free (cur);
		cur = next;
	}
}

int	main(int ac, char **av)
{
	t_queue	queue;
	int		count;
	int		fd;

	

	if (ac != 2)
	{
		ft_putstr("usage: fillit input_file.fillit\n");
		return (0);
	}
	queue.head = NULL;
	queue.tail = NULL;
	count = 0;
	fd = open(av[1], O_RDONLY);
	queue.head = readin(&queue, &count, fd);
	if (!queue.head)
	{
		ft_putstr("error\n");
		return (0);
	}
	//solve(count, queue.head);

	t_tetri *temp = queue.head;
	while (temp)
	{
		printf("count\t%d\n", temp->count);
		printf("left\t%d\n", temp->left);
		printf("right\t%d\n", temp->right);
		printf("stop\t%d\n",  temp->stop);
		printf("\n");
		temp = temp->next;
	}
	free_list(queue.head);
	return (0);
}