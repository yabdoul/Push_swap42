#include <stdlib.h>
#include <string.h>
#include "push_swap.h"

char * parse_args(int ac, char **av)
{
    int i = 1; 
    int j = 0, k = 0;
    int total_length = 0;
    i = 1;
    while (i < ac)
    {
        total_length += ft_strlen(av[i]);
        i++;
    }
    char *parsed_args = malloc((total_length + 1) * sizeof(char));
    if (parsed_args == NULL)
        return NULL;
    i = 1;
    k = 0;
    while (i < ac)
    {
        j = 0;
        while (av[i][j] != '\0')
        {
            parsed_args[k++] = av[i][j++];
        }
        i++;
    }
    
    parsed_args[k] = '\0';
    return parsed_args;
}