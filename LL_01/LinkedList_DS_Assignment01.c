#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void appendNode(void);
void prependNode(void);
struct Student* allocateNode(void);
void insertNode(void);
int length(void);
struct Student* searchList(void);
void printNode(void);
void printList(void);
void deleteB(void);
void deleteE(void);
void deleteAP(void);
void reverseList(void);
void printLtoM(void);

struct Student 
{
    int rollNo;
    char name[50];
    double marks;
    struct Student *next;
};

struct Student *root = NULL ;

int main ()
{
    int ch;
    while(1)
    {
      
        printf("Options : \n");
        printf("Press 1 to Allocate Node \n");
        printf("Press 2 to Prepend Node \n");
        printf("Press 3 to Append Node \n");
        printf("Press 4 to Insert Node After \n");
        printf("Press 5 to Search Node by ID \n");
        printf("Press 6 to Print Node by ID \n");
        printf("Press 7 to Print List \n");
        printf("Press 8 to Delete First Node \n");
        printf("Press 9 to Delete Last Node \n");
        printf("Press 10 to Delete a particular Node \n");
        printf("Press 11 to Reverse List \n");
        printf("Press 12 to Print the last Mth nodes \n");
        printf("Press 13 to Exit \n");

        scanf("%d",&ch);
        
        switch (ch)
        {
        
        case 1: {struct Student * p = allocateNode();
        printf("Node Allocated Successfully");
        break;}
        case 2: prependNode();
        break;
        case 3: appendNode();
        break;
        case 4: insertNode();
        break;
        case 5:{ struct Student * q = searchList();
        printf("Node Found \n");
        break;}
        case 6: printNode();
        break;
        case 7: printList();
        break;
        case 8: deleteB();
        break;
        case 9: deleteE();
        break;
        case 10: deleteAP();
        break;
        case 11: reverseList();
        break;
        case 12: printLtoM();
        break;
        case 13: exit(1);
        break;

        }
    }
    return 0;
}

struct Student* allocateNode()                            //This function allocates a new node to the Structure.
{
    struct Student *temp;
    temp = (struct Student *)malloc (sizeof(struct Student));
    temp -> next = NULL;

    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        struct Student *p;
        p = root;
        while (p->next!=NULL)
        {
            p = p->next;
        }
        p->next = temp;   
    }
    return temp;
}

void appendNode()                              //This functions add a node to the end of the list.
{
    struct Student *temp;
    temp = (struct Student *)malloc (sizeof(struct Student));
    printf("Enter Roll Number : \n");
    scanf("%d", & temp ->rollNo);
    printf("Enter Name : \n");
    scanf("%[^\n]%*c", temp->name); 
    printf("Enter Marks : \n");
    scanf("%lf", & temp ->marks);
    temp -> next = NULL;

    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        struct Student *p;
        p = root;
        while (p->next!=NULL)
        {
            p = p->next;
        }
        p->next = temp;   
    }
}

void prependNode()                           //This functions add a node to the beginning of the list.
{
    struct Student *temp;
    temp = (struct Student*)malloc(sizeof(struct Student));
    printf("Enter Roll Number : \n");
    scanf("%d", & temp ->rollNo);
    printf("Enter Name : \n");
    scanf("%[^\n]%*c", temp->name);
    printf("Enter Marks : \n");
    scanf("%lf", & temp ->marks);
    temp -> next = NULL;
    
    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        temp -> next = root ;
        root = temp;
    }
}

void insertNode()                    //This functions insert a new node after a particular ID node given by the user.
{
    struct Student *temp , *p;
    int loc , len , i=1;
    printf("Enter Location : \n");
    scanf("%d",&loc);
    len = length();
        p = root;
    if (loc > len)
    {
        printf("Invalid Location \n");
        printf("Currently list is having %d nodes \n",len);
    }
    else
    {
    
        while (i<loc)
        {
            p = (struct Student*)p->next ;
            i++;
        }
    temp = (struct Student*)malloc(sizeof(struct Student));
    printf("Enter Roll Number : \n");
    scanf("%d", & temp ->rollNo);
    printf("Enter Name : \n");
    scanf("%[^\n]%*c", temp->name);
    printf("Enter Marks : \n");
    scanf("%lf", & temp ->marks);
    temp -> next = NULL;
    temp -> next = p-> next;
    p-> next = temp ;
    }
    
}

