#include "cube.h"

void	out_sizeofside(data d)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (++i < d.D)
	{
		ft_putstr("z=");
		ft_putnum(i);
		ft_putchar('\n');
		j = -1;
		while (++j < d.H)
		{
			k = -1;
			while (++k < d.W)
				ft_putnum(d.sizeofside[i][j][k]);
			ft_putchar('\n');
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
		ft_putstr("z=");
		ft_putnum(i);
		ft_putchar('\n');
		j = -1;
		while (++j < d.H)
		{
			k = -1;
			while (++k < d.W)
				ft_putchar(d.map[i][j][k]);
			ft_putchar('\n');
		}
	}
}

void	out_data(data d)
{
	out_sizeofside(d);
	out_map(d);
}
