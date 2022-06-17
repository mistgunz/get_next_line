/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnait-el <rnait-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 14:03:41 by rnait-el          #+#    #+#             */
/*   Updated: 2022/06/18 00:45:24 by rnait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

char	*find_line(char **str)
{
	int		i;
	char	*line;
	char	*temp;

	i = 0;
	if (**str == '\0')
		return (NULL);
	while ((*str)[i] && (*str)[i] != '\n')
		i++;
	line = ft_substr(*str, 0, i + 1);
	if ((*str)[i])
		temp = ft_substr(*str, i + 1, ft_strlen(*str));
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