/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takira <takira@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:31:53 by takira            #+#    #+#             */
/*   Updated: 2022/10/17 10:31:54 by takira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || \
	c == '\v' || c == '\f' || c == '\r');
}

static bool	is_under_long(long long before_10x_val, long long add_val, int sign)
{
	long long	ov_div;
	long long	ov_mod;

	ov_div = LONG_MAX / 10;
	ov_mod = LONG_MAX % 10;
	if (sign < 0)
		ov_mod++;
	if (before_10x_val > ov_div)
		return (false);
	if (before_10x_val == ov_div && add_val >= ov_mod)
		return (false);
	return (true);
}

int	ft_atoi(const char *str)
{
	long long	ret_num;
	int			sign;

	while (my_isspace(*str))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	ret_num = 0;
	while (ft_isdigit(*str))
	{
		if (is_under_long(ret_num, (*str - '0'), sign) == true)
			ret_num = ret_num * 10 + *str - '0';
		else if (sign > 0)
			return ((int)LONG_MAX);
		else
			return ((int)LONG_MIN);
		str++;
	}
	return ((int)(sign * ret_num));
}
