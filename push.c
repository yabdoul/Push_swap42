#include "push_swap.h"
#include  <stdlib.h> 
//pb is test  and its good 
void pb(stack_t **stack_a, stack_t **stack_b)
{
    if (*stack_a == NULL) {
        printf("stack_a is NULL in pb function\n");
        return;
    }

    stack_t *top = *stack_a;  // Store the top element of stack_a
    *stack_a = (*stack_a)->next;  // Move stack_a to the next element

    if (*stack_b == NULL) {
        *stack_b = top;  // If stack_b is empty, top becomes the new top of stack_b
        (*stack_b)->next = NULL;  // Ensure the new top of stack_b points to NULL
    } else {
        top->next = *stack_b;  // Attach the top element to the current stack_b
        *stack_b = top;  // Update stack_b to point to the new top element
    }
}

void pa(stack_t **stack_a, stack_t **stack_b)
{
    printf("pb\n");

    if (*stack_b == NULL) {
        return; 
    }
    stack_t *top_b = *stack_b; 
    *stack_b = (*stack_b)->next; 
    if (*stack_a == NULL) {
        *stack_a = top_b; 
        (*stack_a)->next = NULL; 
    } else {
        top_b->next = *stack_a; 
        *stack_a = top_b; 
    }
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
void sb(stack_t *  stack_b )
{
    if(!stack_b )
          exit(1) ; 
     int   helper  ;  
     helper = stack_b->data ;  
     stack_b->data =  stack_b->next->data ;  
     stack_b->next->data = helper ;  
} 
void ss(stack_t  *stack_a  ,  stack_t * stack_b)
{
    if(!stack_a ||  !stack_b )
        exit(1) ;  
    sa(stack_a) ;
    sb(stack_b )  ; 
} 
void ra(stack_t *stack_a) {
    if (stack_a == NULL || stack_a->next == NULL) {
        return;
    }
    stack_t *first = stack_a;
    stack_t *tmp = stack_a;
    int  last = 0;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    last = tmp->data ;
    tmp->data = first->data ;
    tmp =  stack_a ;  
    while((tmp->next)->next != NULL )
    {
        tmp->data = tmp->next->data ;  
        tmp = tmp->next  ; 
    } 
    tmp->data =last ; 
}
void rb(stack_t *stack_b) {
    if (stack_b == NULL || stack_b->next == NULL) {
        return;
    }
    stack_t *tmp = stack_b;
    int  last = 0;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    last = tmp->data ;
    tmp->data = stack_b->data ;
    tmp =  stack_b ;  
    while((tmp->next)->next != NULL )
    {
        tmp->data = tmp->next->data ;  
        tmp = tmp->next  ; 
    } 
    tmp->data =last ; 
}
void rr(stack_t *stack_a , stack_t *stack_b)
{ 
    if(!stack_a ||  !stack_b)
        exit(1); 
     ra(stack_a); 
    rb(stack_b );   
}
void rra(stack_t** stack_a) {
    stack_t *prev = NULL ;  
    stack_t *current= *stack_a  ;  
     while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    if (prev != NULL) {
        prev->next = NULL;
        current->next = *stack_a;
        *stack_a = current;
    }
}
void rrb(stack_t ** stack_b) 
{ 
    if(!*stack_b) 
        exit(1) ; 
      stack_t *last   = NULL  ;
    stack_t *tmp =  *stack_b  ;  
    while(tmp->next->next)
        tmp = tmp->next ; 
    last = tmp->next ; 
    tmp->next = NULL ; 
    last->next = *stack_b ; 
    (*stack_b) = last ;  
}
void rrr(stack_t **  stack_a ,  stack_t ** stack_b)
{
    if(!*stack_a || !*stack_b) 
     exit(1) ;  
    rra(stack_a);
    rrb(stack_b);  
} 