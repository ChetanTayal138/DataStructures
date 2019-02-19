#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

struct stack
{
	int a[SIZE];
	int top ;
};


void push(struct stack *s , int insertingNumber)
{
	if(s->top == SIZE -1)
		{
		printf("STACK IS FULL\n");
		return ;
		}

	else
	{
		s->top++;
		s->a[s->top] = insertingNumber ;
		return ;
	}

}


int pop(struct stack *s)
{
	int poppedNumber;
	if(s->top == -1)
	{
		printf("STACK IS EMPTY\n");
		return -1 ;
	}

	else
	{
		poppedNumber = s->a[s->top] ;
		s->top--;
		return poppedNumber;
	}
}


void display(struct stack *s)
{
	int i ;
	i = s->top;
	if(i == -1)
	{
		printf("STACK IS EMPTY\n");
	}

	else
	{
		while(i != -1)
		{
			printf("%d\n", s->a[i]);
			i--;
		}
	}
}


// void popn(struct stack *s , int numberOfPops)
// {
// 	int k ;
// 	int i ;


// 	if(s->top < numberOfPops)
// 	{
// 		printf("NOT POSSIBLE TO POP THESE MANY\n");
// 	}

// 	else
// 	{
// 		for(i=0 ; i<numberOfPops ; i++)
// 		{
// 			k = pop(s);
// 			printf("%d WAS POPPED\n",k);
// 		}
// 	}
// }

void popn(struct stack *s , int numberOfPops)
{
	if(numberOfPops ==0 )
		return;
	int x = pop(s);
	printf("%d\n", x);
	popn(s , numberOfPops - 1);
	push(s,x) ; 
}

void top3(struct stack *s)
{
	if(s->top < 3)
	{
		printf("NOT ENOUGH ELEMENTS\n");
	}

	else
	{
		printf("%d IS 3RD ELEMENT FROM TOP", s->a[s->top-2]);
	}
}


void bottom3(struct stack *s)
{
	if(s->top < 3)
	{
		printf("NOT ENOUGH ELEMENTS\n");
	}

	else
	{
		printf("%d IS 3RD ELEMENT FROM BOTTOM\n",s->a[2]);
	}
}


int main()
	{
		int choice ;
		struct stack *mystack;
		int numbertopush ;
		int numberOfPops ;
		int popped;
		mystack = (struct stack *)malloc(sizeof(struct stack));
		mystack->top = -1 ;

		while(1)
		{

		printf("******************ENTER YOUR CHOICE*********\n");
		printf("1-PUSH\n2-POP\n3-DISPLAY\n4-TOP3\n5-BOTTOM3\n6-POPN\n0-EXIT\n");
		scanf("%d" , &choice);

		switch(choice)
		{
			case 1:
			printf("ENTER NUMBER TO PUSH INTO STACK\n");
			scanf("%d" , &numbertopush);
			push(mystack , numbertopush);
			break;

			case 2:
			popped = pop(mystack);
			printf("%d WAS POPPED\n", popped);
			break;

			case 3:
			printf("THE CURRENT STACK IS\n");
			display(mystack);
			break;

			case 4:
			top3(mystack);
			break ;

			case 5:
			bottom3(mystack);
			break ;

			case 6:
			printf("HOW MANY TO POP\n");
			scanf("%d" , &numberOfPops);
			popn(mystack , numberOfPops);
			break ;


			case 0:
			exit(0);


		}
		}

	}