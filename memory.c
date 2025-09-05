#include "cube.h"

void	generate_map(data *d)
{
	int	i;
	int	j;
	int	k;
	const unsigned int	seed = (unsigned int)time(NULL);

	i = -1;
	srand(seed);
	while (++i < d->D)
	{
		j = -1;
		while (++j < d->H)
		{
			k = -1;
			while (++k < d->W)
			{
				if(rand() % 10 == 0)
					d->map[i][j][k] = 'o';
				else
					d->map[i][j][k] = '.';
			}
		}
	}
}

int	allocate_data(data *d)
{
	int	i;
	int	j;

	d->sizeofside = (int ***)malloc(sizeof(int **) * d->D);
	d->map = (char ***)malloc(sizeof(char **) * d->D);
	if (!d->sizeofside || !d->map)
		return (0);
	i = -1;
	while (++i < d->D)
	{
		d->sizeofside[i] = (int **)malloc(sizeof(int *) * d->H);
		d->map[i] = (char **)malloc(sizeof(char *) * d->H);
		if (!d->sizeofside[i] || !d->map[i])
			return (0);
		j = -1;
		while (++j < d->H)
		{
			d->sizeofside[i][j] = ft_int_calloc(d->W);
			d->map[i][j] = ft_char_calloc(d->W, '\0');
		}
	}
	return (1);
}

void	free_data(data *d)
{
	int	i;
	int	j;

	i = -1;
	while (++i < d->D)
	{
		j = -1;
		while (++j < d->H)
		{
			free(d->sizeofside[i][j]);
			free(d->map[i][j]);
		}
		free(d->sizeofside[i]);
		free(d->map[i]);
	}
	free(d->sizeofside);
	free(d->map);
}
