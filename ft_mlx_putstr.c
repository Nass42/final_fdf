/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_putstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:13:43 by namohamm          #+#    #+#             */
/*   Updated: 2022/05/04 14:26:34 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_mlx_putstr(t_fdf **d)
{
	int	y;
	int	w;

	w = 0xffffff;
	y = 0 ;
	mlx_string_put((*d)->img->i_p, (*d)->w_p, 50, y += 20, w, "*******");
	mlx_string_put((*d)->img->i_p, (*d)->w_p, 50, y += 20, w, "*(FDF)*");
	mlx_string_put((*d)->img->i_p, (*d)->w_p, 50, y += 20, w, "*******");
	mlx_string_put((*d)->img->i_p, (*d)->w_p, 15, y += 70, w, "col   XY: C");
	mlx_string_put((*d)->img->i_p, (*d)->w_p, 15, y += 70, w, "col    Z: V");
	mlx_string_put((*d)->img->i_p, (*d)->w_p, 15, y += 50, w, "Zoom:     S/W");
	mlx_string_put((*d)->img->i_p, (*d)->w_p, 15, y += 30, w, "Move:   Arrow");
	mlx_string_put((*d)->img->i_p, (*d)->w_p, 15, y += 30, w, "Z u/d: - / +");
	mlx_string_put((*d)->img->i_p, (*d)->w_p, 15, y += 60, w, "Rotate:");
	mlx_string_put((*d)->img->i_p, (*d)->w_p, 57, y += 25, w, "X - Key I or K");
	mlx_string_put((*d)->img->i_p, (*d)->w_p, 57, y += 25, w, "Y - Key J or L");
	mlx_string_put((*d)->img->i_p, (*d)->w_p, 57, y += 25, w, "Z - Key U or O");
	mlx_string_put((*d)->img->i_p, (*d)->w_p, 15, y += 60, w, "Projection:");
	mlx_string_put((*d)->img->i_p, (*d)->w_p, 57, y += 25, w, "ISO      - P");
	mlx_string_put((*d)->img->i_p, (*d)->w_p, 57, y += 25, w, "PAR SIDE - B");
	mlx_string_put((*d)->img->i_p, (*d)->w_p, 57, y += 25, w, "PAR BOT  - N");
}
