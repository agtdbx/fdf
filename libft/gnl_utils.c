/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:46:15 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/02 16:46:36 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_buffer(char **buffer, int end_file)
{
	int	len;

	len = ft_strlen(*buffer);
	if (end_file == 1 && len == 0)
	{
		free(*buffer);
		*buffer = NULL;
	}
}

int	get_end_line(char *buffer)
{
	int	i;

	if (buffer == NULL)
		return (-2);
	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
