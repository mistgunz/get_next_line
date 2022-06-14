/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnait-el <rnait-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 14:03:26 by rnait-el          #+#    #+#             */
/*   Updated: 2022/06/14 18:12:35 by rnait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

char	*ft_cat(char *dest, char *src, char *ptr, int len)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < len)
	{
		while (dest[j])
		{
			ptr[i] = dest[j];
			i++;
			j++;
		}
		j = 0;
		while (src[j])
		{
			ptr[i] = src[j];
			i++;
			j++;
		}
	}
	ptr[i] = '\0';
	return (ptr);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char **s1, char *s2)
{
	int		s2len;
	int		s1len;
	char	*ptr;

	s1len = 0;
	if (*s1 == NULL && s2 == NULL)
		return (NULL);
	if (!*s1)
		*s1 = ft_strdup("");
	s1len = ft_strlen(*s1);
	s2len = ft_strlen(s2);
	s1len += s2len;
	ptr = (char *)malloc(sizeof(char) * s1len + 1);
	if (!ptr)
		return (0);
	ptr = ft_cat(*s1, s2, ptr, s1len);
	free_pointers(s1, NULL);
	return (ptr);
}

int	check_newline(char *saved)
{
	int	i;

	i = 0;
	if (saved)
	{
		while (saved[i])
		{
			if (saved[i] == '\n')
				return (0);
			i++;
		}
	}
	return (1);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*dest;

	i = 0;
	len = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * len + 1);
	if (!dest)
		return (0);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
