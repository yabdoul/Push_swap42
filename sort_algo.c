#include "push_swap.h"
//sort five  12 moves 
//next step checking atgs length !! ---- 
//start implementing the larger algorithme 

int get_index_tab(int *tab , int val ,int size) 
{   
	int i = 0 ;  
	while(i < size) 
	{  
		if(tab[i] == val   ) 
			return(i) ;  
		i++ ;  
	}
	return(-1)  ; 
}
stack_t * find_min(stack_t * stack_a)  
{ 
	stack_t * min =stack_a ; 
	stack_t * helper = stack_a ;  
	while(helper) 
	{ 
		if(min->data > helper->data )
			min = helper ;  
		helper = helper->next  ; 
	}
	return min ; 
}
void sort_three(stack_t ** stack_a ,  stack_t **stack_b) 
{ 
	 stack_t *min = find_min(*stack_a )  ; 
	while(*stack_a != min )
		rra(stack_a) ;  
	pb(stack_a,stack_b) ;  
	if((*stack_a)->data > (*stack_a)->next->data ) 
	 sa(stack_a)  ; 
	pa(stack_a,stack_b) ;  
 }
void sort_four(stack_t **stack_a , stack_t **stack_b)  
{  
	 stack_t *min = find_min(*stack_a )  ;
	  while(*stack_a != min )
		rra(stack_a) ;  
	pb(stack_a,stack_b)  ;   
	 sort_three(stack_a , stack_b)  ;  
	 pa(stack_a ,stack_b) ;  
}
void sort_five(stack_t **stack_a ,stack_t **stack_b)  
{ 
 stack_t *min = find_min(*stack_a )  ;
	  while(*stack_a != min )
		rra(stack_a) ;  
	pb(stack_a,stack_b)  ; 
	sort_four(stack_a , stack_b)  ;  
	pa(stack_a,stack_b) ;  
}
void large_sort(stack_t **stack_a, stack_t **stack_b, data_t *algo_data) {
    while (*stack_a) {
        while (*stack_a && pivot_cmp(algo_data->pivot1, *stack_a)) {
            if ((*stack_a)->index < algo_data->pivot1) { 
                pb(stack_a, stack_b);
				 printf(" stack_b =  %d ",(*stack_b)->data ) ;   

			} else {
                ra(stack_a); 
            }
        }
	algo_data->rem  = algo_data->pivot1 ;  
	algo_data->pivot2 = (lst_size(*stack_a) / 6 ) + algo_data->rem ;  
	algo_data->pivot1 += lst_size(*stack_a) / 3 ; 
     }
}