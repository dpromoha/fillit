#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "../libft/libft.h"

# define ERROR_CHECK(a) if (a) return (-1)
# define NULL_CHECK(a) (a = NULL)
# define L_FEED(a) (a == '\n')
# define MAX_SIZE(a) (a < 4)
# define DOTS(a) (a == '.')
# define HASH(a) (a == '#')
# define MIN(a) (a == -1)
# define M_1(a) (a = -1)

typedef struct	s_ttr
{
	char	**model;
	char	mark;
	int		i;
	int		j;
}				t_ttr;

typedef struct		s_struct
{
    int             i;
    int             j;
	int             diez;
	int             dot;
}					t_struct;

void			init_t_struct(t_struct *a);
void			put_error(void);
char			**dots(char **new_tetrx, int i, int j, int size);
int     		count_symb(char **tetrx);
int				need_elem(char **block);
int				touch_elem(char **tetrx);
void			put_usage(void);
int				validation(char **tetrx);
void			print_tetrx(char **tetrx);
int				columns(char **tetrx, int i, int j);
int				rows(char **tetrx, int i, int j);
void			free_tetri(t_ttr **);
char			**diez_cut_tetrx(char **tetrx, char **new_tetrx, int count);
char			**new_block(char **tetrx, int size);
int    			count_where_to_set(int size, int count);
int				setting_tetrx(char **tetrx, t_ttr *tetrimino, int i, int j);
void			free_tetr_arr(char **tetrx);
int				read_file(char *input, int fd);
char			**mem_for_new_array(char **new_tetrx, int size);
int				valid_final_tetrx(int i, int j, char **tetrx, t_ttr *tetrimino);
int				set_tetrx(char **tetrx, t_ttr *tetrimino, int i, int j);
int				length_columns(char **tetrx, int i);
char    		**try_to_set(t_ttr *, int size);
int				length_rows(char **tetrx, int i);
char			**help_mem(char **tetrx, char **new_tetrx);
void			put_dots_on_need_place(t_ttr *tetrimino, char **tetrx, int i, int j);
void			try_to_set_valid(t_ttr *, char *filename, int fd);
int				cross_tetrx(char **tetrx, t_ttr *tetrimino);
char			**set_tetriminos(t_ttr *, int tetri_size);
int				fillit(char **tetrx, t_ttr *);

#endif
