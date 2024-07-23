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
stack_t* stack_from_args(char **args, int ac) {
    if (ac <= 0) {
        return NULL; // Handle edge case where there are no arguments
    }
    
    int i = 0; 
    stack_t* head = create_node(atoi(args[i++]));
    stack_t *current = head;
    
    while (i < ac) {
        current->next = create_node(atoi(args[i++]));
        current = current->next;
    }
    
    return head;
}

size_t ft_strlen( char *s)
{
    size_t leng = 0;
    int i = 0;
	while (s[i])
    {
        if (s[i] != ' ')
        {
            leng++;
        }
        i++;
    }

    return leng;
}
