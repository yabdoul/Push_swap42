#include <stdlib.h>
#include <string.h>
#include "push_swap.h"

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
char ** rem_space(char *av)
{
    char **result  = malloc(ft_strlen(av) * sizeof(char *) + 1) ; 
    if(!result) 
        { 
            free(result); 
            return(NULL);   
        }  
    result = ft_split(av,' '); 
    return(result) ;  
} 
char** parse_args(int ac, char **av ,  int *  length ) {
    int i = 1, j, k;
    int total_length = 0;
    int index = 0;
    while (i < ac) {
        total_length += ft_strlen(av[i]);
        i++;
    }
    char ** parsed_args = malloc(sizeof(char *) * (total_length + 1 ));
    if (parsed_args == NULL)
        return NULL;

    i = 1;  
    total_length = 0;  
    while (i < ac) {
        char **tmp = rem_space(av[i++]);
        j = 0;
            while (tmp[j]) 
            {
                total_length += 1  ;   
                parsed_args[index++] = tmp[j++];
            }
        }
    * length   = total_length  ;  
    check_for_repeat(total_length,parsed_args) ; 
    return parsed_args;
}



