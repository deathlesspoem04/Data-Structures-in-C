#include <stdio.h>
#include <stdlib.h>

void insertNode(void);
int length(void);
struct node * SearchList(void);
void PrintList(void);

struct node
{
    int data = 0 ;
    struct node * link = NULL;
};

struct node *root = NULL;

void insertNode()                  
{
    struct node *temp , *p;
    int loc , len , i=1;
    printf("Enter Location : \n");
    scanf("%d",&loc);
    len = length();
        p = root;
    if (loc == 0)
    {
        temp = (struct node*)malloc(sizeof(struct node));
        printf("Enter Data : \n");
        scanf("%d \n", & temp ->data);
        root = temp;
        temp->link = NULL;
    }
    else if (loc > len)
    {
        printf("Invalid Location \n");
        printf("Currently list is having %d nodes \n",len);
    }
    else
    {
        while (i<loc)
        {
            p = (struct node*)p->link ;
            i++;
        }
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter Data : \n");
    scanf("%d \n", & temp ->data);
    temp -> link = NULL;
    temp -> link = p-> link;
    p-> link = temp ;
    }
    
}


int length()                                          
{
    int count = 0;
    struct node *temp ;
    temp = root;
    while (temp != NULL)
    {
        count++;
        temp = temp->link;
    }
    return count;
}

struct node * SearchList()
{
    int id,count=0,flag=0;
    int len = length();
    printf("Enter Data to be searched :\n");
    scanf("%d \n",&id);
    struct node *temp,*r;
    r = NULL;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->link = root;
    for (int i =0 ;i< len; i++)
    {
        count++;
        if(temp->data == id)
        {
            r=temp;
        }
        if(flag!=0)
        {
            count--;
        }
        temp = temp->link;
    }
    if(flag!=0)
    {
        printf("ID matched with node at %d in the list\n",count);
    }
    else
    {
        printf("ID Not matched\n");
    }
    
    return r;
}

void PrintList()
{
    struct node *temp;
    int len;
    len = length();
    temp = (struct node*)malloc(sizeof(struct node));
    temp->link = root;
    for(int i = 0; i< len ;i++)
    {
        printf("%d\n",temp->data);
        temp = temp->link;
    }
}

int main()
{
    int ch;
    while(1)
    {
        printf("Enter Choice :\n");
        printf("1.Insert Node\n");
        printf("2.Search List\n");
        printf("3.Print List\n");
        printf("4.Exit\n");
        scanf("%d \n",&ch);
        switch(ch)
        {
            case 1:{
                insertNode();
            break;}
            case 2:{
                struct node *p = SearchList();
            break;}
            case 3:{
                PrintList();
            break;}
            case 4:{
                exit(1);
            break;}
            default: exit(1);
        }
    }
    return 0;
}