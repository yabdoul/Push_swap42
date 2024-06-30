#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#endif
#include <stdlib.h>
#include <stdio.h> 
typedef struct stack_s {
    int data;
     struct stack_s* next;
} stack_t;

stack_t* create_node(int data);
stack_t* add_to_list(stack_t* head, stack_t *node); // Assuming you want to add to the head of the list
void stack_to_list(int ac, char** av,stack_t * head);
void  check_final(int ac ,  char ** av ); 
char	**ft_split(const char  *s, char c) ; 
char	*ft_strjoin(char const *s1, char const *s2); 
size_t	ft_strlen(char *s);
char ** parse_args(int ac, char **av,int * length); 
int	ft_isdigit(char* c); 
stack_t *stack_from_args(char **args , int ac ); 
void check_for_repeat(int ac ,  char ** av ) ; 
stack_t *  pa(stack_t * stack_a ,  stack_t *  stack_b) ; 
stack_t *  pb(stack_t* stack_a , stack_t*  stack_b); 
void sa(stack_t * stack_a) ;  
void sb(stack_t *  stack_b); 
void ra(stack_t * stack_a); 
void rb(stack_t *stack_b); 
void rr(stack_t *stack_a , stack_t * stack_b );  