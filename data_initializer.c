#include "fdf.h"

void	*ft_memalloc_die(size_t size)
{
	void	*ret;

	if ((ret = ft_memalloc(size)) == NULL)
		die("Error: out of memory");
	return (ret);
}

void	init_fdf(t_fdf **fdf)
{
	if ((*fdf = ft_memalloc(sizeof(t_fdf))) == NULL)
		die("Error: Out of memory");
	(*fdf)->map = NULL;
	(*fdf)->h = 0;
	(*fdf)->w = -1;
	(*fdf)->scale = 1.0;
	(*fdf)->map_line = NULL;
}

void	add_line(t_fdf *fdf, char *line)
{
	t_list	*list;
	int		i;

	validate_line(fdf, line);
	if ((list = ft_lstnew(NULL, (fdf->w * sizeof(int)))) == NULL)
		die("Error: Out of memory");
	if ((list->content = ft_memalloc(fdf->w * sizeof(int))) == NULL)
		die("Error: Out of memory");
	i = 0;
	while (*line)
	{
		(((int*)(list->content))[i++]) = ft_atoi(line++);
		while (*line && ft_isdigit(*line))
			line++;
		line++;
	}
	if (fdf->map_line == NULL)
		fdf->map_line = list;
	else
		ft_lstappend(fdf->map_line, list);
	fdf->h = fdf->h + 1;
}

void	map_to_array(t_fdf *fdf)
{
	int		y;
	int		x;
	t_list	*tmp;

	if (fdf->w == -1)
		die("Error: empty map");
	if ((fdf->map = ft_memalloc(fdf->h * sizeof(int*))) == NULL)
		die("Error: Out of memory");
	y = 0;
	while (y < fdf->h)
	{
		if ((fdf->map[y] = ft_memalloc(fdf->w * sizeof(int))) == NULL)
			die("Error: Out of memory");
		x = 0;
		while (x < fdf->w)
		{
			fdf->map[y][x] = ((int*)(fdf->map_line->content))[x];
			x++;
		}
		tmp = fdf->map_line->next;
		free(fdf->map_line->content);
		free(fdf->map_line);
		fdf->map_line = tmp;
		y++;
	}
}