/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 06:49:17 by namohamm          #+#    #+#             */
/*   Updated: 2022/05/04 14:20:24 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init(char *str, t_fdf **data)
{
	ft_get_height(str, data);
	ft_get_width(str, data);
	ft_read_file(str, data);
	ft_read_col(str, data);
	(*data)->w_w = 1500;
	(*data)->w_h = 900;
	(*data)->shift_x = 10;
	(*data)->shift_y = 10;
	(*data)->my_z = 3;
	(*data)->alpha = -45;
	(*data)->theta = 0;
	(*data)->gamma = -45;
	(*data)->col1 = 0;
	(*data)->col2 = 3;
	(*data)->count = 0;
	if ((*data)->width > 100)
		(*data)->zoom += 2;
	else
		(*data)->zoom = 25;
}
