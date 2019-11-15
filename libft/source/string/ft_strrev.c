/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 20:40:56 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/12 12:53:27 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char				*ft_strrev(char *s)
{
	char		*str;
	size_t		i;
	size_t		len;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * len--);
	while (s)
	{
		str[i] = s[len];
		i++;
		len--;
	}
	str[i] = '\0';
	return (str);
}
