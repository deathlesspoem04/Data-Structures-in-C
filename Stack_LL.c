#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node* link;
};

struct node* top=NULL;

void push()
{
struct node* temp;
temp=(struct node*)malloc(sizeof(struct node*));
printf(" Enter Data : ");
scanf(" %d", &temp->data); // taking the input
temp->link=top; // top should point to new node
top=temp;

}

void pop()
{
struct node*  temp;
temp=top;
if(temp==NULL)
{
printf(" temp == NULL");
}
else
{
printf(" Element to be deleted : ");
top=top->link;
temp->link=NULL;
}
}

void traverse()
{
struct node* temp;
if(top==NULL)
printf(" No elements : ");
else
{
temp=top;
while(temp!=NULL)
{
printf(" %d",temp->data);
temp=temp->link;
}
}

}

int main()
{
int ch;


while(1)
{
printf(" 1.Push\n");
printf(" 2.Pop\n");
printf(" 3.Traverse\n");
printf(" 4.Exit\n");
printf(" Enter Input : ");
scanf("%d",&ch);
switch(ch)
{
case 1: push();
break;
case 2: pop();
break;
case 3: traverse();
break;

case 4: exit(1);
break;
}

}
}