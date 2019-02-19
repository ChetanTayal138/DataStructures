#include<stdio.h>
#include<stdlib.h>
#define SIZE 5 


struct queue
{
    int front ;
    int rear ;
    int a[SIZE] ;
};


void insert(struct queue *q , int insertingNumber)
{
    if(q->front == (q->rear+1)%SIZE)
    {
        printf("CIRCULAR QUEUE IS FULL\n");
        return ;
    }

    else
    {
        q->rear = (q->rear+1)%SIZE ;
        q->a[q->rear] = insertingNumber;
        printf("%d WAS INSERTED\n", q->a[q->rear]);
        if(q->front == -1)
        {
            q->front = 0;
        }

        return ;
    }

}


void delete(struct queue *q)
{
    if(q->front == -1)
    {
        printf("CIRCULAR QUEUE IS EMPTY\n");
        return ;
    }

    else if(q->front == q->rear)
    {
        printf("%d WAS REMOVED\n",q->a[q->front]);
        q->front = q->rear = -1;
    }

    else
    {
        printf("%d WAS REMOVED\n",q->a[q->front]);
        q->front = (q->front+1)%SIZE; 
        return ;
    }
}

void display(struct queue *q)
{
    int i ;

    if(q->front == -1)
    {
        printf("CIRCULAR QUEUE IS EMPTY\n");
        return ;
    }

    if(q->front <= q->rear)
    {
        for(i=q->front ; i <= q->rear ; i++)
        {
            printf("%d->",q->a[i]);
        }
    }

    else
    {
        for(i=q->front ; i < SIZE ; i++)
        {
            printf("%d->", q->a[i]);
        }

        for(i=0 ; i <= q->rear ; i++)
        {
            printf("%d->",q->a[i]);
        }
    }
}









int main()
{
    int choice ;
    struct queue q ;
    q.front = -1;
    q.rear  = -1;

    int insertingNumber;


    while(1)
    {
        printf("\n<1>INSERT\n<2>DELETE\n<3>DISPLAY\n<4>EXIT\n");
        printf("ENTER CHOICE\n");
        scanf("%d" , &choice);

        switch(choice)
        {

            case 1:
            printf("ENTER NUMBER TO INSERT\n");
            scanf("%d" , &insertingNumber);
            insert(&q , insertingNumber);
            break ;

            case 2:
            delete(&q);
            break ;


            case 3:
            printf("THE CURRENT CIRCULAR QUEUE IS\n");
            display(&q);
            break;

            case 4:
            exit(0);




        }


    }

}













