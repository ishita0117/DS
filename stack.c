#include<stdio.h>
#define size 10
void push(int);
void pop();
void display();
int stack[size],top=-1;
void main()
{
    int value,choice,x=1;
    while(1){
        printf("choose a number for instruction to perform");
        printf("\n\n 1.Push\n 2.Pop \n 3.Display \n 4. Exit \n");
        printf("enter the choice");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1 : printf("enter the value to be inserted :");
                 scanf("%d",&value);
                 push(value);
                 break;
        case 2 : pop();
                 break;
        case 3 :display();
                break;
        case 4 :exit(0);

        default :printf("\n wrong selection");
        }
    }
}
void push(int value){
if (top == size-1)
{
    printf("stack is full");
}
else{
    top++;
    stack[top]= value;
    printf("insertion sucessful");
}
}
void pop(){
if (top==-1)
{
    printf("stack is empty");
}
else {
    printf("pop:%d",stack[top]);
    top--;
}
}
void display()
{
    if (top==-1)
    {
        printf("stack is empty");
    }
    else{
        int i;
        printf("stack elements are \n");
        for (i=top;i>=0;i--)
        {
            printf("%d\n",stack[i]);
        }
    }
}
