#include <stdlib.h>
#include <string.h>
#include "push_swap.h"
int add_checker(char *s) 
{  
    int  i = 0 ; 
    int checker = 0 ;    
    while(s[i]) 
        { 
            if(s[i] == '-' || s[i] == '+') 
            checker++ ; 
        i++ ; 
        }
        if(checker  <= 1  ) 
            return 1 ;  
        else  
            return 0 ;  
}
char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] && (unsigned char)c != s[i])
		i++;
	if (s[i] == (unsigned char)c)
		return ((char *)&s[i]);
	return (NULL);
}

void free_chars(char **str, int size)
{
    int i = 0;
    while (i < size)
    {
        free(str[i]);
        i++;
    }
    free(str);
}

char **rem_space(char *av)
{
    char **result = ft_split(av, ' ');
    if (!result)
    {
        return NULL;
    }
    return result;
}

char** parse_args(int ac, char **av, int *length)
{
    int i = 1, j;
    int total_length = 0;
    int index = 0;

    while (i < ac)
        total_length += ft_strlen(av[i++]);

    char **parsed_args = malloc(sizeof(char *) * (total_length + 1));
    if (parsed_args == NULL)
        return NULL;

    i = 1;
    while (i < ac)
    {
        char **tmp = rem_space(av[i++]);
        if (!tmp)
        {
            free(parsed_args);
            return NULL;
        }

        j = 0;
        while (tmp[j])
         {
            if(!add_checker(tmp[j])) 
                { 
                    printf("error \n ") ;  
                    exit(-1);  
                } 
            parsed_args[index++] = tmp[j++];
         } 
        free(tmp);
    }
    parsed_args[index] = NULL;
    *length = index;
    check_for_repeat(index, parsed_args);
    return parsed_args;
}
