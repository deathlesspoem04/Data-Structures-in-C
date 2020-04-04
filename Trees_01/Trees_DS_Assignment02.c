// Trees Data Structures Assignment 02

#include<stdio.h>
#include<stdlib.h>
#include <string.h>

void creation(void);
void insertion(void);
void search(struct Student*);
void inOrder(struct Student*);
void inOrder_wr(struct Student *);
void preOrder(struct Student*);
void preOrder_wr(struct Student*);
void postOrder(struct Student*);
void postOrder_wr(struct Student*);
void NthInorder(struct Student*, int);
void NthPostorder(struct Student*, int);
void mirror(struct Student*);

struct Student
{
    int rollNo;
    char name[20];
    int marks;
    struct Student* left;
    struct Student* right;
    bool visited; 
};
struct Student *root = NULL ;
struct Student *temp = NULL ;

int main()
{
    int choice;
    while(1)
    {
        printf("\nPress 1 : Insertion \nPress 2 : Inorder\nPress 3 : Inorder(Without Recursion) \nPress 4 : PreOrder\nPress 5 : PreOrder(Without Recursion) \nPress 6 : PostOrder\nPress 7 : PostOrder(Without Recursion) \nPress 8 : nth Node of InOrder\nPress 9 : nth Node of PostOrder\nPress 10 : Mirror Tree \nAny onther Number to Exit \n");
        printf("\nEnter Choice : ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            {
                insertion();
                break;
            }
            case 2:
            {
                inOrder(root);
                break;
            }
            case 3:
            {
                inOrder_wr(root);
                break;
            }
            case 4:
            {
                preOrder(root);
                break;
            }
            case 5:
            {
                preOrder_wr(root);
                break;
            }
            case 6:
            {
                postOrder(root);
                break;
            }
            case 7:
            {
                postOrder_wr(root);
                break;
            }
            case 8:
            {
                int n;
                printf("Enter value of n: ");
                scanf("%d", &n);
                NthInorder(root, n);
                break;
            }
            case 9:
            {
                int n;
                printf("Enter value of n: ");
                scanf("%d", &n);
                NthPostorder(root, n); 
                break;
            }
            case 10:
            {
                mirror(root);
                inOrder(root);                         // Printing InOrder after Mirroring the Tree
                break;
            }
            default: exit(1);
        }
    }
    return 0;
}

void insertion()
{
    creation();
    if(root==NULL)
        root=temp;
    else
        search(root);
}

void creation()
{
    int marks , rollNo;
    char name[50];
    printf("Insert data for New Element :\nRollNo : ");
    scanf("%d",&rollNo);
    printf("Marks and Name:");
    scanf("%d",&marks);
    gets(name);
    temp = (struct Student*)malloc(sizeof(struct Student));
    temp->rollNo=rollNo;
    temp->marks=marks;
    strcpy(temp->name, name);
    temp->left=NULL;
    temp->right=NULL;
    temp->visited = false;
}

void search( struct Student *node)
{
    if((temp->rollNo > node->rollNo) && (node->right != NULL))
        search(node->right);
    else if((temp->rollNo > node->rollNo)&&(node->right==NULL))
        node->right=temp;
        else if ((temp->rollNo < node->rollNo) && (node->left != NULL))    /* value less than root node value insert at left */
        search(node->left);
    else if ((temp->rollNo < node->rollNo) && (node->left == NULL))
        node->left = temp;
}

void inOrder(struct Student *node)
{
    if (root == NULL)
    {
        printf("\nNo Nodes Found\n");
        return;
    }
    if (node->left != NULL)
        inOrder(node->left);
    printf("%d %d %s -> ", node->rollNo, node->marks, node->name);
    if (node->right != NULL)
        inOrder(node->right);
}

