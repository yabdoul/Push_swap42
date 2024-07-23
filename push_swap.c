#include "push_swap.h"
//TODO : adding index attrib and setting it  to stack_t -->done 
//TODO: implementing the 5 sort hardcode algorithme 
//TODO: implementing the large sort  algo 

int main(int ac  , char **av)
{
  check_final(ac ,av) ; 
  int  total_length = 0  ;  
stack_t *stack_b = NULL ; 
data_t *algo_data =  malloc(sizeof(data_t)); 
char ** parsed_args  =parse_args(ac ,av,&total_length) ; 
stack_t *stack_a =  stack_from_args(parsed_args,total_length);   
int  *tab_tmp = args_to_array(stack_a)  ;  
sort_array(tab_tmp,stack_a) ; 
indexing(tab_tmp,stack_a) ;  
set_algo_data(stack_a ,algo_data)  ;  
large_sort(&stack_a,&stack_b,algo_data)  ; 
 stack_t * tmp  = stack_a ;  
 while(tmp) 
 { 
  printf("%d \n ", tmp->index )  ;  
  tmp = tmp->next ; 
 }
 } 