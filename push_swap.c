#include "push_swap.h"
//TODO : adding index attrib and setting it  to stack_t -->done 
//TODO: implementing the 5 sort hardcode algorithme 
//TODO: implementing the large sort  algo 

int main(int ac  , char **av)
{
  check_final(ac ,av) ; 
  int  total_length = 0  ;  
  // int i = 0  ; 
char ** parsed_args  =parse_args(ac ,av,&total_length) ; 
stack_t *stack_a =  stack_from_args(parsed_args,total_length);  
stack_t *stack_b = NULL  ; 
sort_five(stack_a,stack_b) ;  
stack_t *tmp  = stack_a  ; 
while(tmp) 
{ 
  printf("%d \n",tmp->data);  
  tmp = tmp->next ; 
}
} 