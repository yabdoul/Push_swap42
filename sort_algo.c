#include "push_swap.h"
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
//todo making a function thts check  for the nearest  node in range and checking its top or bottom
int   get_index_nearest(stack_t* node  , int range , int  i ) 
{   
	stack_t *tmp = node; 
	int j = 0 ;  
	while(tmp) 
	{ 
		 if(tmp->index >= i  &&  tmp->index <= range + i ) 
		 	return j  ;  
		 tmp =  tmp->next ;
		 j++;    
	}
	return -1 ;  
}
void large_sort(stack_t **stack_a, stack_t **stack_b, int size ) 
{ 
	int range = 0.0375 * size + 11.75;   
	int  i = 0 ; 
	while(i < size ) 
	{  
		if((*stack_a)->index  <= i  ) 
		{  
			pb(stack_a ,  stack_b) ;  
			rb(stack_b) ;  
			i++ ; 
		}
		else if((*stack_a)->index  <= range + i  ) 
		{ 
			 pb(stack_a, stack_b ) ;  
			 i++ ; 
		}
		else if(get_index_nearest(*stack_a , range , i) <= size / 2 ) 
			{ 	
				ra(stack_a) ; 
			}
			else  
				rra(stack_a) ; 
	}
}

void sort_stack_b(stack_t ** stack_a,stack_t ** stack_b ,int size)
{
stack_t* max;
int range = 0.0375 * size + 11.75;   
while (*stack_b)
{
max = get_max(*stack_b);
int index  = get_node_index(*stack_b , max->data) ; 
if(index == 0 ) 
{ 
	pa(stack_a , stack_b)  ; 
}
else if (index<= range )
{
	rb(stack_b) ; 
}
else { 
	rrb(stack_b) ; 
}

}
}