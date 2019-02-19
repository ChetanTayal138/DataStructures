#include<stdio.h>
#include<stdlib.h>

int n ; 

void swap(int *a , int *b)
{
	int temp ; 
	temp = *a ;
	*a = *b ;
	*b = temp ;

}


void heapify(int a[10] , int i)
{
	int left , right , largest ;
	left = 2*i ;
	right = 2*i + 1;

	if(left <= n && a[left] > a[i])
		largest = left ;

	else
		largest = i;

	if(right <= n && a[right] > a[largest])
		largest = right ;
	
	if(largest != i)
	{
		swap(&a[i] ,&a[largest]);
		heapify(a, largest);
	}
}

void buildMAXheap(int a[10])
{
	int i ;
	for(i=n/2;i>=1	;i--)
	{
		heapify(a,i);
	}
}

int extractMax(int a[10])
{
	int max ;
	if(n==0)
		{
			printf("EMPTY HEAP\n");
			return -1;
		}

	else
	{
		max = a[1];
		a[1] = a[n];
		n = n-1;
		heapify(a,1);
		return max; 

	}

}





int main()
{
	int a[10], i , choice ;

	while(1)
	{
		printf("\nENTER CHOICE\n<1>CREATE HEAP\n<2>DELETE\n<3>EXIT\n");
		scanf("%d" , &choice);
		switch(choice)
		{
			case 1:
			printf("ENTER VALUE\n");
			scanf("%d" , &n);
			printf("READING ELEMENTS\n");
			for(i=1 ; i<= n ; i++)
			{
				scanf("%d" , &a[i]);
			}
			buildMAXheap(a);
			printf("ELEMENTS OF HEAP ARE\n");
			for(i=1 ; i<= n ; i++)
			{
				printf("%d\t",a[i]);
			}
			break;
			
			case 2:
			printf("THE ELEMENT RETRIEVED IS %d\n" , extractMax(a));
			printf("ELEMENTS AFTER DELETION\n");
			for(i=1 ; i<=n ; i++)
			{
				printf("%d\t",a[i]);
			}
			break;
			case 3:
			exit(0);

		}


	}
}