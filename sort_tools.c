#include "push_swap.h"
size_t lst_size(stack_t *head) 
{
    int  i = 0 ;  
    stack_t *  tmp = head ; 
    while(tmp)
    {
        i++ ; 
        tmp = tmp->next ; 
    } 
    return i  ; 
}
int * args_to_array(stack_t * stack_a)
{ 
    int  i = 0 ; 
    if(!stack_a)
        exit(1) ; 
    int * res_arr = malloc(sizeof(int) *  lst_size(stack_a)); 
    stack_t * tmp =  stack_a ;  
    while(tmp)
    {  
        res_arr[i++] = tmp->data ;  
        tmp  = tmp->next;  
    } 
    return res_arr ;  
}
void sort_array(int * arr , stack_t * stack_a)
{
    size_t  i = 0 ;
    size_t j  = 0 ;    
    int tmp =  0 ;  
    while(i < lst_size(stack_a))
    {
        j  = i  ; 
       while(j <  lst_size(stack_a) )
       {
            if(arr[i] > arr[j])
            {
                tmp =arr[i]  ; 
                arr[i] = arr[j]  ;
                arr[j] = tmp  ;  
            }
        j++ ; 
       } 
    i++ ; 
    }
}
void indexing(int *arr , stack_t *  stack_a )
{
    size_t i = 0  ; 
    stack_t  * tmp =  stack_a ;  
    if(!arr || !stack_a) 
      exit(0) ; 
   while(tmp) 
   {
    i = 0  ; 
    while( i < lst_size(stack_a))
    {
        if(arr[i] == tmp->data)
            tmp->index = i ;  
        i++ ; 
    }
    tmp = tmp->next ; 
   }
} 
int pivot_cmp(int pivot1 , stack_t * stack_a )  
{  
    stack_t * tmp =  stack_a  ; 
     while(tmp) 
     {  
        if(tmp->data < pivot1) 
            return 1 ;   
        tmp = tmp->next ;  
     }
     return 0 ;  
}
void set_algo_data(stack_t *stack_a , data_t * data ) 
{ 
    data->size =  lst_size(stack_a)  ;
    data->pivot1= data->size / 3 ; 
    data->pivot2= (data->size / 6 ) + data->pivot1 ; 
    data->rem = data->pivot1  ; 
}