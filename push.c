#include "push_swap.h"
#include  <stdlib.h> 
stack_t *   pa(stack_t* stack_a ,  stack_t*  stack_b)
{
    if(stack_a == NULL)
        exit(1);  
    if(stack_b == NULL)
        { 
            stack_b =  create_node(stack_a->data) ;
        } 
    return stack_a->next ;  
 }
stack_t *  pb(stack_t* stack_a , stack_t*  stack_b)
{

 if(stack_b == NULL)
        exit(1);  
    if(stack_a == NULL)
        { 
            stack_a =  create_node(stack_b->data) ;
        } 
    return stack_b->next ;  
} 
void sa(stack_t *  stack_a )
{
    if(!stack_a )
          exit(1) ; 
     int   helper  ;  
     helper = stack_a->data ;  
     stack_a->data =  stack_a->next->data ;  
     stack_a->next->data = helper ;  
} 