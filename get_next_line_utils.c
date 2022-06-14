/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnait-el <rnait-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 14:03:26 by rnait-el          #+#    #+#             */
/*   Updated: 2022/06/14 22:23:36 by rnait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

char	*ft_cat(char *s1, char *s2, char *ptr, int len)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < len)
	{
		while (s1[j])
		{
			ptr[i] = s1[j];
			i++;
			j++;
		}
		j = 0;
		while (s2[j])
		{
			ptr[i] = s2[j];
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

void	free_pointers(char **ptr1, char **ptr2)
{
	if (ptr1 && *ptr1)
	{
		free(*ptr1);
		*ptr1 = NULL;
	}
	if (ptr2 && *ptr2)
	{
		free(*ptr2);
		*ptr2 = NULL;
	}
	return ;
}

char	*subfunc(char *s, char *substr, int start, int len)
{
	int	i;

	i = 0;
	while (s[start] && len)
	{
		substr[i++] = s[start++];
		len--;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*substr;
	int		slen;
	
	slen = ft_strlen(s);
	substr = NULL;
	if (!s || !*s)
		return (0);
	if ((int)start > slen)
		return (ft_strdup(""));
	if (slen == (int)len)
		substr = (char *)malloc(sizeof(char) * len - start + 1);
	else if (slen + start >= len)
		substr = (char *)malloc(sizeof(char) * len + 1);
	else if (slen + start < len)
		substr = (char *)malloc(sizeof(char) * slen + 1);
	if (!substr)
		return (NULL);
	return (subfunc(s, substr, start, len));
}

