#include <unistd.h>
#include <stdlib.h>

int is_white(char c)
{
    if (c == 32 || c == 9 || c == 10)
        return (1);
    return (0);
}

void    ft_pass(char *str, size_t *i)
{
    while (is_white(str[*i]) && str[*i])
        *i = *i + 1;
}

char    *ft_strsub(char *dest, char *src, size_t start, size_t end)
{
    size_t  i;

    i = 0;
    while (start < end)
        dest[i++] = src[start++];
    dest[i] = '\0';
    return (dest);
}

void    ft_pass_first_word(char *str, size_t *i)
{
    while (!is_white(str[*i]) && str[*i])
        *i = *i + 1;
}

void    ft_putstr(char *str)
{
    size_t  i;

    i = 0;
    while (str[i])
        write(1, &str[i++], 1);
}

int main(int ac, char **av)
{
    size_t  i;
    int     t = 0;
    size_t  j;
    char    *first_world;

    if (ac > 1)
    {
        i = 0;
        ft_pass(av[1], &i);
        if (!av[1][i])
            return (write(1, "\n", 1));
        j = i;
        ft_pass_first_word(av[1], &i);
        first_world = (char *)malloc(sizeof(char) * (i - j) + 1);
        if (!first_world)
            return (2);
        ft_strsub(first_world, av[1], j, i);
        ft_pass(av[1], &i);
        while (av[1][i])
        {
            if (is_white(av[1][i]))
            {
                ft_pass(av[1], &i);
                write(1, " ", 1);
                continue;
            }
            t = write(1, &av[1][i++], 1);
        }
        if (t && !is_white(av[1][i - 1]))
            write(1, " ", 1);
        ft_putstr(first_world);
        free(first_world);
    }
    write(1, "\n", 1);
}