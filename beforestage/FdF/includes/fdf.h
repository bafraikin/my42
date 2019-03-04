

#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>


typedef struct s_mlx
{
	void *ptr;
	void *win;
	int height;
	int width;
} t_mlx;

typedef struct s_img
{
	int size;
	void *ptr;
	char *data;
	int bbp;
	int size_line;
	int endian;
} t_img;

typedef struct s_pars
{
	short **map;
	short **tmp;
	int size_l;
	int nb_l;

} t_pars;


t_pars *ft_parse_map(int fd);
