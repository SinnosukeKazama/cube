#include "cube.h"

int main(int ac, char **av)
{
	vec3 crnt;
	data d;

	if (ac != 4)
	{
		ft_putstr("Error");
		return (0);
	}
	crnt.x = 0;
	crnt.y = 0;
	d.D = ft_atoi(av[1]);
	d.H = ft_atoi(av[2]);
	d.W = ft_atoi(av[3]);
	if (!allocate_data(&d))
		return (0);
	generate_map(&d);
	sides_data(&d, &crnt);
	write_cb(&d);
	out_data(d);
	free_data(&d);
	return(0);
}
