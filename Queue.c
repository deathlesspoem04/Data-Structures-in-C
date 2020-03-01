#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int queue[5];
int front = 0;
int rear = 0;

void insert()
{
    if (rear==5)
        printf("Queue if full. \n");
    else 
    {
        int ele;
        scanf("%d\n",&ele);
        queue[rear] = ele;
    }
}
