#include <stdio.h>
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
	return temp ;
}



//INSERT FUNCTIONS


NODE * insertFront(NODE * start , int ele)
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
		newNode->data = ele ;
		newNode->next = NULL;
	}


	if(start == NULL)
	{
		start = newNode;
		return start ;
	}

	else
	{
		newNode->next = start ;
		start = newNode;
		return start;


	}
}


NODE * insertEnd(NODE * start , int ele)
	{
		NODE * temp ;
		NODE * newNode ;

		newNode = createNode();

		if(newNode == NULL)
		{
			printf("Insufficient Memory\n");
			return start;
		}

		else
		{
			newNode->data = ele ;
			newNode->next = NULL ;
		}


		if(start == NULL)
		{
			start = newNode;
			return start;
		}

		else
		{

		temp = start;

		while(temp->next != NULL)
		{
		
			temp = temp->next ;
		}

		temp->next = newNode;
		return start ;

	    }


	}









NODE * insertAtPosition(NODE * start , int ele , int position)
{
	NODE * temp ; 
	NODE * prev ; 
	NODE * newNode ;
	int current_position ; 

	newNode = createNode();

	if(newNode == NULL)
	{
		printf("Insufficient Memory\n");
		return start;
	}

	else
	{
		newNode->data = ele ;
		newNode->next = NULL ; 
	}


	if(start == NULL)
	{
		printf("THE LIST IS EMPTY\n");
		return start ;

	}


	else
	{
		temp = start ;
		current_position = 1;

		while(temp != NULL || current_position != position)
		{
			prev = temp ;
			temp = temp->next ;
			current_position = current_position + 1;

		}

		if(temp = NULL)
		{
			printf("\nINVALID POSITION\n");
			return start ;
		}

		newNode->next = temp ;
		prev->next = newNode ;


		return start ;  


	}

}








//DELETE FUNCTIONS

NODE * deleteFront(NODE * start)
{
	NODE * temp ;
	temp = start ; 

	if(start == NULL)
	{
		printf("LIST IS EMPTY , NOTHING TO DELETE\n");
		return start ;
	}

	else if(temp->next == NULL)
	{
		start = NULL ;
		free(temp);
		return start ;



	}

	else
	{
		
		start = temp->next ; 
		free(temp);
		return start ;
	}




}


NODE * deleteEnd(NODE * start)
{
	NODE * temp ; 
	NODE * prev ; 
	temp = start;

	if(start == NULL)
	{
		printf("EMPTY LIST , NOTHING TO DELETE\n");
		return start ;


	}

	else if(temp->next == NULL)
	{
		start = NULL;
		free(temp);
		return start;

	}

	else
	{

	while(temp->next != NULL)
	{
		prev = temp;
		temp = temp->next ;
	}

	prev->next = NULL;
	free(temp);
	return start;

	}

}



NODE * deleteAtPosition(NODE * start , int position)
{
	NODE * temp ;
	NODE * prev ;
	int current_position = 1 ;

	temp = start ; 

	if(start == NULL)
	{
		printf("THE LIST IS EMPTY\n");
		return start ;
	}

	else if(position == 1)
	{
		start = deleteFront(start);
		return start;
	}

	while(temp!= NULL && current_position != position)
	{
		prev = temp;
		temp = temp->next ;
		current_position = current_position + 1;
	}

	if(temp == NULL)
	{
		printf("INVALID POSITION\n");
		return start ;
	}

	prev->next = temp->next ;
	free(temp);
	return start;

    
}



NODE * reverse(NODE * start)
{
	NODE * temp ;
	NODE * prev ; 
	NODE * next ;

	prev = NULL ; //Since the first element becomes the last , it needs to point to NULL
	temp = start ;

	while(temp != NULL)
	{
		next = temp->next ;
		temp->next = prev ;
		prev = temp ;
		temp = next ;
	}

	start = prev ;
	return start ;
}



//DISPLAY FUNCTIONS
NODE * display(NODE * start)
{
	NODE * temp;
	temp = start;

	while(temp != NULL)
	{
		printf("%d->", temp->data );
		temp = temp->next ;
	}


	return start;

}




//MAIN FUNCTION


int main()
{
	NODE * start ; 
	start = NULL ;
	int choice ;
	int inserting_number = 0;
	int inserting_position ;
	int deletePosition ;


	printf("****************LINKED LIST OPERATIONS****************\n");

	while(1)
	{
		printf("\n<1>INSERT IN FRONT\n<2>INSERT AT END\n<3>INSERT AT POSITION\n<4>DELETE AT FRONT\n<5>DELETE AT END\n<6>DELETE AT POSITION\n<7>DISPLAY\n<8>EXIT\n<9>REVERSE LINKED LIST");
		printf("\nSELECT YOUR OPERATION\n");
		scanf("%d" , &choice);

		switch(choice)
		{
			case 1:
			printf("ENTER NUMBER TO INSERT\n");
			scanf("%d" , &inserting_number);
			start = insertFront(start , inserting_number);
			printf("%d WAS INSERTED IN THE FRONT\n", start->data);
			break;

			case 2:
			printf("ENTER NUMBER TO INSERT\n");
			scanf("%d" , &inserting_number);
			start = insertEnd(start , inserting_number);
			break;

			case 3:
			printf("ENTER NUMBER  AND POSITION TO INSERT\n");
			scanf("%d %d" , &inserting_number , &inserting_position);
			start = insertAtPosition(start , inserting_number, inserting_position);
			break;

			case 4:
			start = deleteFront(start);
			break ;

			case 5:
			start = deleteEnd(start);
			break;

			case 6:
			printf("ENTER THE POSITION TO DELETE AT\n");
			scanf("%d" , &deletePosition);
			start = deleteAtPosition(start , deletePosition);
			break;

			case 7:
			printf("THE CURRENT LINKED LIST IS\n");
			display(start);
			break;

			case 8:
			exit(0);

			case 9:
			start = reverse(start);
			break ;
		}
	}



}