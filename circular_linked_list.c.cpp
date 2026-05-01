#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

// Insert at end
void insert(int value)
{
    struct node *newnode, *temp;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    if(head == NULL)
    {
        head = newnode;
        newnode->next = head;
    }
    else
    {
        temp = head;
        while(temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
    }
}

// Display circular linked list
void display()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty");
        return;
    }

    temp = head;
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while(temp != head);

    printf("(Back to Head)");
}

int main()
{
    insert(10);
    insert(20);
    insert(30);

    printf("Circular Linked List:\n");
    display();

    return 0;
}