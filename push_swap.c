#include "push_swap.h"
#include <stdio.h> 
#include <stdlib.h>
int main(int ac  ,char **av )
{ 
    // check_final(ac,av) ;
    // stack_t * stack_a = create_node(atoi(av[1])) ; 
    // stack_to_list(ac , av , stack_a); 
    char * test = parse_args(ac ,av) ;
    int i = 0;  
    while(test[i]) 
        printf("%c\n",test[i++]); 
} 
