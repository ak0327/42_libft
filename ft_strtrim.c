/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takira <takira@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:39:48 by takira            #+#    #+#             */
/*   Updated: 2022/11/12 10:09:59 by takira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_head_and_size(const char *s, const char *set, size_t *head)
{
	size_t	tail;

	*head = 0;
	while (s[*head] && ft_strchr(set, s[*head]) != NULL)
		*head += 1;
	tail = ft_strlen(s) - 1;
	while (tail > 0 && ft_strchr(set, s[tail]) != NULL)
		tail -= 1;
	if (*head <= tail)
		return (tail - *head + 1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	head_idx;
	size_t	size;
	char	*ret_str;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (*s1 == '\0')
		size = 0;
	else
		size = get_head_and_size(s1, set, &head_idx);
	ret_str = (char *)ft_calloc(sizeof(char), size + 1);
	if (ret_str == NULL)
		return (NULL);
	ft_memcpy(ret_str, &s1[head_idx], size);
	return (ret_str);
}