void inOrder_wr(struct Student *node)
{ 
    struct Student *current, *pre; 
    printf("InOrder Without Recursion :\n");
    if (node == NULL) 
        return; 
  
    current = node; 
    while (current != NULL) { 
  
        if (current->left == NULL) { 
            printf("%d %d %s ->", current->rollNo,current->marks,current->name); 
            current = current->right; 
        } 
        else { 
  
            /* Find the inorder predecessor of current */
            pre = current->left; 
            while (pre->right != NULL && pre->right != current) 
                pre = pre->right; 
  
            /* Make current as the right child of its inorder  
               predecessor */
            if (pre->right == NULL) { 
                pre->right = current; 
                current = current->left; 
            } 
  
            /* Revert the changes made in the 'if' part to restore  
               the original tree i.e., fix the right child 
               of predecessor */
            else { 
                pre->right = NULL; 
                printf("%d %d %s ->", current->rollNo,current->marks,current->name);
                current = current->right; 
            }
        }
    } 
} 

void preOrder(struct Student *t)
{
    if (root == NULL)
    {
        printf("\nNo Nodes Found\n");
        return;
    }
    printf("%d %d %s -> ", t->rollNo,t->marks,t->name);
    if (t->left != NULL)
        preOrder(t->left);
    if (t->right != NULL)
        preOrder(t->right);
}

void preOrder_wr(struct Student *node)
{ 
    printf("PreOrder Without Recursion :\n");
    while (node) 
    { 
        // If left child is null, print the current node data. Move to 
        // right child. 
        if (node->left == NULL) 
        { 
            printf("%d %d %s ->", node->rollNo,node->marks,node->name);
            node = node->right; 
        } 
        else
        { 
            // Find inorder predecessor 
            struct Student* current = node->left; 
            while (current->right && current->right != node) 
                current = current->right; 
  
            // If the right child of inorder predecessor already points to 
            // this node 
            if (current->right == node) 
            { 
                current->right = NULL; 
                node = node->right; 
            } 
  
            // If right child doesn't point to this node, then print this 
            // node and make right child point to this node 
            else
            { 
                printf("%d %d %s ->", node->rollNo,node->marks,node->name);
                current->right = node; 
                node = node->left; 
            } 
        } 
    } 
} 

void postOrder(struct Student *t)
{
    if (root == NULL)
    {
        printf("No elements in a tree to display ");
        return;
    }
    if (t->left != NULL)
        postOrder(t->left);
    if (t->right != NULL)
        postOrder(t->right);
    printf("%d %d %s-> ", t->rollNo,t->marks,t->name);
}

void postOrder_wr(struct Student* head)
{ 
    printf("PostOrder Without Recursion :\n");
    struct Student* temp = head; 
    while (temp && temp->visited == false) { 
  
        // Visited left subtree 
        if (temp->left && temp->left->visited == false) 
            temp = temp->left; 
  
        // Visited right subtree 
        else if (temp->right && temp->right->visited == false) 
            temp = temp->right; 
  
        // Print node 
        else { 
            printf("%d %d %s-> ", temp->rollNo,temp->marks,temp->name);
            temp->visited = true; 
            temp = head; 
        } 
    } 
} 

void NthInorder(struct Student* node, int n) 
{ 
    static int count = 0; 
    if (node == NULL) 
        return; 
  
    if (count <= n) { 
        NthInorder(node->left, n);                                              /* first recur on left child */
        count++; 
  
        if (count == n)                                                         /* when count = n then print element*/
            printf("Nth in InOrder : %d %d %s", node->rollNo,node->marks,node->name);
        NthInorder(node->right, n);                                             /* now recur on right child */
    } 
} 

void NthPostorder(struct Student* node, int N) 
{ 
    static int flag = 0; 
  
    if (node == NULL) 
        return; 
  
    if (flag <= N) { 
        NthPostorder(node->left, N);                              // left recursion
        NthPostorder(node->right, N);                             // right recursion
        flag++;  
        if (flag == N)                                            // prints the n-th node of preorder traversal
            printf("Nth in PostOrder : %d %d %s", node->rollNo,node->marks,node->name);
    } 
}

void mirror(struct Student* node)  
{ 
  if (node==NULL)  
    return;   
  else 
  { 
    struct Student* temp; 
      
    mirror(node->left);             /* do the subtrees */
    mirror(node->right); 
  
    temp        = node->left;       /* swap the pointers in this node */
    node->left  = node->right; 
    node->right = temp; 
  }

}