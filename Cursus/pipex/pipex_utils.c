#include "pipex.h"

size_t  ft_strlen(char *s)
{
    size_t i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

void    ft_putstr_fd(char *s, int fd)
{
    write(fd, s, ft_strlen(s));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t  	i;
	size_t		len1;
	size_t	    len2;
	char	    *str;

	if (!s1 || !s2)
        return (NULL);
	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	str = (char*)malloc(sizeof(char) * (len1 + len2 + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
    {
		str[i] = s1[i];
        i++;
    }
	i = 0;
	while (s2[i])
		str[len1++] = s2[i++];
	str[len1] = '\0';
	return (str);
}
