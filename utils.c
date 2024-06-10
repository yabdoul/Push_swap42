#include <stdlib.h>
#include <stdio.h>
int	ft_isdigit(int c)
{
	return ((c >= '0' && c <= '9')|| c == '-');
}
//actions 

void push_b(int stack_a[],int stack_b[], int size) 
{
	int  i = 0 ; 
	if(!stack_a)
		return ;
	stack_b[0] =  stack_a[0];  
	while(i < size )
	{
		stack_a[i] =  stack_a[i+1] ; 
		i++ ; 
	}
	stack_a + i == NULL ; 
}
void push_a(int stack_a[] ,  int stack_b [], int size)
{ 
	int i  = 0 ; 
	if(!stack_b) 
		return ; 
	stack_a[0] = stack_b[0] ; 
	while(i < size  && stack_a[i] &	stack_b[i])
	{
		stack_b[i] =  stack_b[i+1] ; 
		i++ ; 
	}
	stack_a + i == NULL ; 
} 
void swap_a(int stack_a[] )
{
int temp ; 
temp =  stack_a[0] ;
stack_a[0] =  stack_a[1]; 
stack_a[1] = temp; 
}
void swap_b(int stack_b[])
{
int temp ; 
temp =  stack_b[0] ;
stack_b[0] =  stack_b[1]; 
stack_b[1] = temp; 
} 
void ra(int stack_a[] , int size )
{
	int i   = 0 ; 
	if(!stack_a[0] ) 
		return  ; 
	while( i <  size)
	{ 
		if(i == 0)
		{
		int tmp  = stack_a[0] ; 
		stack_a[0] = stack_a[size-1] ; 
		stack_a[size - 1 ] = tmp ;   
		}
		else{
			stack_a[i+1]  = stack_a[i] ; 
		 }
		i++ ; 
	} 
} 
void  rb( int stack_b [], int size)
{
		int i   = 0 ; 
	if(!stack_b[0] ) 
		return  ; 
	while( i <  size)
	{ 
		if(i == 0)
		{
		int tmp  = stack_b[0] ; 
		stack_b[0] = stack_b[size-1] ; 
		stack_b[size - 1 ] = tmp ;   
		}
		else{
			stack_b[i+1]  = stack_b[i] ; 
		 }
		i++ ; 
	} 
}
void rr(int stack_b [] , int stack_a[], int size)
{
	rb(stack_a , size) ; 
	ra(stack_b , size) ; 

} 
void sort_three(int stack_a[] , int stack_b[])
{
	
} 

int main()
{
	int i  = 0; 
	int stack_a[5]={4,1,3,2,1} ; 
	int stack_b[5]={2,5,7,8,1};  
	push_a(stack_a,stack_b,5); 
	while(i < 5 &&  stack_a[i])
	{
		printf("[stack _b] : %d\n",stack_a[i++]); 
		// i++ ; 
	} 
} 