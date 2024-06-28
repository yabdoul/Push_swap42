#include "push_swap.h"
int main(int ac  , char **av)
{
  int  i = 0 ;  
  char ** parsed_args  =parse_args(ac ,av ) ; 
  while(parsed_args[i]) 
      printf("%s  \n" ,parsed_args[i++]); 

} 