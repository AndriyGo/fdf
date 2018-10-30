#include "fdf.h"

void	die(char *message)
{
	printf("%s\n", message);
	exit(0);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	t_fdf	*fdf;

	if (argc > 2)
		die("usage: \t./fdf [no args] to read from stdin\n\t\t\
			./fdf filename (1 file max");
	if (argc == 1)
		fd = 0;
	else if ((fd = open(argv[0])) == -1)
		die("Cannot read input file");
	init_fdf(&fdf);
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strlen(line) == 0)
		{
			free(line);
			break ;
		}
		add_line(fdf, line);
		free(line);
	}
	map_to_array(fdf);
	redraw(fdf);
	while(1);
	return (0);
}