#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#endif

typedef struct stack_s {
    int data;
     struct stack_s* next;
} stack_t;

stack_t* create_node(int data);
stack_t* add_to_list(stack_t* head, stack_t *node); // Assuming you want to add to the head of the list
void stack_to_list(int ac, char** av,stack_t * head);
void  check_final(int ac ,  char ** av ); 
char	**ft_split(char const *s, char c) ; 