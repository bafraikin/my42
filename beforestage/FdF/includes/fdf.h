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
