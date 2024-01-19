#include <stdlib.h>
#include <string.h>

size_t  ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}
char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *subs;
    size_t  size;
    size_t  i;

    size = ft_strlen(s);
    i = 0;
    if (!s)
        return (NULL);
    if (start >= size)
    {
        subs= (char *)malloc(1);
		if (subs == NULL)
			return (NULL);
		subs[0] = '\0';
		return (subs);
    }
    subs = (char *)malloc(len + 1);
    if (!subs)
        return (NULL);
    while (i < len && s[start] != '\0')
    {
        subs[i] = s[start];
        i++;
        start++;
    }
    subs[i] = '\0';
    return (subs);
}
char *ft_strtrim(char const *s1, char const *set)
{
    size_t  i;

    if(!s1 || !set)
        return (NULL);
    
    while (*s1 && ft_strchr(set, *s1))
        s1++;
    i = ft_strlen(s1);
    while (i && ft_strchr(set, s1[i]))
        i--;
    return (ft_substr(set, 0, i + 1));
}