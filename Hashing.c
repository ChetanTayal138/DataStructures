#include<stdio.h>
#include<stdlib.h>

#define INT_NONE -1






void insert(int arr[] , int hashn , int size)
{
	int n=0 ;
	int inserting_number ;
	int pos ;

	printf("ENTER THE NUMBER TO INSERT\n");
	scanf("%d" , &inserting_number);

	pos = inserting_number%hashn;

	while(arr[pos] != INT_NONE)
	{
		n = n+1;
		if(n==size)
			break;
		pos = (pos+1)%hashn;
	}

	if(n==size)
	{
		printf("NO MORE SPACE TO INSERT NUMBER IN HASH TABLE\n");
	}

	else
	{
		arr[pos] = inserting_number ;
	}

}



void delete(int arr[] , int hashn , int size)
{

	int n = 0 ;
	int deleting_number ;
	int pos ;

	printf("ENTER NUMBER TO DELETE\n");
	scanf("%d" , &deleting_number);

	pos = deleting_number%hashn;

	while(arr[pos] != deleting_number)
	{
		n = n+1;
		if(n==size)
			break;
		pos = (pos+1)%hashn;
	}

	if(n==size)
	{
		printf("NUMBER COULD NOT BE DELETED\n");
	}

	else
	{
		arr[pos] = INT_NONE;
	}

}



void search(int arr[] , int hashn , int size)
{
	int searching_number ;
	int pos ;
	int n = 0 ;

	printf("ENTER THE NUMBER TO SEARCH FOR\n");
	scanf("%d" , &searching_number);

	pos = searching_number%hashn;

	while(arr[pos] != searching_number)
	{
		n = n+1 ;
		if(n==size)
			break;
		pos = (pos+1)%hashn;
	}

	if(n==size)
	{
		printf("NUMBER WAS NOT FOUND\n");
	}

	else
	{
		printf("%d FOUND AT POSITION %d\n",arr[pos] , pos);
	}

}



void display(int arr[] , int size)
{
	int i;
	printf("POS\tDATA\n");

	for(i=0 ; i<size ; i++)
	{
		printf("%d\t%d\n",i , arr[i] );
	}








}




int main()
{
	int choice ;
	int size ;
	int hashn ;
	int i ;


	printf("ENTER THE SIZE OF THE HASH TABLE\n");
	scanf("%d" , &size);

    int arr[size];

    for(i = 0 ; i<size ; i++)
    {
    	arr[i] = INT_NONE;
    }

	printf("ENTER THE HASHING FUNCTION\n");
	scanf("%d" , &hashn);


	while(1)


	{


		printf("<0>EXIT\n<1>INSERT\n<2>DELETE\n<3>SEARCH\n<4>DISPLAY\n");
		printf("ENTER CHOICE\n");
		scanf("%d" , &choice);

		switch(choice)
		{
			case 0:
			exit(0);

			case 1:
			insert(arr,hashn,size);
			break;

			case 2:
			delete(arr,hashn,size);
			break;

			case 3:
			search(arr,hashn,size);

			case 4:
			display(arr,size);
		}



	}


}