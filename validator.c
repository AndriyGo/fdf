#include "fdf.h"

void	validate_number(char *line)
{
	int	c;

	if ((*line == '-') || (*line == '+'))
		line++;
	c = 0;
	while (*line && (*line != ' '))
	{
		if (!ft_isdigit(*(line++)))
			die("Error: map contains invalid numbers");
		c++;
	}
	if (c == 0)
		die("Error: map contains empty entries");
}

void	validate_line(t_fdf *fdf, char *line)
{
	int	s;

	s = 0;
	while (*line)
	{
		if (*line == ' ')
			s++;
		else
			validate_number(line);
		line++;
	}
	if ((fdf->w != -1) && (s != fdf->w - 1))
		die("Error: map has inconsistent width");
	else
		fdf->w = s + 1;
}