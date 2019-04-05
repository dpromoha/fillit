#include "fillit.h"

int		need_elem(char **block)
{
	t_struct	a;

	a.i = 0;
	init_t_struct(&a);
	while (block[a.i])
	{
		a.j = 0;
		while (HASH(block[a.i][a.j]) || DOTS(block[a.i][a.j]))
			a.j++;
		ERROR_CHECK(a.j != 4);
		a.i++;
	}
	return (touch_elem(block));
}

int		touch_elem(char **tetrx)
{
	t_struct	a;
	int 		touch;

	touch = 0;
	init_t_struct(&a);
	a.i = 0;
	while (tetrx[a.i] && MAX_SIZE(a.i))
	{
		a.j = 0;
		while (tetrx[a.i][a.j] && MAX_SIZE(a.j))
		{
			if (HASH(tetrx[a.i][a.j]))
			{
				ERROR_CHECK((touch = touch + (rows(tetrx, a.i, a.j) +
					columns(tetrx, a.i, a.j))) <= 0);
			}
			a.j++;
		}
		a.i++;
	}
	ERROR_CHECK(touch < 6);
	return (1);
}

int		count_symb(char **tetrx)
{
	t_struct	a;

	a.i = 0;
	a.diez = 0;
	a.dot = 0;
	init_t_struct(&a);
	while (tetrx[a.i])
    {
		a.j = 0;
		while (tetrx[a.i][a.j])
		{
			if HASH(tetrx[a.i][a.j])
				a.diez++;
			else if DOTS(tetrx[a.i][a.j])
				a.dot++;
			else
			    return (-1);
			a.j++;
		}
		a.i++;
	}
	if (a.diez == 4 || a.dot == 12)
		return (touch_elem(tetrx));
	else
		return (-1);
}

int     columns(char **tetrx, int i, int j)
{
    int count;

    count = 0;
    if (MAX_SIZE(i + 1) && HASH(tetrx[i + 1][j]))
        count++;
    if (i - 1 >= 0 && HASH(tetrx[i - 1][j]))
        count++;
    return (count);
}

int     rows(char **tetrx, int i, int j)
{
    int count;

    count = 0;
    if (MAX_SIZE(j + 1) && HASH(tetrx[i][j + 1]))
        count++;
    if (j - 1 >= 0 && HASH(tetrx[i][j - 1]))
        count++;
    return (count);
}