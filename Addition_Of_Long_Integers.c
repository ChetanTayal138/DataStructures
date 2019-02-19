#include<stdio.h>
#include<stdlib.h>



typedef struct node 
{
	int data ;
	struct node *next ;
}NODE;


NODE * createNode()
{
	NODE * temp ;
	temp = (NODE *)malloc(sizeof(NODE));
	return temp ;
}



NODE * insertFront(NODE * start , int data)
{
	NODE * newNode ;

	newNode = createNode();
	newNode->data = data ;
	newNode->next = NULL ;


	if(start == NULL)
	{
		start = newNode ;
		return start ;
	}

	else
	{
		newNode->next = start ;
		
		start = newNode ;
		return start ;
	}

}


void display(NODE * start)
{
	NODE * temp ;
	temp = start ;

	if(start == NULL)
	{
		printf("list empty\n");
	}
	else
	{


	while(temp!=NULL)
	{
		printf("%d",temp->data);
		temp = temp->next;
	}
	}
}




NODE * add(NODE * start1 , NODE * start2)
{
	int sum ;
	int carry = 0 ;
	int remainder ;

	NODE * start ;
	start = NULL ;

	NODE * temp1;
	NODE * temp2;

	temp1 = start1;
	temp2 = start2;

	while(temp1 || temp2)
	{
		sum = carry + temp1->data + temp2->data;
		remainder = sum%10;
		carry = sum/10;
		start = insertFront(start , remainder);
		temp1 = temp1->next ;
		temp2 = temp2->next ;
		//printf("yeet 1");

	}

	
	while(temp1)
	{

		sum = carry + temp1->data;
		remainder = sum%10;
		carry = sum/10;
		start = insertFront(start , remainder);
		temp1 = temp1->next ;
		printf("\nTest1\n" );

	}
	
	while(temp2)
	{

		sum = carry + temp2->data ;
		remainder = sum%10;
		carry = sum/10;
		start = insertFront(start , remainder);
		temp2 = temp2->next ;
		printf("\nTEST2\n");


	}
	

	if(carry > 0)
	{
		start = insertFront(start , carry);
	}


	return start ;
}


int main()
{
	NODE * start1 ;
	NODE * start2 ;
	NODE * start3 ;
	start1 = NULL ;
	start2 = NULL ;
	start3 = NULL ;
	int i ;
	int first_length;
	int second_length ;

	char first[100];
	char second[100];

	printf("\nENTER FIRST LONG INTEGER\n");
	scanf("%s" , first);
	printf("ENTER SECOND LONG INTEGER\n");
	scanf("%s" , second);

	for(i = 0 ; first[i]!= '\0' ; i++)
	{
		start1 = insertFront(start1 , first[i]-'0');

	}


	for(i = 0 ;second[i]!= '\0' ; i++)
	{
		start2 = insertFront(start2 , second[i]-'0');
		
	}


	start3 = add(start1, start2);
	display(start3);


}


