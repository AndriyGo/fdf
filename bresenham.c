#include "fdf.h"

int		**draw_line_r(int x0, int y0, int x1, int y1)
{
	int		deltax;
	int		error;
	int		deltaerr;
	int		**ret;
	int		i;

	deltax = abs(x1 - x0);
	printf("YO %d\n", deltax + 2);
	ret = ft_memalloc_die((deltax + 2) * sizeof(int*));
	deltaerr = abs(y1 - y0);
	error = 0;
	i = 0;
	while (x0 <= x1)
	{
		ret[i] = ft_memalloc_die(2 * sizeof(int));
		ret[i][0] = x0;
		ret[i++][1] = y0;
		error = error + deltaerr;
		if (2 * error >= deltax)
		{
			y0 = (y1 < y0) ? (y0 - 1) : (y0 + 1);
			error = error - deltax;
		}
		x0++;
	}
	return (ret);
}

int		**draw_line_l(int x0, int y0, int x1, int y1)
{
	int		deltax;
	int		error;
	int		deltaerr;
	int		**ret;
	int		i;

	deltax = abs(x1 - x0);
	ret = ft_memalloc_die((deltax + 2) * sizeof(int*));
	printf("%d\n", deltax + 1);
	deltaerr = abs(y1 - y0);
	error = 0;
	i = 0;
	while (x0 >= x1)
	{
		ret[i] = ft_memalloc_die(2 * sizeof(int));
		ret[i][0] = x0;
		ret[i++][1] = y0;
		error = error + deltaerr;
		if (2 * error >= deltax)
		{
			y0 = (y1 < y0) ? (y0 - 1) : (y0 + 1);
			error = error - deltax;
		}
		x0--;
	}
	return (ret);
}

int		**draw_line_t(int x0, int y0, int x1, int y1)
{
	int		deltax;
	int		error;
	int		deltaerr;
	int		**ret;
	int		i;

	deltax = abs(y1 - y0);
	ret = ft_memalloc_die((deltax + 2) * sizeof(int*));
	deltaerr = abs(x1 - x0);
	error = 0;
	i = 0;
	while (y0 <= y1)
	{
		ret[i] = ft_memalloc_die(2 * sizeof(int));
		ret[i][0] = x0;
		ret[i++][1] = y0;
		error = error + deltaerr;
		if (2 * error >= deltax)
		{
			x0 = (x1 < x0) ? (x0 - 1) : (x0 + 1);
			error = error - deltax;
		}
		y0++;
	}
	return (ret);
}

int		**draw_line_b(int x0, int y0, int x1, int y1)
{
	int		deltax;
	int		error;
	int		deltaerr;
	int		**ret;
	int		i;

	deltax = abs(y1 - y0);
	ret = ft_memalloc_die((deltax + 2) * sizeof(int*));
	deltaerr = abs(x1 - x0);
	error = 0;
	i = 0;
	while (y0 >= y1)
	{
		ret[i] = ft_memalloc_die(2 * sizeof(int));
		ret[i][0] = x0;
		ret[i++][1] = y0;
		error = error + deltaerr;
		if (2 * error >= deltax)
		{
			x0 = (x1 < x0) ? (x0 - 1) : (x0 + 1);
			error = error - deltax;
		}
		y0--;
	}
	return (ret);
}

int		**points_between(int x0, int y0, int x1, int y1)
{
	int		**points;
	int		l;
	int		dx;
	int		dy;

	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	if ((dx >= dy) && (x1 > x0))
		points = draw_line_r(x0, y0, x1, y1);
	else if (dx >= dy)
		points = draw_line_l(x0, y0, x1, y1);
	else if (y1 > y0)
		points = draw_line_t(x0, y0, x1, y1);
	else
		points = draw_line_b(x0, y0, x1, y1);
	return (points);
}
