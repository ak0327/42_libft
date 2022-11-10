/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takira <takira@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:37:26 by takira            #+#    #+#             */
/*   Updated: 2022/10/17 10:37:27 by takira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	chr;
	size_t	i;

	chr = (char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == chr)
			return ((char *) &s[i]);
		i++;
	}
	if (chr == '\0')
		return ((char *) &s[i]);
	return (NULL);
}
