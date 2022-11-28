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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
    n--;
	while (i < n && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char    *path_finder(char **envp)
{
    size_t  i;

    i = 0;
    while (ft_strncmp(envp[i], "PATH", 4))
        i++;
    return (&envp[i][5]);
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
