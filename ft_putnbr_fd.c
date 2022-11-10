/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takira <takira@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:36:57 by takira            #+#    #+#             */
/*   Updated: 2022/10/17 10:36:58 by takira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	get_pow(long long num)
{
	long long	pow;

	if (num == 0)
		return (1);
	pow = 1;
	while (num / pow > 0)
		pow *= 10;
	return (pow / 10);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	num;
	long long	pow;

	num = (long long)n;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num *= (-1);
	}
	pow = get_pow(num);
	while (pow > 0)
	{
		ft_putchar_fd((char)(num / pow + '0'), fd);
		num %= pow;
		pow /= 10;
	}
}
