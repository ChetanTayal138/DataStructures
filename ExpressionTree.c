#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct node
{
	char data ;
	struct node *right_child ;
	struct node *left_child ;

}TREE ;


void postorder(TREE * root)
{
	if(root == NULL)
		return ;

	postorder(root->left_child);
	postorder(root->right_child);
	printf("%c",root->data);

}


void preorder(TREE * root)
{
	if(root == NULL)
		return ;

    printf("%c",root->data);
	preorder(root->left_child);
	preorder(root->right_child);
}


int precedence(char symbol)
{
	switch(symbol)
	{
		case '^':
		return 3;

		case '*':
		case '/':
		return 2;

		case '+':
		case '-':
		return 1;

	}

}


TREE * createNode(char x)
{
	TREE * temp ;
	temp = (TREE *)malloc(sizeof(TREE));
	temp->data = x ;
	temp->right_child = NULL;
	temp->left_child  = NULL;
	return temp ;
}


TREE * createExpressionTree(char infix[])
{
	TREE * temp ;
	int i , tree_stack_top = -1 , operator_stack_top = -1 ; //t1 is for tree stack and t2 is for operator stack
	TREE * tree_stack[15];
	TREE * operator_stack[15];
	TREE * right ;
	TREE * left  ;
	TREE * temp1 ;
	char symbol ;

	for(i = 0 ; infix[i] != '\0' ; i++)
	{
		symbol = infix[i];
		temp = createNode(symbol);

		if(isalnum(symbol))
		{
			tree_stack[++tree_stack_top] = temp ;
		}

		else
		{
			if(operator_stack_top == -1)
			{
				operator_stack[++operator_stack_top] = temp; //To insert an element in the operator stack if it is empty in the first place
			}

			else
			{

				while(operator_stack_top != -1 && precedence(operator_stack[operator_stack_top]->data) >= precedence(symbol) && operator_stack_top != '(')
				{
					temp1 = operator_stack[operator_stack_top--];
					right = tree_stack[tree_stack_top--];
					left  = tree_stack[tree_stack_top--];
					temp1->right_child = right;
					temp1->left_child  = left;
					tree_stack[++tree_stack_top] = temp1 ;
				}

				operator_stack[++operator_stack_top] = temp ;
			}
		}
	}


	while(operator_stack_top != -1)
	{
		temp1 = operator_stack[operator_stack_top--];
		right = tree_stack[tree_stack_top--];
		left  = tree_stack[tree_stack_top--];
		temp1->right_child = right;
		temp1->left_child  = left ;
		tree_stack[++tree_stack_top] = temp1 ;
	}

	return tree_stack[tree_stack_top];
}


int main()
{

	TREE * root ;
	root = NULL ;
	char infix[15];

	printf("ENTER THE EXPRESSION\n");
	scanf("%s" , infix);
	root = createExpressionTree(infix);
	printf("\nPREORDER TRAVERSAL IS\n");
	preorder(root);
	printf("\nPOSTORDER TRAVERSAL IS\n");
	postorder(root);
}
















