#include<stdio.h>
#include<stdlib.h>
struct node
{
    int coef;
    int exp;
    struct node *next;
};

struct node *head = NULL, *temp = NULL;
void create()
{
    struct node *newnode;
    int n, i;

    printf("Enter number of terms: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter coefficient: ");
        scanf("%d",&newnode->coef);

        printf("Enter exponent: ");
        scanf("%d",&newnode->exp);

        newnode->next = NULL;

        if(head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
}
void display()
{
	temp=head;
	while(temp!=0)
	{
		if(temp->coef!=0)
		{
			printf("%+dx^%d",temp->coef,temp->exp);
		}
		else
		{
			printf("+0");
		}
		temp=temp->next;
	}
}

int main()
{
    create();
    printf("\nPolynomial Expression:\n");
    display();
    return 0;
}
