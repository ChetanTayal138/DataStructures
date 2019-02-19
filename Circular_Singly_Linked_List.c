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



NODE * insertFront(NODE * last,  int data)
{
	NODE * newNode ;
	newNode = createNode();
	if(newNode == NULL)
	{
		printf("INSUFFICIENT MEMORY\n");	
	}

	else
	{
		newNode->data = data;
	}


	if(last == NULL)
	{
		last = newNode;
		newNode->next = last ;
		return last;

	}

	else
	{
		newNode->next = last->next ;
		last->next = newNode;
		return last ;
	}
}












NODE * insertEnd(NODE * last , int data)
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
		newNode->data = data;
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







NODE * deleteFront(NODE * last)
{
	NODE * temp ;
	NODE * next ;

	if(last == NULL)
	{
		printf("NOTHING TO DELETE\n");
	}

	else if(last->next == last)
	{
		free(last);
		return NULL;
	}

	else
	{

	NODE * temp ;
	temp = last->next ;
	next = temp->next ;
	last->next = next ;
	free(temp);
	return last ;
	
	}


}



NODE * deleteEnd(NODE *last)
{
	if(last == NULL)
	{
		printf("NOTHING TO DELETE\n");
	}


	else if(last->next == last)
	{
		free(last);
		return NULL;
	}

	else
	{

	NODE * temp ;
	temp = last->next ;
	while(temp->next != last)
	{
		temp = temp->next ;
	}

	temp->next = last->next ;
	free(last);
	last = temp ;
	return last ;
	
	}

}





void display(NODE * last)
{
	NODE * temp;
	temp = last->next;

	if(last->next == NULL)
	{
		printf("EMPTY LIST\n");
	}

	else
	{

	
	while(temp != last)
	{
		printf("%d->",temp->data);
		temp = temp->next;
	}
	printf("%d",temp->data);

	}
}


int main()
{
	NODE * last ;
	last = NULL;
	int choice ;
	int insertingNumber ;

	while(1)
	{
		printf("\n<0>EXIT\n<1>INSERT FRONT\n<2>INSERT END\n<3>DISPLAY\n<4>DELETE END\n<5>DELETE FRONT\n");
		printf("SELECT YOUR CHOICE\n");
		scanf("%d" , &choice);

		switch(choice)
		{
			case 1:
			printf("ENTER THE NUMBER TO INSERT\n");
			scanf("%d" , &insertingNumber);
			last = insertFront(last, insertingNumber);
			break;

			case 2:
			printf("ENTER THE NUMBER TO INSERT\n");
			scanf("%d" , &insertingNumber);
			last = insertEnd(last , insertingNumber);
			break;

			case 3:
			printf("THE CURRENT CIRCULAR LINKED LIST IS\n");
			display(last);
			break;

			case 4:
			last = deleteEnd(last);
			break ;

			case 5:
			last = deleteFront(last);
			break;


			case 0:
			exit(0);
		}
	}


}