int length()                                          // This function returns the length of the Linked List when called. 
{
    int count = 0;
    struct Student *temp ;
    temp = root;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

struct Student * searchList()                                    // This function returns the correct Node of the ID asked. 
{
    int id;
    struct Student *temp;
    temp = root;
    printf("Enter the ID Number : \n");
    scanf("%d", &id);
    while (temp->rollNo != id)
    {
        temp = temp->next;
    }
    return temp->next;
}

void printNode()                                                // This function prints the data of a particular Node.
{
    int id;
    struct Student *temp;
    temp = root;
    printf("Enter the ID Number : \n");
    scanf("%d", &id);
    while (temp->rollNo != id)
    {
        temp = temp->next;
    }

    printf("Roll Number : %d \n", temp ->rollNo);
    printf("Name : %s \n", temp->name);
    printf("Marks : %lf \n", temp->marks);

}

void printList()                                                // This Function prints the complete List.
{
    struct Student *temp;
    temp = root;
    while (temp->next != NULL)
    {
        temp = temp->next;
        printf("Roll Number : %d \n", temp ->rollNo);
        printf("Name : %s \n", temp->name);
        printf("Marks : %lf \n", temp->marks);
    }
}

void deleteB()                                                  // This Function delete the node from the beginning.
{
    if (root == NULL)
    {
        printf("The list is empty \n");
    }
    else
    {
    struct Student *temp;
    temp = root;
    root = temp->next;
    temp->next = NULL;
    free(temp);
    printf("First Node Deleted \n");
    }
}

void deleteE()                                                 // This Function delete the node from the end.
{
    if (root == NULL)
    {
        printf("The list is empty \n");
    }
    else
    {
    struct Student *temp,*p;
    temp = root;
    while(temp->next != NULL)
    {
        temp = p;
        temp = temp->next;
    }
    p->next = NULL;
    free(p);
    free(temp);
    printf("Last Node Deleted \n");
    }
}

void deleteAP()                                                 // This Function delete the node at a specific location provided.
{
    struct Student *temp;
    int loc;
    int len = length();
    printf("Enter location to delete: \n");
    scanf("%d", &loc);
    if (loc > len)
    {
        printf("Invalid Location \n");
    }
    else if(loc == 1)
    {
        temp = root;
        root = temp->next;
        temp->next = NULL;
        free(temp);
    }
    else
    {
        int i = 1;
        struct Student *p = root , *q;
        while (i < loc-1)
        {
            p = p->next;
            i++;
        }
        q = p->next;
        p->next = q->next;
        q->next = NULL;
        free(q);
    }
    printf("Node at location %d deleted \n",loc);
}

void reverseList()                                             // This function reverse the complete List.
{
    struct Student *p,*q;
    int i,j,k,len;
    int temp;
    double temp1;
    char temp2[100];
    len = length();
    i=0;
    j=len-1;
    p=root;
    q=root;
    while(i<j)
    {
        k=0;
        while(k<j)
        {
            q = q->next;
            k++;
        }
        temp1 = p ->marks;
        p->marks = q->marks;
        q->marks = temp1;

        temp = p ->rollNo;
        p->rollNo = q->rollNo;
        q->rollNo = temp;

        strcpy(temp2,p ->name);
        strcpy(p->name,q->name);
        strcpy(q->name,temp2);

        i++;
        j--;
        p = p->next;
        q = root;
    }
    printf("List Reversed");
}

void printLtoM()                                                     // This Function prints the last M nodes in the list.
{
    struct Student *temp;
    temp = root;
    int m,len;
    len = length();
    printf("Enter the value of M : \n");
    scanf("%d", &m);
    if (m > len)
    {
        printf("Invalid Input \n");
    }
    else if(m == 0)
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        printf("Roll Number : %d \n", temp ->rollNo);
        printf("Name : %s \n", temp->name);
        printf("Marks : %lf \n", temp->marks);
    }
    else
    {
        int l = len - m;
        int flag = 0;
        while (flag != l)
        {
            flag++;
            temp = temp->next;
        }
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        printf("Roll Number : %d \n", temp ->rollNo);
        printf("Name : %s \n", temp->name);
        printf("Marks : %lf \n", temp->marks);
    }
    
}