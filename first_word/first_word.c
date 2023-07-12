#include <unistd.h>

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

int main(int ac, char **av)
{
    if (ac == 2)
    {
        size_t  i;
        size_t  j;
        
        i = 0;
        ft_pass(av[1], &i);
        j = i;
        while (av[1][i])
        {
            if (is_white(av[1][i]))
            {
                while (j < i)
                {
                    write(1,&av[1][j++], 1);
                }
                write(1, "\n", 1);
                return (1);
            }
            i++;
        }
        if (!is_white(av[1][i - 1]))
        {
                while (j < i)
                {
                    write(1,&av[1][j++], 1);
                }
                write(1, "\n", 1);
                return (2);
        }
    }
    write(1, "\n", 1);
}