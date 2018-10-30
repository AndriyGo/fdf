#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include <stdlib.h>
# include <math.h>

typedef struct	s_fdf
{
	int			w;
	int			h;
	int			**map;
	double		scale;
	t_list		*map_line;
}				t_fdf;

void	die(char *message);
void	init_fdf(t_fdf **fdf);
void	add_line(t_fdf *fdf, char *line);
void	validate_line(t_fdf *fdf, char *line);
void	map_to_array(t_fdf *fdf);
void	*ft_memalloc_die(size_t size);
int		**points_between(int x0, int y0, int x1, int y1);
void	redraw(t_fdf *fdf);

#endif