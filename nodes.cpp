#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node*link;
};

int main()
{
	struct node * head = NULL , * newnode = NULL;
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("\n enter the node data:");
	scanf("%d",&newnode->data);
	newnode->link = NULL;
	head = newnode;
	printf("\n node data = %d",newnode->data);
	return 0;    
}
