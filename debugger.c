#include "fdf.h"

void	print_map_lines(t_fdf *fdf, t_list *list)
{
	int	x;

	printf("MAP %d by %d\n", fdf->h, fdf->w);
	while (list != NULL)
	{
		x = 0;
		while (x < fdf->w)
			printf("%d ", ((int*)(list->content))[x++]);
		printf("\n");
		list = list->next;
	}
}