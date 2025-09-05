#include "cube.h"

void	out_sizeofside(data d)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (++i < d.D)
	{
		printf("z=%d\n", i);
		j = -1;
		while (++j < d.H)
		{
			k = -1;
			while (++k < d.W)
				printf("%d,", d.sizeofside[i][j][k]);
			printf("\n");
		}
	}
}

void	out_map(data d)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (++i < d.D)
	{
		printf("z=%d\n",i);
		j = -1;
		while (++j < d.H)
		{
			k = -1;
			while (++k < d.W)
				printf("%c ", d.map[i][j][k]);
			printf("\n");
		}
	}
}

void	out_data(data d)
{
	out_sizeofside(d);
	out_map(d);
}
