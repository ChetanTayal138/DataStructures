#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
	int data ; 
	struct node *next ;
	struct node *prev ;

}NODE;



//Create Node Function

NODE * createNode()
{
	NODE *temp ; 
	temp = (NODE *)malloc(sizeof(NODE));
	return temp;
}




//Insert Functions 

NODE * insertFront(NODE * start , int data)
{
	NODE * newNode ;
	newNode = createNode();

	if(newNode == NULL)
	{
		printf("Insufficient Memory\n");
		return start;
	}

	else
	{
		newNode->data = data;
		newNode->next = NULL; 
		newNode->prev = NULL;
	}


	if(start == NULL)
	{
		start = newNode ;
		return start ;
	}


	else
	{
		newNode->next = start ;
		start->prev = newNode ;
		start = newNode ;
		return start ;

	}

}


NODE * insertEnd(NODE * start , int data)
{
	NODE * newNode ;
	newNode = createNode();

	if(newNode == NULL)
	{
		printf("Insufficient Memory\n");
		return start;
	}

	else
	{
		newNode->data = data;
		newNode->next = NULL; 
		newNode->prev = NULL;
	}


	NODE * temp ;
	temp = start ;
	if(start == NULL)
	{
		start = newNode;
		return start ;
	}
	else
	{
	
	while(temp->next != NULL)
	{
		temp = temp->next ;
	}
	temp->next = newNode ;
	newNode->prev = temp ;
	return start ;

	}
}


NODE * insertAtPosition(NODE * start , int data , int position)
{
	NODE * temp ;
	NODE * prev ;
	int current_position ;

	current_position = 1 ;
	temp = start;

	NODE * newNode ;
	newNode = createNode();

	if(newNode == NULL)
	{
		printf("Insufficient Memory\n");
		return start;
	}

	else
	{
		newNode->data = data;
		newNode->next = NULL; 
		newNode->prev = NULL;
	}

	while(current_position != position)
	{
		current_position = current_position + 1;
		prev = temp ;
		temp = temp->next;
	
	}

	newNode->next = temp ;
	newNode->prev = prev ;
	prev->next = newNode ;
	temp->prev = newNode ;
	return start ;


}






//Delete Functions

NODE * deleteFront(NODE * start)
{
	NODE * temp ;

	if(start == NULL)
	{
		printf("NOTHING TO DELETE , DOUBLY LINKED LIST IS EMPTY\n");
		return start;
	}

	else if(start->next == NULL)
	{
		temp = start ;
		start = NULL ;
		free(temp);
		return start ;
	}

	else
	{
		temp = start ;
		start = temp->next ;
		start->prev = NULL ;
		free(temp);
		return start ;
	}
}



NODE * deleteEnd(NODE * start)
{
	NODE * temp ;
	NODE * prev ;

	if(start == NULL)
	{
		printf("NOTHING TO DELETE , DOUBLY LINKED LIST IS EMPTY\n");
		return start ;
	}

	else if(start->next == NULL)
	{
		start = NULL ;
		return start ;
	}

	else
	{
		temp = start ;
		while(temp->next != NULL)
		{
			prev = temp;
			temp = temp->next ;
		}

		prev->next = NULL ;
		free(temp);
		return start ;
	}
}




NODE * deleteAtPosition(NODE * start , int position)
{
	NODE * prev ;
	NODE * temp ;
	int current_position;

	temp = start ;
	current_position = 1;

	if(position == 1)
	{
		start = deleteFront(start);
		return start ;
	}

	else
	{

	while(current_position != position && temp != NULL)
	{
		prev = temp ;
		temp = temp->next;
		current_position += 1;
	}


	if(temp == NULL)
	{
		printf("Invalid Position\n");
		return start ;
	}




	
	prev->next = temp->next ; 
	free(temp);
	temp = prev->next ;
	temp->prev =  prev ;
	return start ;

	}




}









//Display Function

void display(NODE * start)
{
	NODE * temp ;
	temp = start ;

	if(start == NULL)
	{
		printf("LIST IS CURRENTLY EMPTY\n");

	}
	else
	{
		while(temp != NULL)
		{
			printf("%d->",temp->data );
			temp = temp->next ;

		}

	}
}


NODE * reverse(NODE * start)
{
	NODE * prev ;
	NODE * temp ;
	NODE * next ;

	temp = start ;
	prev = NULL ;

	while(temp != NULL)
	{
		next = temp->next ;
		temp->next = prev ; 
		temp->prev = next ;
		prev = temp ;
		temp = next ;

	}

	start = prev ;
	return start ;
}


//Main


int main()
{
	NODE * start ;
	start = NULL ;

	int choice ;
	int insertingNumber ;
	int position ;


	printf("<<<DOUBLY LINKED LIST OPERATIONS>>>\n");

	while(1)
	{
		printf("\n<1>INSERT FRONT\n<2>INSERT END\n<3>INSERT AT POSITION\n<4>EXIT\n<5>DISPLAY\n<6>DELETE FRONT\n<7>DELETE END\n<8>DELETE AT POSITION\n<9>REVERSE DOUBLY LINKED LIST\n");
		printf("\nENTER YOUR CHOICE\n");
		scanf("%d" , &choice);

		switch(choice)
		{
			case 1:
			printf("ENTER NUMBER TO INSERT\n");
			scanf("%d" , &insertingNumber);
			start = insertFront(start , insertingNumber);
			printf("%d WAS INSERTED IN THE FRONT\n",start->data );
			break;


			case 2:
			printf("ENTER NUMBER TO INSERT\n");
			scanf("%d" , &insertingNumber);
			start = insertEnd(start , insertingNumber);
			break;


			case 3:
			printf("ENTER NUMBER TO INSERT\n");
			scanf("%d" , &insertingNumber);
			printf("ENTER POSITION\n");
			scanf("%d" , &position);
			start = insertAtPosition(start , insertingNumber , position);
			break ;


			case 4:
			exit(0);

			case 5:
			display(start);
			break ;

			case 6:
			start = deleteFront(start);
			break;


			case 7:
			start = deleteEnd(start);
			break;

			case 8:
			printf("ENTER POSITION\n");
			scanf("%d" , &position);
			start = deleteAtPosition(start , position);
			break;

			case 9:
			start = reverse(start);
			break ;

		}




	}









}
