/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnait-el <rnait-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 14:03:41 by rnait-el          #+#    #+#             */
/*   Updated: 2022/06/14 18:12:55 by rnait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

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

char	*find_line(char **str)
{
	int		counter;
	char	*line;
	char	*temp;

	counter = 0;
	if (**str == '\0')
		return (NULL);
	while ((*str)[counter] && (*str)[counter] != '\n')
		counter++;
	line = ft_substr(*str, 0, counter + 1);
	if ((*str)[counter])
		temp = ft_substr(*str, counter + 1, 1000);
	else
		temp = ft_strdup("");
	free (*str);
	*str = temp;
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*str;
	static char	*saved;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = malloc(sizeof(char) * BUFFER_SIZE + 1);
	i = 1;
	while (i > 0 && check_newline(saved))
	{
		i = read(fd, str, BUFFER_SIZE);
		if (i < 0)
		{
			free_pointers(&str, &saved);
			return (NULL);
		}
		str[i] = '\0';
		saved = ft_strjoin(&saved, str);
	}
	line = find_line(&saved);
	free_pointers(&str, NULL);
	if (*saved == 0)
		free_pointers(&saved, NULL);
	return (line);
}
