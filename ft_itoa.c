/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takira <takira@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:41:38 by takira            #+#    #+#             */
/*   Updated: 2022/10/20 15:16:33 by takira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_num_digits(long long num)
{
	int	num_digits;

	num_digits = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num_digits += 1;
		num /= 10;
	}
	return (num_digits);
}

static void	set_params(int n, long long *num, size_t *len, size_t *sign_idx)
{
	*num = (long long)n;
	*len = 0;
	*sign_idx = 0;
	if (*num < 0)
	{
		*len += 1;
		*num *= (-1);
		*sign_idx = 1;
	}
	*len += get_num_digits(*num);
}

char	*ft_itoa(int n)
{
	long long	num;
	size_t		itoa_len;
	size_t		sign_idx;
	char		*ret;

	set_params(n, &num, &itoa_len, &sign_idx);
	ret = (char *)ft_calloc(sizeof(char), itoa_len + 1);
	if (ret == NULL)
		return (NULL);
	if (sign_idx == 1)
		ret[0] = '-';
	while (itoa_len > sign_idx)
	{
		ret[itoa_len - 1] = (char)(num % 10 + '0');
		num /= 10;
		itoa_len--;
	}
	return (ret);
}
