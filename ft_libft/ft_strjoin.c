/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:56:59 by evocatur          #+#    #+#             */
/*   Updated: 2023/01/20 13:56:59 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*finalstring(char const *s1, char const *s2, char *newstr)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		if (s1[i] != '\0')
			newstr[j] = s1[i];
		j++;
		i++;
	}
	i = 0;
	while (s2[i])
	{
		if (s2[i] != '\0')
			newstr[j] = s2[i];
		i++;
		j++;
	}
	newstr[j++] = '\0';
	return (newstr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;

	if (s2 == NULL || s1 == NULL)
		return (NULL);
	if (ft_strlen(s1) >= 0 && ft_strlen(s1) >= 0)
	{
		newstr = (char *)malloc
			(ft_strlen(s1) + ft_strlen(s2) + 1 * sizeof(char));
		if (!newstr)
			return (NULL);
		return (finalstring(s1, s2, newstr));
	}
	return (NULL);
}
