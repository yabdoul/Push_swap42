#include "push_swap.h" 
void lst_sort(stack_t * stack_a )  
{ 
    stack_t *tmp  = stack_a ;  
    stack_t *helper = stack_a ; 
    // int swapper = 0 ;   
    while(tmp) 
    {   
        helper =tmp;  
        while(helper)
        { 
            if(tmp->data > helper->data)  
            {  
                tmp->data = helper->data ;  
                helper->data = 4 ;     
            }
            helper = helper->next ;  
        }
        tmp = tmp->next ;  
    }
}
void sort_five(stack_t *stack_a ,stack_t * stack_b)  
{ 
    (void) stack_b ;  
    while(stack_a->next->next) 
   {  
    rra(&stack_a) ; 
     rra(&stack_a) ; 
      rra(&stack_a) ; 
   }
   printf("stack a = %d",stack_a->data) ; 
 //    lst_sort(stack_a) ; 
}