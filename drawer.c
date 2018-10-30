#include "fdf.h"

int		*xyz_to_xyc(t_fdf *fdf, int x, int y, int z)
{
	int	*ret;

	ret = ft_memalloc_die(3 * sizeof(int));
	ret[0] = (int)((double)x * fdf->scale);
	ret[1] = (int)((double)y * fdf->scale);
	ret[2] = (int)((double)z * fdf->scale);
	return (ret);
}

void	clear(t_fdf *fdf)
{

}

void	add_point_to_image(t_fdf *fdf, int x, int y, int color)
{

}

void	draw_points_between(t_fdf *fdf, int *p1, int *p2)
{
	int		**points;
	int		**tmp;
	int		**tmp2;
	int		x;
	int		len;

	printf("HELLO\n");
	points = points_between(p1[0], p1[1], p2[0], p2[1]);
	printf("HELLO2\n");
	tmp = points;
	len = sizeof(points[0]) / (2 * sizeof(points[0][0]));
	printf("Len %d\n", len);
	x = 0;
	while (*points)
	{
		add_point_to_image(fdf, (*points)[0], (*points)[1], p1[2] + x * (p2[2] \
			- p1[2]) / len);
		tmp2 = points;
		free(*points);
		points = ++tmp2;
	}
	free(tmp);
}

void	redraw(t_fdf *fdf)
{
	int	x;
	int	y;
	int	*p1;
	int	*p2;

	clear(fdf);
	y = 0;
	while (y < fdf->h)
	{
		x = 0;
		while (x < fdf->w)
		{
			p1 = xyz_to_xyc(fdf, x, y, fdf->map[y][x]);
			if (x < fdf->w - 1)
			{
				p2 = xyz_to_xyc(fdf, x + 1, y, fdf->map[y][x + 1]);
				draw_points_between(fdf, p1 , p2);
				free(p2);
			}
			if (y < fdf->h - 1)
			{
				p2 = xyz_to_xyc(fdf, x, y + 1, fdf->map[y + 1][x]);
				draw_points_between(fdf, p1 , p2);
				free(p2);
			}
			free(p1);
			x++;
		}
		y++;
	}
}