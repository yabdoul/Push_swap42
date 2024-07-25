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

void large_sort(stack_t **stack_a, stack_t **stack_b,int *tab  , int size ) 
{ 
	int start ;  
	int end ;  
	
	start = 0 ;  
	if(size > 5 && size <= 100 )
		end =size / 4 ;  
	else 
		end = 30  ;   
	while(*stack_a ) 
	{ 
		if((*stack_a)->data >= tab[start] && (*stack_a)->data <= tab[end])
				{
					end ++;  
					start++ ; 
					 pb(stack_a , stack_b) ;
					if(end >= size ) 
						end = size - 1     ;
				}  
		else if ((*stack_a)->data < tab[start]) {
	end ++;  
	start++ ; 	
    pb(stack_a, stack_b);
    rb(stack_b);
	if(end >=size ) 
		end = size - 1  ; 
}
else if ((*stack_a)->data > tab[end]) {
    ra(stack_a);
}
	}	
}
void sort_stack_b(stack_t ** stack_a,stack_t ** stack_b )
{
int max_val;
int middle;
int max_index;

while (*stack_b)
{
max_val = get_max(*stack_b);
middle = lst_size(*stack_a) / 2;
max_index = get_node_index(*stack_b, max_val);
if (max_index <= middle)
{
while ((*stack_b)->data != max_val)
rb(stack_b);
}
else if (max_val >= middle)
{
while ((*stack_b)->data != max_val)
rrb(stack_b);
}
pa(stack_a, stack_b);
}
}
