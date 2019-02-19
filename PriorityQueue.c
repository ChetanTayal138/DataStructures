#include <stdio.h>
#include <stdlib.h>
#define size 5 



struct queue 
{
	int rear ;
	int front ;
	int a[size];
};



void priorityInsert(struct queue *q , int data)
{
	int i ;
	int j ;
	if(q->front == -1)
	{
		q->front = 0 ;
	}


	if(q->rear == size -1)
	{
		printf("Queue is Full\n");
		return ;
	}


	else if(q->rear == -1)
	{
		q->rear++;
		q->a[q->rear] = data;

	}

	else
	{
		checkdata(data);

	}

	q->rear++


}

void checkdata(struct queue *q , int data)
	{
		int i ;
		int j;

		for(i = 0 ; i<=q->rear ; i++)
		{
			if(data >= q->a[i])
			{
				for(j=q->rear++ ; j>q->a[i] ;j--)
				{
					q->a[j] = q->a[j-1];
				}
            q->a[i] = data;
            return ;
            }

        }
        q->a[i] = data ;


	}
	
//23 6 4 3




int priorityDelete(struct queue *q)
{
	int deletedNumber;
	if(q->front == -1)
	{
		printf("Nothing to delete\n");
		return -1;

	}

	else if(q->front == q->rear)
	{
		deletedNumber = q->a[q->front];
		q->front = q->rear = -1;
		return deletedNumber;
	}



}


void display(struct queue *q)
{
	int i;
	for(i=q->front ; i <= q->rear ; i++)
	{
		printf("%d ", q->a[i]);
	}
}






int main()
{
	int insertedNumber;
	int deletedNumber;
	int choice;
	struct queue q;
	q.front = -1;
	q.rear  = -1;

while(1)
{
	printf("\nENTER CHOICE\n");
	printf("1-ENQUEUE\n2-DEQUEUE\n3-DISPLAY\n4-EXIT\n\n");
	scanf("%d" , &choice);



	switch(choice)
	{
		case 1:
		printf("Enter number to insert\n");
		scanf("%d" , &insertedNumber);
		priorityInsert(&q , insertedNumber);
		//insert(&q , insertedNumber);
		break;

		case 2:
		deletedNumber = priorityDelete(&q);
		if(deletedNumber == -1)
		{
			printf("Nothing was removed\n");
			break;
		}
		printf("%d was removed\n" , deletedNumber);
		break;

		case 3:
		printf("Current queue is\n");
		//display(&q);
		display(&q);
		break;

		case 4:
		exit(0);
	}

}


}


