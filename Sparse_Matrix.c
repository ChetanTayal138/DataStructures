#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
	int data ;
	struct node *prev ;
	struct node *next ;
	int row ; 
	int col ; 
	
}NODE;



NODE * createNode(int data , int row , int col)
{
	NODE * temp ;
	temp = (NODE *)malloc(sizeof(NODE));
	temp->next = NULL ;
	temp ->prev = NULL ;
	temp->data = data ;
	temp->row = row ;
	temp->col = col ;
	return temp ;
}

NODE * insertEnd(NODE * start , int data , int row , int col)
{
	NODE * temp ;
	NODE * newNode;

	newNode = createNode(data , row , col);

	if(start == NULL)
	{
		start = newNode ;
		return start ;
	}

	else
	{
		temp = start ;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		
		temp->next = newNode ;
		newNode->prev = temp ;
		return start;
	}
}


int check_dll(NODE * start , int row , int col)
{
	NODE * temp ;
	temp = start ;

	while(temp != NULL)
	{
		if(temp->row == row && temp->col == col)
		{
			return temp->data;
		}
		temp = temp->next;
	}

	return 0 ;
}



void display(NODE * start , int rows , int cols)
{
	int i ;
	int j ;
	int temp;

	for(i=0;i<rows;i++)
	{
		for(j=0;j<cols;j++)
		{
			temp = check_dll(start , i , j);
			printf("%d\t",temp);
		}

		printf("\n");
	}

}


int main()
{
	int insertingData;
	int insertingRow ;
	int insertingCol ;
	int rows ;
	int cols ;
	int size ;
	int count = 0 ;
	NODE * start ;
	start = NULL ;

	printf("ENTER NUMBER OF ROWS\n");
	scanf("%d" , &rows);
	printf("ENTER NUMBER OF COLUMNS\n");
	scanf("%d" , &cols);

	printf("ENTER HOW MANY NUMBER TO INSERT\n");
	scanf("%d" , &size);

	while(count != size)
	{
		printf("ENTER NUMBER %d 's DATA\n", count + 1);
		scanf("%d" , &insertingData);
		printf("ENTER NUMBER %d 's ROW\n", count + 1 );
		scanf("%d" , &insertingRow);
		printf("ENTER NUMBER %d 's COLUMN\n", count + 1);
		scanf("%d" , &insertingCol);

		start = insertEnd(start , insertingData , insertingRow , insertingCol);
		count = count + 1 ;
	}

	display(start, rows , cols);

}