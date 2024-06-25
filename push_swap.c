#include "push_swap.h"
#include <stdio.h> 
#include <stdlib.h>
int main(int ac  ,char **av )
{
    stack_t *head = create_node(5); 
    head->next = NULL ; 
    stack_t *node  = create_node(1055); 
     stack_t *node2  = create_node(1055); 
     head =  add_to_list(node,head) ;
    head = add_to_list(node2,head); 
    // stack_t *tmp = head; 
    stack_t * tmp= head  ; 
    while(tmp !=NULL) 
        {
            printf("[]%d\n",tmp->data);
            tmp= tmp->next ; 
        }  
} 
