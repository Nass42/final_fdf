/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:02:53 by namohamm          #+#    #+#             */
/*   Updated: 2022/05/04 14:24:00 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int key, t_fdf **d)
{
	ft_keys(key, &(*d));
	mlx_destroy_image((*d)->m_p, (*d)->img->i_p);
	(*d)->img->i_p = mlx_new_image((*d)->m_p, (*d)->w_w, (*d)->w_h);
	(*d)->img->ad = mlx_get_data_addr((*d)->img->i_p,
			&((*d)->img->bpp), &((*d)->img->ll), &((*d)->img->endian));
	ft_draw(&(*d));
	mlx_put_image_to_window((*d)->m_p, (*d)->w_p,
		(*d)->img->i_p, 0, 0);
	ft_mlx_putstr(&(*d));
	return (0);
}

void	my_mlx_pixel_put(t_fdf **d, int x, int y, int color)
{
	char	*dst;

	if ((x >= 0 && y >= 0) && (x < (*d)->w_w && y < (*d)->w_h))
	{
		dst = (*d)->img->ad + (y * (*d)->img->ll + x * ((*d)->img->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

int	mouse_hook(int keycode, t_fdf **data)
{
	if (keycode)
	{
		exit(0);
		free(data);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_fdf	*d;

	if (ac == 2)
	{
		if (ft_error(av[1]))
		{
			d = (t_fdf *)malloc(sizeof(t_fdf));
			d->img = (t_i *)malloc(sizeof(t_i));
			ft_init(av[1], &d);
			d->m_p = mlx_init();
			d->w_p = mlx_new_window(d->m_p, 1500, 900, "FDF");
			d->img->i_p = mlx_new_image(d->m_p, d->w_w, d->w_h);
			d->img->ad = mlx_get_data_addr(d->img->i_p, &(d->img->bpp),
					&(d->img->ll), &(d->img->endian));
			ft_draw(&d);
			mlx_key_hook(d->w_p, deal_key, &d);
			mlx_hook(d->w_p, 17, 1L << 0, mouse_hook, &d);
			mlx_put_image_to_window(d->m_p, d->w_p, d->img->i_p, 0, 0);
			ft_mlx_putstr(&d);
			mlx_loop(d->m_p);
		}
	}
	ft_putstr("Usage: ./fdf MAP_FILE");
	return (0);
}
