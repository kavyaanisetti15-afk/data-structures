# include<stdio.h>
# define MAX 5
int queue[MAX];
int front=-1;
int rear=-1;
void enqueue()
{
    int a;
    if((rear+1)%MAX==front)
    {
        printf("\noverflow");
    }
    else{
        printf("\nenter element: ");
        scanf("%d",&a);
     if(rear==-1&&front==-1)
    {
        rear=front=0;
        queue[rear]=a;
    }
    else
    {
        rear=(rear+1)%MAX;
        queue[rear]=a;
    }
    }
}
void dequeue()
{
    if(front==-1)
    {
        printf("\nunderflow");
    }
    else if(rear==front)
    {
        printf("\nthe dequeued element: %d",queue[front]);
        rear=front=-1;
    }
    else
    {
        printf("\nthe dequeued element: %d",queue[front]);
        front=(front+1)%MAX;
    }
}
void peek()
{
    if(front==-1)
    {
        printf("\nunderflow");
    }
    else
    {
        printf("\nthe front element: %d",queue[front]);
    }
}
void display()
{
    int i=front;
    if(front==-1)
    {
        printf("\nunderflow");
    }
    else
    {
    while(i!=rear)
    {
        printf("\n%d",queue[i]);
        i=(i+1)%MAX;
    }
    printf("\n%d",queue[rear]);
    }
}
int main()
{
    int choice,ch=1;
    while(ch)
    {
        printf("\n1.enqueue()\n2.dequeue()\n3.peek()\n4.display()");
        printf("\nenter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            enqueue();
            break;
            case 2:
            dequeue();
            break;
            case 3:
            peek();
            break;
            case 4:
            display();
            break;
            default:
            printf("\ninvalid option");
        }
        printf("\ndo you want another option: ");
        scanf("%d",&ch);
    }
    return 0;
}
