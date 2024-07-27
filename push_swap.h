#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#endif
#include <stdlib.h>
#include <stdio.h> 
typedef struct stack_s {
    int data;
    int index ; 
    struct stack_s* next;
} stack_t;
typedef struct data_s { 
    int size;  
    int rem ; 
    int pivot1; 
    int pivot2;  
} data_t ;  
stack_t* create_node(int data);
stack_t* add_to_list(stack_t* head, stack_t *node); 
void stack_to_list(int ac, char** av,stack_t * head);
void  check_final(int ac ,  char ** av ); 
char	**ft_split(const char  *s, char c) ; 
char	*ft_strjoin(char const *s1, char const *s2); 
size_t	ft_strlen(char *s);
char ** parse_args(int ac, char **av,int * length); 
int	ft_isdigit(char* c); 
stack_t *stack_from_args(char **args , int ac ); 
void check_for_repeat(int ac ,  char ** av ) ; 
void  pa(stack_t **stack_a ,  stack_t **  stack_b) ; 
void pb(stack_t **stack_a, stack_t **stack_b);
void sa(stack_t ** stack_a) ;  
void sb(stack_t **  stack_b); 
void ra(stack_t ** stack_a); 
void rb(stack_t ** stack_b); 
void rr(stack_t **stack_a , stack_t ** stack_b );  
void rra(stack_t ** stack_a );
void rrb(stack_t ** stack_b) ; 
void rrr(stack_t ** stack_a ,  stack_t** stack_b) ;  
int * args_to_array(stack_t * stack_a);  
void sort_array(int * arr , stack_t * stack_a);  
void indexing(int *arr ,  stack_t * stack_a );   
void sort_five(stack_t **stack_a ,stack_t ** stack_b)  ; 
void sort_three(stack_t ** stack_a ,  stack_t ** stack_b) ; 
void sort_four(stack_t **stack_a , stack_t **stack_b)  ;  
void set_algo_data(stack_t *stack_a , data_t * data )  ;  
int  get_node_index(stack_t *stack  , int val )  ;  
int pivot_cmp(int pivot1 , stack_t * stack_a )   ; 
size_t lst_size(stack_t *head)  ; 
void large_sort(stack_t **stack_a, stack_t **stack_b, int size )   ;  
void sort_stack_b(stack_t **sa,stack_t **sb,int size)  ; 
stack_t* get_max(stack_t *stack)   ;  