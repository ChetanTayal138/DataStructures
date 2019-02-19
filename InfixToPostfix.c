#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define SIZE 30


struct stack
{
	int top;
	char a[SIZE]; 
};


void push(struct stack *s , char insertingSymbol)
{
	if(s->top == SIZE -1)
		{
			printf("WORD FULL\n");
			return ;
		}

	else
	{
		s->top++;
		s->a[s->top] = insertingSymbol ;
	}
}


char pop(struct stack *s)
{
	char popped ;
	if(s->top == -1)
	{
		return -1 ;
	}

	else
	{
		popped = s->a[s->top];
		s->top--;
		return popped;
	}

}


int prec(char symbol)
{

	switch(symbol)
	{
	
	case '^':
	return 5 ;

	case '*':
	case '/':
	return 3;

	case '+':
	case '-':
	return 1;
	
	}
}


void infixtopostfix(struct stack *s , char infix[30])
{
	char postfix[30]; 
	int j = 0 ;
	int i ;
	char temp ;
	char symbol;

	for(i=0 ; infix[i]!= '\0' ; i++)
	{
		symbol = infix[i];
		if(isalnum(symbol))
		{
			temp = symbol ;
			postfix[j++] = temp ;

		}

		else
		{
			switch(symbol)
			{
				case '(':
				push(s, '(');
				break;

				case ')':
				temp = pop(s);
				while(temp != '(')
				{
					postfix[j++] = temp ;
					temp = pop(s);
				}

				break ;

				case '^':
				case '*':
				case '/':
				case '+':
				case '-':

				if(s->top == -1 || s->a[s->top] == '(')
				{
					push(s , symbol);
				}

				else
				{
					while(prec(s->a[s->top]) >= prec(symbol) || s->top != -1 || s->a[s->top] != '(')
					{
						postfix[j++] = pop(s);
					}

					push(s , symbol);
				}

			}
		}
	}


	while(s->top != -1)
	{
		postfix[j++] = pop(s);
	}

	postfix[j] = '\0';
	printf("%s IS POSTFIX EXPRESSION\n" , postfix );
}






int main()
{
	struct stack mystack ;
	mystack.top = -1 ;
	char infix[SIZE];

	printf("ENTER INFIX\n");
	scanf("%s" , &infix);

	infixtopostfix(&mystack , infix);

}