#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

// Insert at end
void insert(int value)
{
    struct node *newnode, *temp;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = NULL;

    if(head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
}

// Display forward
void display()
{
    struct node *temp;
    temp = head;

    while(temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

int main()
{
    insert(10);
    insert(20);
    insert(30);

    printf("Doubly Linked List:\n");
    display();

    return 0;
}