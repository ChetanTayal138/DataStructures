#include<stdlib.h>
#include<stdio.h>



typedef struct node 
{
	int data;
	struct node *next;
}NODE ;




NODE * createNode()
{
	NODE * temp ;
	temp = (NODE *)malloc(sizeof(NODE));
	return temp;
}

NODE * insertFront(NODE * head , int data)
{
	NODE * newNode ;

	newNode = createNode();
	newNode->data = data ;

	if(head->next = head)
	{
		head->next = newNode;
		newNode->next = head ;
		return head;
	}

	else
	{
		newNode->next = head->next ;
		head->next = newNode;
		return head ;
	}

}



NODE * insertEnd(NODE * head , int data)
{
	NODE * newNode; 
	NODE * temp ;

	newNode = createNode();

	newNode->data = data ;

	temp = head->next ;

	if(head->next == head)
	{
		head->next = newNode;
		newNode->next = head ;
		return head;
	}

	else
	{

	temp = head->next ;

	while(temp->next != head)
	{
		temp = temp->next ;
	}

	newNode->next = head ;
	temp->next = newNode ;
	return head ;

	}



}

void display(NODE * head)
{
	NODE * temp ;

	temp = head->next ;
	while(temp!=head)
	{
		printf("%d->",temp->data );
		temp = temp->next ;
	}
}



int main()
{
	int choice ;
	int insertingNumber ;
	NODE * head ;
	head = createNode();
	head->data = 0;
	head->next = head ;

	printf("CIRCULAR LINKED LIST WITH HEADER\n");

	while(1)
	{

		printf("\n<0>EXIT\n<1>INSERTFRONT\n<2>INSERTEND\n<3>DISPLAY\n");
		printf("SELECT CHOICE\n");
		scanf("%d" , &choice);

		switch(choice)
		{
			case 0:
			exit(0);

			case 1:
			printf("ENTER NUMBER TO INSERT\n");
			scanf("%d" , &insertingNumber);
			head = insertFront(head , insertingNumber);
			break;

			case 2:
			printf("ENTER NUMBER TO INSERT\n");
			scanf("%d" , &insertingNumber);
			head = insertEnd(head  , insertingNumber);
			break ;

			case 3:
			printf("CURRENT LIST IS\n");
			display(head);
		}
	}
}