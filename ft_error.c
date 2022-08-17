/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:43:26 by namohamm          #+#    #+#             */
/*   Updated: 2022/05/04 14:40:08 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_error(char *str)
{
	int		fd;

	fd = open(str, O_RDONLY, 0);
	if (fd < 3)
	{
		ft_putstr(" ERROR: INVALIDE FILE OR PERMISSION DENIED ");
		return (0);
	}
	close(fd);
	return (1);
}
