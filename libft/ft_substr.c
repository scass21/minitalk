/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scass <scass@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 12:13:08 by scass             #+#    #+#             */
/*   Updated: 2021/04/09 07:06:57 by scass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, int start, size_t len)
{
	char	*dest;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	dest = malloc(sizeof(char) * (len + 1));
	if (dest)
	{
		if (start >= ft_strlen(s))
			dest[0] = '\0';
		else
		{
			while (len)
			{
				dest[i++] = s[start++];
				len--;
			}
			dest[i] = '\0';
		}
	}
	return (dest);
}
