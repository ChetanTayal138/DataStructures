#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
	int co ;
	int po ;
	struct node * next ;
}NODE;

NODE * createNode()
{
	NODE * temp ;
	temp = (NODE *)malloc(sizeof(NODE));
	return temp ;
}

NODE * insertEnd(NODE * start , int co , int po)
{
	NODE * newNode;
	NODE * temp ;
	newNode = createNode();
	newNode->co = co;
	newNode->po = po;
	newNode->next = NULL ;

	if(start == NULL)
	{
		start = newNode ;
		return start ;
	}

	else
	{
		temp = start;
		while(temp->next != NULL)
		{
			temp = temp->next ;
		}

		temp->next = newNode; 
	}

	return start ;
}



NODE * addtoresult(NODE * start , int co , int po)
{
	NODE * temp ;
	temp = start;

	while(temp != NULL)
	{
		if(temp->po == po)
		{
			temp->co = temp->co + co;
			return start ;
		}

		temp = temp->next ;
	}

	start = insertEnd(start , co , po);
	return start ;

}



NODE * mutiply(NODE * start1, NODE * start2)
{
	int co ;
	int po ;
	NODE * start3 ;
	start3 = NULL ;


	NODE * temp1 ;
	NODE * temp2 ;
	temp1 = start1;
	temp2 = start2;

	for(temp1 = start1; temp1 != NULL ; temp1 = temp1->next)
	{
		for(temp2 = start2 ; temp2!= NULL ; temp2 = temp2->next)
		{
			co = temp1->co * temp2->co;
			po = temp1->po + temp2->po;
			start3 = addtoresult(start3 , co , po); 

		}
	}

	return start3 ;
}


void display(NODE * start)
{
	NODE * temp ;
	temp = start;

	while(temp!= NULL)
	{
		printf("%d*x^%d +",temp->co,temp->po);
		temp = temp->next ;
	}
	printf(" 0\n");


}

int main()
{
	NODE * start1;
	NODE * start2;
	NODE * start3;
	int co ; 
	int po ;
	int choice ;

	start1 = NULL ;
	start2 = NULL ;
	start3 = NULL ;

	while(1)
	{
		printf("\n<1>ADD TO FIRST POLYNOMIAL\n<2>DISPLAY FIRST POLYNOMIAL\n<3>ADD TO SECOND POLYNOMIAL\n<4>DISPLAY SECOND POLYNOMIAL\n<5>MULTIPLY\n<6>EXIT\n");
		printf("ENTER CHOICE\n");
		scanf("%d" , &choice);

		switch(choice)
		{
			case 1:
			printf("ENTER COEFFICIENT\n");
			scanf("%d" , &co);
			printf("ENTER POWER\n");
			scanf("%d" , &po);
			start1 = insertEnd(start1 , co , po);
			break ;



			case 2:
			display(start1);
			break ;


			case 3:
			printf("ENTER COEFFICIENT\n");
			scanf("%d" , &co);
			printf("ENTER POWER\n");
			scanf("%d" , &po);
			start2 = insertEnd(start2 , co , po);
			break ;


			case 4:
			display(start2);
			break ;

			case 5:
			start3 = mutiply(start1 , start2);
			display(start3);

			case 6:
			exit(0);


		}
	}
}