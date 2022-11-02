/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:32:16 by aderouba          #+#    #+#             */
/*   Updated: 2022/09/30 11:46:13 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recursive_print(int n, int fd)
{
	int	tmp;

	tmp = n % 10;
	if (n >= 10)
	{
		n -= tmp;
		n /= 10;
		recursive_print(n, fd);
	}
	ft_putchar_fd(tmp + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		ft_putchar_fd('-', fd);
	}
	recursive_print(n, fd);
}
