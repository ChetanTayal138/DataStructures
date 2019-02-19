#include<stdio.h>
#include<stdlib.h>
#define SIZE 5 

struct queue
{
    int a[SIZE];
    int front ; 
    int rear ;

};




void insert(struct queue *q , int insertingNumber)
{
    if(q->front == -1)
    {
        q->front++ ;
    }

    if(q->rear == SIZE-1)
    {
        printf("NO MORE ELEMENTS CAN BE INSERTED INSIDE THE QUEUE\n");
        return ;
    }

    else
    {
        q->rear++ ;
        q->a[q->rear] = insertingNumber ;
        printf("%d WAS INSERTED\n", q->a[q->rear]);
        return ;
    }

}


void delete(struct queue *q)
{

    if(q->rear == -1)
    {
        printf("NO ELEMENTS IN THE QUEUE TO DELETE\n");
        return ;
    }



    else if(q->front == q->rear)
    {
        printf("%d WAS REMOVED FROM THE QUEUE", q->a[q->front]);
        q->front = q->rear = -1 ;  //Resets the queue as an empty queue after all the elements have been used up to store the elements and then been deleted
        return ;
    }

    else
    {
        printf("%d WAS REMOVED FROM THE QUEUE", q->a[q->front]); //The element that was first put in is pointed by front.So when deleting we remove the element pointed by front
        q->front++;
        return ;
    }

}


void display(struct queue *q)
{
    int i ; 


    if(q->front == -1)
    {
        printf("QUEUE IS EMPTY\n");
    }

    else
    {

    for(i=q->front ; i <= q->rear ; i++)
    {
        printf("%d->",q->a[i]);
    }

    }
}



int main()
{
    struct queue q ;
    int insertingNumber;
    int choice ;
    printf("QUEUE OPERATIONS\n");
    q.front = -1;
    q.rear  = -1; 

    while(1)
    {
        printf("\n<0>EXIT\n<1>INSERT\n<2>DELETE\n<3>DISPLAY\n");
        printf("ENTER CHOICE\n");
        scanf("%d" , &choice);

        switch(choice)
        {
            case 0:
            exit(0);

            case 1:
            printf("ENTER ELEMENT TO INSERT\n");
            scanf("%d" , &insertingNumber);
            insert(&q , insertingNumber);
            break; 

            case 2:
            delete(&q);
            break;


            case 3:
            printf("CURRENT QUEUE IS\n");
            display(&q);
        }
    }



}

























