#include "fdf.h"

int     check_for_color()
{
    
}

char *ft_strchr(const char *s, char c)
{
    size_t i;
    char *res;
    size_t len;
    

    res = (char *)s;
    len = ft_strlen(res);
    if (c == '\0')
        return (res + len);
    i = 0;
    while (i < len)
    {
        if (s[i] == c)
            return (res + i);
        i++;
    }
    return (NULL);
}

