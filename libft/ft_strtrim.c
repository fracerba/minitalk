/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:01:41 by fracerba          #+#    #+#             */
/*   Updated: 2022/10/04 12:01:46 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	check_start(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		b;
	int		c;

	b = 1;
	c = 0;
	i = 0;
	while (*(s1 + i) != '\0' && b == 1)
	{
		b = 0;
		j = 0;
		while (*(set + j) != '\0')
		{
			if (*(s1 + i) == *(set + j))
			{
				b = 1;
				c++;
			}
			j++;
		}
		i++;
	}
	return (c);
}

static int	check_end(char const *s1, char const *set, int len)
{
	int		i;
	int		j;
	int		b;
	int		c;

	b = 1;
	c = 0;
	i = 1;
	while (len > i && b == 1)
	{
		b = 0;
		j = 0;
		while (*(set + j) != '\0')
		{
			if (*(s1 + len - i) == *(set + j))
			{
				b = 1;
				c++;
			}
			j++;
		}
		i++;
	}
	return (c);
}

char	*ft_setstr(char const *s1, char *trim, int k, int i)
{
	int		j;

	j = 0;
	while (j < i)
	{
		*(trim + j) = *(s1 + k + j);
		j++;
	}
	*(trim + j) = '\0';
	return (trim);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		k;
	char	*trim;

	if (!s1 || !set)
		return (0);
	i = 0;
	while (*(s1 + i) != '\0')
		i++;
	k = check_start(s1, set) + check_end(s1, set, i);
	if (k > i)
		k = i;
	trim = malloc((i - k + 1) * 1);
	if (!trim)
		return (0);
	i = i - k;
	k = check_start(s1, set);
	trim = ft_setstr(s1, trim, k, i);
	return (trim);
}
