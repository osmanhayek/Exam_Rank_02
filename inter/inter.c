#include <unistd.h>

int main(int ac, char **av)
{
    static int  hash[127] = {0};
    int i;
    if (ac == 3)
    {
        i = 0;
        while (av[2][i])
        {
            hash[(int)av[2][i]] = 1;
            i++;
        }
        i = 0;
        while (av[1][i])
        {
            if (hash[(int)av[1][i]] == 1)
            {
                write(1, &av[1][i], 1);
                hash[(int)av[1][i]] = 0;
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}