#include <stdio.h>
#define MAX 50
int queue_array[MAX];
int rear = -1;
int front= -1;
void display()
{
    int i;
    if (front==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue is:\n");
        for (i=front;i<=rear; i++)
        {
            printf("%d\n", queue_array[i]);
        }
        printf("\n");
    }
}
void insert()
{
    int add_item;
    if (rear==MAX-1)
    {
        printf("Queue overflow");
    }
        else{
                if(front ==-1)
                {
                    front=0;
                }
                    printf("Insert the element in queue:");
                    scanf("%d", &add_item);
                    rear=rear+1;
                    queue_array[rear]=add_item;


        }
    }
void delete()
{
    if (front==-1||front>rear)
    {
        printf("Queue underflow\n");
        return;
    }
    else{
        printf("Delete Element is: %d\n", queue_array[front]);
        front=front+1;
    }
}
void main()
{
    int choice;
    while(1)
    {
        printf("1.Insert\n 2.Delete 3.Display\n 4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(1);
            default:
                printf("Invalid choice\n");

        }

    }
}
