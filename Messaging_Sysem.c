#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 5

struct queue
{
	char c[SIZE][10];
	int front;
	int rear ;
};




void insert(struct queue *q , char ch[15])
{
	if((q->front) == (q->rear+1)%SIZE) 
		printf("FULL MESSAGES\n");

	else
	{
		q->rear = (q->rear+1)%SIZE;
		strcpy(q->c[q->rear] , ch);
	}

	if(q->front == -1)
		q->front = 0 ;
}




void delete(struct queue *q)
{
	char ele[15];
	if(q->front == -1)
		printf("NO MESSAGES\n");

	else
	{
		strcpy(ele , q->c[q->front]);
		if(q->front == q->rear)
			q->front = q->rear = -1 ;
		else
			q->front = (q->front+1)%SIZE;
		printf("MESSAGES RECIEVED\n");
	}
}


void display(struct queue *q)
{
	int i ;

	if(q->front == -1)
	{
		printf("NO MESSAGES\n");
	}

	else if(q->front < q->rear)
	{
		for(i=q->front;i<=q->rear;i++)
		{
			printf("%s\n" , q->c[i]);
		}

	}

	else if(q->front > q->rear)
	{
		for(i=q->front ; i <SIZE ; i++)
			printf("%s\n" , q->c[i]);

		for(i=0 ; i<= q->rear ; i++)
			printf("%s\n" , q->c[i]);
	}
}






int main()
{
	char ele[20];
	int choice ;

	struct queue q ;
	q.front = -1 ;
	q.rear  = -1 ;
	printf("MESSAGES SYSTEM\n");

	while(1)
	{
		printf("\n<1>SEND MESSAGE\n<2>DISPLAY MESSAGE\n<3>RECIEVE MESSAGE\n<4>EXIT");
		printf("\nENTER CHOICE\n");
		scanf("%d" , &choice);

		switch(choice)
		{
			case 1:
			printf("ENTER MESSAGE\n");
			scanf("%s" , ele);
			insert(&q , ele);
			break ;

			case 2:
			display(&q);
			break ;

			case 3:
			delete(&q);
			break ;

			case 4:
			exit(0);
		}

	}
}