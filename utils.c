#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"
stack_t * create_node(int data)
{
	stack_t * node  =  malloc(sizeof(stack_t)); 
	node->data = data ; 
	node->next = NULL ;
	return node ;  
}
stack_t* add_to_list(stack_t * node, stack_t * head)
{
    if (head == NULL) {
        return node;
    }

    stack_t *tmp = head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = node;

    return head; 
}
void stack_to_list(int ac , char **  av , stack_t * head )
{
	int i  = 0 ; 
	while(i <  ac )
	{
		stack_t * node = create_node(atoi(av[i++])) ; 
		add_to_list(node,head) ;  		
	}
} 