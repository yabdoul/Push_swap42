#include "push_swap.h"
#include <stdio.h> 
#include <stdlib.h>
int check_arg(char * arg)
{
    int  i = 0 ; 
   while(arg[i])
        if(!ft_isdigit((int)arg[i++]))
          {
            printf("Error !\n");
            exit(1); 
          } 
     
}
int fill_stack(char**arg , int *  stack , int size)
{
  int i = 1; 
  while(i < size)
  {
    stack[i]=atoi(arg[i]);        
    i++ ; 
  } 
}

int main(int ac , char **av)
{
    int stack_a[ac-1]  ;  
    int stack_b[ac-1] ; 
    int  i = 1 ; 
    while(i <  ac)
      check_arg(av[i++]); 
    fill_stack(av , stack_a, ac);
    i= 1 ;  
    while(i < ac )
      printf("%d \n",stack_a[i++]); 
    return 0; 
} 