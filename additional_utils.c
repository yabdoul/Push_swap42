void check_sorted(stack_t *stack_a)  
{  
    stack_t *tmp = stack_a ;  
    while(tmp) 
    { 
        if(tmp->data > tmp->next->data)
            return ;  
         tmp = tmp->next ;  
    }
    printf("error \n") ;  
    free_all(stack_a) ;  
}