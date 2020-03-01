#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isFull(void);
int isEmpty(void);
void push(int);
int pop(void);
int peek(void);
void display(void);

int stack[5];
int top = -1;

int main()
{
  
    int ch;
    while(1)
    {
    printf("Enter Choice: \n");
    printf("1. Push \n2. Pop \n3.Peek \n4.Display \5.Exit \n");
    scanf("%d \n", &ch);
    switch(ch)
    {
        case 1 :{
          int a;
            printf("Enter the Value \n");
            scanf("%d\n",&a);
            push(a);
            break;
        }
        case 2:{
            int a = pop();
            printf("%d Deleted \n",a);
            break;
        }
        case 3:{
            int a = peek();
            printf("%d is the Last Element\n",a);
            break;
        }
        case 4:{
            display();
        break;
        }
        case 5:{
            exit(1);
        }
    }
    }
}

int isFull()
{
    if(top == 5)
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

void push(int ele)
{
    if(isFull())
        printf("Stack is full. \n");
    else
    {
        top++;
        stack[top]=ele;
        printf("%d Inserted \n",ele);
    }
}

int pop()
{
    int ele;
    if(isEmpty())
        return 0;
    else
    {
        ele = stack[top];
        top--;
    }
    return ele;
}

int peek()
{
    if(isEmpty())
        return 0;
    else
    {
        return stack[top];
    }
}

void display()
{
    for(int i=0;i<5;i++)
    {
        printf("%d \n",stack[i]);
    }
}