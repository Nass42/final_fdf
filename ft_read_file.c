/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:41:49 by namohamm          #+#    #+#             */
/*   Updated: 2022/05/03 18:49:46 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_get_height(char *str, t_fdf **data)
{
	int		fd;
	int		height;
	char	*tmp;

	height = 0;
	fd = open(str, O_RDONLY, 0);
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		height++;
		free(tmp);
	}
	(*data)->height = height;
}

void	ft_get_width(char *str, t_fdf **data)
{
	int		fd;
	char	*tmp;

	fd = open(str, O_RDONLY, 0);
	tmp = get_next_line(fd);
	(*data)->width = ft_words(tmp, ' ');
	while (1)
	{
		tmp = get_next_line(fd);
		free(tmp);
		if (!tmp)
			break ;
	}
	close(fd);
}

int	*fill_matrix(char *line)
{
	char	**str;
	int		*z_line;
	int		i;
	int		len;

	i = 0;
	len = ft_words(line, ' ');
	z_line = (int *)malloc(sizeof(int) * (len + 1));
	if (!z_line)
		return (NULL);
	str = ft_split(line, ' ');
	while (str[i])
	{
		z_line[i] = ft_atoi(str[i]);
		free(str[i]);
		i++;
	}
	free(str);
	return (z_line);
}

void	ft_read_file(char *file, t_fdf **data)
{
	int		fd;
	int		i;
	char	*tmp;

	i = 0;
	(*data)->z_matrix = (int **)malloc(sizeof(int *) * ((*data)->height + 1));
	if (!(*data)->z_matrix)
		return ;
	fd = open(file, O_RDONLY, 0);
	while (i < (*data)->height)
	{
		tmp = get_next_line(fd);
		(*data)->z_matrix[i] = fill_matrix(tmp);
		free(tmp);
		i++;
	}
	close(fd);
	fd = open(file, O_RDONLY, 0);
	close(fd);
}
