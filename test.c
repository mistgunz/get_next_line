# include "get_next_line.h"
# include <stdio.h>

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
		return ;
	if (s)
		while (s[i] != '\0')
			write(fd, &s[i++], 1);
}

int main()
{

//char* str;
int fd;

fd = open("x",O_RDWR|O_CREAT);
//ft_putstr_fd("xxxxxxxxxxxxxxxxabcfw \n fwfegeg gegeege \n fgrggreg\ngwgwtgtws",fd);

//printf("%d \n",fd);
printf("%s",get_next_line(fd));
printf("%s",get_next_line(fd));
printf("%s",get_next_line(fd));
printf("%s",get_next_line(fd));
printf("%s",get_next_line(fd));
}