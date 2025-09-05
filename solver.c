#include "cube.h"

int	solve_sizeofside(data d, vec3 *crnt)
{
	int	side;//size of cube's side
	int	i;//number of intdex
	int	j;
	int	k;

	side = 0;
	while (side <= (ft_min(d.D - crnt->z, ft_min(d.H - crnt->y, d.W - crnt->x))))//most shotest axis in the 3axis
	{
		i = 0;
		while (i < side)
		{
			j = 0;
			while (j < side)
			{
				k  = 0;
				while (k < side)
				{
					if (d.map[crnt->z + i][crnt->y + j][crnt->x + k] == 'o')
						return (side - 1);//辺長 －１
					++k;
				}
				++j;
			}
			++i;
		}
		++side;
	}
	return (side - 1);
}

void	sides_data(data *d, vec3 *crnt)
{
	crnt->z = 0;
	while (crnt->z < d->D)
	{
		crnt->y = 0;
		while (crnt->y < d->H)
		{
			crnt->x = 0;
			while (crnt->x < d->W)
			{
				d->sizeofside[crnt->z][crnt->y][crnt->x] = solve_sizeofside(*d, crnt);
				++crnt->x;
			}
			++crnt->y;
		}
		++crnt->z;
	}
}

//一番大きい値を探す。d.sizeofsideの中から
void	solve_max(max *m, data d)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (++i < d.D)
	{
		j = -1;
		while (++j < d.H)
		{
			k = -1;
			while (++k < d.W)
			{
				if (m->side < d.sizeofside[i][j][k])
				{
					m->side = d.sizeofside[i][j][k];
					m->index.z = i;
					m->index.y = j;
					m->index.x = k;
				}
			}
		}
	}
}

void	write_cb(data *d)
{
	max m;
	int	i;
	int	j;
	int	k;

	m.index.z = 0;
	m.index.y = 0;
	m.index.x = 0;
	m.side = 0;
	solve_max(&m, *d);
	i = -1;
	while (++i < m.side)
	{
		j = -1;
		while (++j < m.side)
		{
			k = -1;
			while (++k < m.side)
				d->map[m.index.z + i][m.index.y + j][m.index.x + k] = 'x';
		}
	}
}
