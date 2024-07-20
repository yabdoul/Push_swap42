#include <unistd.h> 
#include <stdlib.h>
#include <stdio.h>
//args validations and reject 
//what should i check : 
//if args have an alphab 
// if args have an space 
// ,,,,,,,, points or an another symboles 
    int	ft_isdigit(char* c)
    {
    int  i  = 0; 
    if(c[0] == '\0') 
        {
            printf("Error\n");  
            exit(1); 
        } 
    while(c[i]) 
    {    if((c[i] < '0' || c[i] > '9') && (c[i] != ' '))
                {
                    printf("Error\n"); 
                    exit(1);
                }
           i++ ; 
    }
    return 1;  
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
void check_for_repeat(int ac ,  char **av)
{
    int i = 1 ; 
    int  j = i ; 
    while(i < ac )
    {
        j = i + 1 ;  
        while(j < ac)
        {
            if(atoi(av[i]) == atoi(av[j++]) ) 
                exit(1) ; 
        } 

        i++;  
    }  
}

void  check_final(int ac ,  char ** av )
{ 
    check_args_numerique(ac  ,av) ;
    check_for_repeat(ac , av ); 
}
