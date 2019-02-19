#include<stdio.h>
#include<stdlib.h>


typedef struct node 
{
	int data ;
	struct node * next ;
}NODE ;



NODE * createNode()
{
	NODE * temp ;
	temp = (NODE *)malloc(sizeof(NODE));
	return temp;
}


NODE * insertRear(NODE * last , int data)
{
	NODE * newNode;
	newNode = createNode();

	if(newNode == NULL)
	{
		printf("INSUFFICIENT MEMORY\n");
		return last ;
	}

	else
	{
		newNode->data = data ;
	}



	if(last == NULL)
	{
		last = newNode;
		newNode->next = last ;
		return last ;
	}

	else
	{
		newNode->next = last->next ;
		last->next = newNode;
		last = newNode;
		return last ;

	}
}


void display(NODE * last)
{
	NODE * temp;
	temp = last->next ;

	if(last == NULL)
	{
		printf("EMPTY LIST\n");
	}
	else
	{

	while(temp != last)
	{
		printf("%d->",temp->data);
		temp = temp->next ;
	}
	printf("%d",temp->data);

	}
}



int survivor(NODE * last , int k )
{
	NODE * temp ;
	NODE * prev ;
	int i ;

	temp = last->next ;
	prev = NULL ;

	while(temp->next != temp)
	{
	for(i=1 ; i<k ;i++)
	{
		prev = temp ;
		temp = temp->next;
	}

	prev->next = temp->next ;
	printf("%d has died\n",temp->data);
	free(temp);
	temp = prev->next ;
	}

	return temp->data;
}





int main()
{
	int number ;
	int k , sur , i;
	NODE * last ;
	last = NULL ;

	printf("READ NO. OF PEOPLE\n");
	scanf("%d" , &number);
	for(i=1 ; i<=number ; i++)
	{
		last = insertRear(last , i);
	}

	display(last);

	printf("\nGIVE K\n");
	scanf("%d" , &k);
	sur = survivor(last , k);
	printf("%d is survivor\n");

}