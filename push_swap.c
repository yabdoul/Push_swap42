#include "push_swap.h"
//TODO : adding index attrib and setting it  to stack_t -->done 
int main(int ac  , char **av)
{
  check_final(ac ,av) ; 
  int  total_length = 0  ;  
  int i = 0  ; 
  char ** parsed_args  =parse_args(ac ,av,&total_length) ; 
  stack_t *stack_a =  stack_from_args(parsed_args,total_length) ;
  stack_t *stack_b = NULL ;
  // stack_a  = pa(stack_a , stack_b);  
  // stack_a = pa(stack_a , stack_b );  
  // sa(stack_a) ;  
int * arr = args_to_array(stack_a) ; 
sort_array(arr,stack_a)  ; 
indexing(arr,stack_a) ;  
stack_t *tmp =stack_a  ; 
while(tmp)
{
printf("[%d] = [%d] \n",tmp->index , tmp->data);
tmp =  tmp->next ; 
}
} 