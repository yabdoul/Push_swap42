#include "push_swap.h"
void  free_all(stack_t *node ) 
{ 
  stack_t *tmp = node ;  
  while(node) 
  {  
    tmp = node;  
    node = node->next ; 
    free(tmp) ;  
  }
}
void free_args(char ** parsed_args  , int size ) 
{ 
  int  i = 0 ;  
  while(i<size ) 
  { 
    free( parsed_args[i]) ; 
    i++ ;   
  } 
  free(parsed_args) ;  
}

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
    int size = algo_data->size ; 
large_sort(&stack_a , &stack_b , size)  ; 
sort_stack_b(&stack_a,&stack_b ,size ) ; 
  }
  free_all(stack_a) ;  
  free_all(stack_b) ;  
  free(tab_tmp) ;   
  free_args(parsed_args,algo_data->size) ;  
  free( algo_data) ;   
 }