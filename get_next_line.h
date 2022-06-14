/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnait-el <rnait-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 14:03:48 by rnait-el          #+#    #+#             */
/*   Updated: 2022/06/14 18:10:53 by rnait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*ft_strjoin(char **s1, char *s2);
size_t	ft_strlen(char *str);
char	*ft_strdup(char *src);
int		check_newline(char *saved);
void	free_pointers(char **ptr1, char **ptr2);
char	*get_next_line(int fd);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif