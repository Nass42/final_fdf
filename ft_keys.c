/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 06:59:34 by namohamm          #+#    #+#             */
/*   Updated: 2022/05/04 13:29:57 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_key_p(int key, t_fdf **d)
{
	if (key == 11)
	{
		(*d)->alpha = -90;
		(*d)->theta = 0;
		(*d)->gamma = 0;
	}
	if (key == 45)
	{
		(*d)->alpha = 0;
		(*d)->theta = 0;
		(*d)->gamma = 0;
	}
	if (key == 35)
	{
		(*d)->alpha = -35.264;
		(*d)->theta = 0;
		(*d)->gamma = -45;
	}
}

void	ft_key_z(int key, t_fdf **d)
{
	if (key == 1 && (*d)->width < 100)
		(*d)->zoom += 10;
	if (key == 24)
		(*d)->my_z += 1;
	if (key == 27)
		(*d)->my_z -= 1;
	if (key == 13 && (*d)->width > 100)
		(*d)->zoom += 1;
	if (key == 1 && (*d)->width > 100)
	{
		(*d)->zoom -= 1;
		if ((*d)->zoom < 1)
			(*d)->zoom = 1;
	}
	ft_key_p(key, d);
}

void	ft_keys_h(int key, t_fdf **data)
{
	if (key == 34)
		(*data)->alpha += 1;
	if (key == 40)
		(*data)->alpha -= 1;
	if (key == 37)
		(*data)->theta += 1;
	if (key == 38)
		(*data)->theta -= 1;
	if (key == 32)
		(*data)->gamma += 1;
	if (key == 31)
		(*data)->gamma -= 1;
	if (key == 8)
		(*data)->col1 += 1;
	if (key == 9)
		(*data)->col2 += 1;
}

void	ft_keys(int key, t_fdf **data)
{
	if (key == 126)
		(*data)->shift_y -= 10;
	if (key == 125)
		(*data)->shift_y += 10;
	if (key == 123)
		(*data)->shift_x -= 10;
	if (key == 124)
		(*data)->shift_x += 10;
	if (key == 13 && (*data)->width < 100)
	{
		(*data)->zoom -= 10;
		if ((*data)->zoom < 1)
			(*data)->zoom = 10;
	}
	ft_key_z(key, data);
	if (key == 53)
	{
		exit(0);
		free(data);
	}
	ft_keys_h(key, data);
}
