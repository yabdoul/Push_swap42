#include "push_swap.h"
#include  <stdlib.h> 
//pb is test  and its good 
//get ar
void pb(stack_t **stack_a, stack_t **stack_b)
{
    printf("pb\n ")  ;  
    if (*stack_a == NULL) {
        printf("stack_a is NULL in pb function\n");
        return;
    }

    stack_t *top = *stack_a;  
    *stack_a = (*stack_a)->next;  

    if (*stack_b == NULL) {
        *stack_b = top; 
        (*stack_b)->next = NULL;  
    } else {
        top->next = *stack_b;  
        *stack_b = top; 
    }
}

void pa(stack_t **stack_a, stack_t **stack_b)
{
    printf("pa\n ")  ;  

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
void sa(stack_t ** stack_a )
{
        printf("sa\n ")  ;  
    if(!*stack_a )
          exit(1) ; 
     int   helper  ;  
     helper = (*stack_a)->data ;  
     (*stack_a)->data =  (*stack_a)->next->data ;  
     (*stack_a)->next->data = helper ;  
} 
void sb(stack_t *  stack_b )
{
        printf("sb \n ")  ;  
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
    sa(&stack_a) ;
    sb(stack_b )  ; 
} 
void ra(stack_t **stack_a) {
    if (*stack_a == NULL || (*stack_a)->next == NULL) {
        return;
    }
    stack_t *last = *stack_a;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = *stack_a;
    *stack_a = (*stack_a)->next;
    last->next->next = NULL;
}
    
void rb(stack_t **stack_b) {
     if (*stack_b == NULL || (*stack_b)->next == NULL) {
        return;
    }
    stack_t *last = *stack_b;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = *stack_b;
    *stack_b = (*stack_b)->next;
    last->next->next = NULL;
}
void rr(stack_t *stack_a , stack_t *stack_b)
{ 
    if(!stack_a ||  !stack_b)
        exit(1); 
     ra(&stack_a); 
    rb(&stack_b );   
}
void rra(stack_t** stack_a) {
    printf("rra\n");
    if (*stack_a == NULL || (*stack_a)->next == NULL) {
        return; 
    }
    stack_t *last = *stack_a;
    stack_t *second_last = NULL;
    while (last->next) {
        second_last = last;
        last = last->next;
    }
    second_last->next = NULL; 
    last->next = *stack_a;   
    *stack_a = last;         
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