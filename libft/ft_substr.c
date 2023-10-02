/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:02:44 by fracerba          #+#    #+#             */
/*   Updated: 2022/10/04 12:02:47 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	while (*(s + i) != '\0')
		i++;
	if (i <= start)
	{
		sub = malloc(1 * 1);
		*sub = '\0';
		return (sub);
	}
	sub = malloc((len + 1) * 1);
	if (!sub)
		return (0);
	i = 0;
	while (i < len && *(s + start + i) != '\0')
	{
		*(sub + i) = *(s + start + i);
		i++;
	}
	*(sub + i) = '\0';
	return (sub);
}
