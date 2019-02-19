#include<stdio.h>
#include<stdlib.h>



//Binary Search Tree implementation with the following operations - INSERT NODE - DELETE NODE - HEIGHT OF TREE - INORDER - PREORDER - POSTORDER



typedef struct tree 
{
	int data;
	struct tree * left_child;
	struct tree * right_child;
}TREE ; 



//Creating a node in the tree 

TREE * createNode ()
{
	TREE * temp ;
	temp = (TREE *)malloc(sizeof(TREE));
	return temp ;
}


//Inserting a node 

TREE * insertNode(TREE * root , int number_to_insert)
{
	TREE * newNode ;

	newNode = createNode();
	newNode->data = number_to_insert;
	newNode->left_child  = NULL ;
	newNode->right_child = NULL ;
	


	if(root == NULL)
	{
		root = newNode ;
		return root ;
	}

	else if(number_to_insert < root->data)
	{
		root->left_child = insertNode(root->left_child , number_to_insert);
		return root ;
	}

	else if(number_to_insert > root->data)
	{
		root->right_child = insertNode(root->right_child , number_to_insert);
		return root ;
	}

	else if(number_to_insert == root->data)
	{
		printf("NUMBER ALREADY INSIDE THE TREE\n");
		return root ;

	}


}


//Deleting a node 


//Cases possible -
//1. no child node for the NODE to be deleted 
//2. no left_child for the NODE to be deleted 
//3. no right_child for the NODE to be deleted
//4.Both child present for the NODE to be deleted




TREE * inorderSuccessor(TREE * root)
{
	TREE * temp;
	temp = root ;
	while(temp->left_child != NULL)
	{
		temp = temp->left_child;
	}

	return temp;
}


TREE * deleteNode(TREE * root , int number_to_delete)
{
	TREE * temp;

	if(root==NULL)
	{
		printf("NUMBER NOT FOUND\n");
		return root ;
	}

	else if(number_to_delete < root->data)
	{
		root->left_child = deleteNode(root->left_child , number_to_delete);
		return root ;
	}

	else if(number_to_delete > root->data)
	{
		root->right_child = deleteNode(root->right_child , number_to_delete);
		return root ;
	}


	else if(number_to_delete == root->data) //MEANS THIS CURRENT NODE IS TO BE DELETED
	{

		if(root->left_child == NULL && root->right_child != NULL) //LEFT CHILD  ABSENT  RIGHT CHILD PRESENT
		{
			temp = root->right_child;
			free(root);
			root = temp ;
			return root ;

		}


		else if(root->left_child != NULL && root->right_child == NULL) //LEFT CHILD IS PRESENT RIGHT CHILD ABSENT
		{
			temp = root->left_child;
			free(root);
			root = temp ;
			return root ;

		}

		else if(root->left_child == NULL && root->right_child == NULL)
		{
			free(root);
			return NULL;
		}

		else if(root->left_child != NULL && root->right_child != NULL)
		{
			temp = inorderSuccessor(root->right_child);
			root->data = temp->data ;
			root->right_child = deleteNode(root->right_child , root->data);
			return root;
  

		}


	}

}








//Inorder Traversal

void inorder_display(TREE * root)
{
	if(root == NULL)
	{
		return ;
	}

	else
	{
		inorder_display(root->left_child);
		printf("%d->" , root->data);
		inorder_display(root->right_child);
	}
}


//Preorder Traversal

void preorder_display(TREE * root)
{
	if(root == NULL)
	{
		return ;
	}

	else
	{
		printf("%d-",root->data);
		preorder_display(root->left_child);
		preorder_display(root->right_child);
	}
}


//Postorder Traversal



void postorder_display(TREE * root)
{
	if(root == NULL)
	{
		return ;
	}

	else
	{
		
		postorder_display(root->left_child);
		postorder_display(root->right_child);
		printf("%d-",root->data);
	}
}


//main function


int main()
{
	TREE * root ;
	root = NULL ;
	int inserting_number ;
	int deleting_number ;
	int choice ;

	printf("BINARY SEARCH TREE OPERATIONS\n");

	while(1)
	{
		printf("\n<0>EXIT\n<1>INSERT NODE\n<2>DELETE NODE\n<3>INORDER DISPLAY\n<4>PREORDER DISPLAY\n<5>POSTORDER DISPLAY\n");
		printf("SELECT YOUR OPERATION\n");
		scanf("%d" , &choice);

		switch(choice)
		{
			case 0:
			exit(0);

			case 1:
			printf("ENTER THE NUMBER TO INSERT\n");
			scanf("%d" , &inserting_number);
			root = insertNode(root , inserting_number);
			break ;

			case 2:
			printf("ENTER THE NUMBER TO DELETE\n");
			scanf("%d" , &deleting_number);
			root = deleteNode(root , deleting_number);
			break;

			case 3:
			printf("INORDER TREE IS\n");
			inorder_display(root);
			break;


			case 4:
			printf("PREORDER TREE IS\n");
			preorder_display(root);
			break;

			case 5:
			printf("POSTORDER TREE IS\n");
			postorder_display(root);
			break;

		}

	}
}





