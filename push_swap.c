#include "push_swap.h"

//todo ==  fix parsing things  n negative numbers and some additional things  
// wondering whhy 500 numbers gives me 13000 moves 
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
  if(algo_data->size == 3 ) 
    sort_three(&stack_a ,&stack_b )  ;  
  else if(algo_data->size == 5 ) 
     sort_five(&stack_a,&stack_b) ; 
  else if (algo_data->size ==  4 )
      sort_four(&stack_a , &stack_a ) ;  
  else { 
large_sort(&stack_a,&stack_b,tab_tmp,algo_data->size)  ; 
sort_stack_b(&stack_a,&stack_b ) ; 
  }
stack_t *tmp = stack_a ;  
while(tmp) 
{ 
  printf("%d \n ",tmp->data ) ;  
  tmp = tmp->next ;  
}

 } 