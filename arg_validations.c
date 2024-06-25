#include <unistd.h> 
#include <stdlib.h>
//args validations and reject 
//what should i check : 
//if args have an alphab 
// if args have an space 
// ,,,,,,,, points or an another symboles 
    int	ft_isdigit(int c)
    {
	return (c >= '0' && c <= '9');
    }

void check_args_numerique(int ac  , char **  av)
{
    int i = 1 ;  

    while(i < ac)
    {
        if(!ft_isdigit(av[i++])) 
            exit(1); 
    }
} 
void check_for_repit(int ac ,  char **av)
{
    int i = 1 ; 
    int  j = i ; 
    while(i <  ac )
    {
        j = i ;  
        while(j < ac)
        {
            if(av[i] == av[j++] ) 
                exit(1) ; 

        } 
        i++;  
    }  
} 