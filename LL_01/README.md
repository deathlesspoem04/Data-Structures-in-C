## Data_Structures_LinkedList

### This readme file contains details about the implementaion of all the functions and prototypes and logic used in the program.
### It also includes the problems faced during the testing of the code.

#### The HeaderFiles :

```
#include <stdio.h>
#include <stdlib.h>
```
stdio gives the essential features for performing standard input/output operations.
stdlib gives more features for performing tasks like dynamic memory allocation using ```malloc()``` 

#### The Function prototypes :
```
void appendNode(void);
void prependNode(void);
void allocateNode(void);
void insertNode(void);
.
.
void reverseList(void);
void printLtoM(void);
```
Function prototype tells compiler about number of parameters function takes, data-types of parameters and return type of function. By using this information, compiler cross checks function parameters and their data-type with function definition and function call.

#### Defining the structure :
```
struct Student 
{
    int rollNo;
    char name[50];
    double marks;
    struct Student *next;
};
```
We named the structure Student and it contain four feilds , three of which are data feilds and one is the structure pointer type, which will be used to point the structure while implementing the functions.

#### 1) allocateNode()

This function creates a temp structure pointer and dynamically allocates memory to a Student type structure and then points it to the end of the list using ```if-else``` statement.

#### 2) prependNode()

This function adds the node to the starting of the list by connecting the root varoiable to it and pointing it to the previous 1st element.
For this we use ```if-else``` statement.

#### 3) appendNode()

This function adds the node to the end of the list using the same logic as the last one.

#### 4) insertNode()

This functions insert a new node after a particular ID node given by the user.
For this we use two structure pointer type variables.
```struct node *temp , *p;```
Firstly we take the input from the user at what location does he want to insert the node , and then we check if that is a valid loaction (i.e, less than or equal to the length of the list).
If its a valid loaction then we make a pointer variable point to a node just before the loaction and then the memory is dynamically allocated to the other node pointer and then the previous pointer is pointed to the newly allocated node and the new node is pointed to the further node.
```
temp -> next = NULL;
temp -> next = p-> next;
p-> next = temp ;
```
In this way we can insert the node in between of a list.

#### 5) length()

This function returns the length of the Linked List.
We use a count variable and a while loop , which counts each time ```temp->next!=NULL``` (i.e, until it reaches the end of the list from the root).
This method was used in the previous function insertNode() while comparing the length of the list with the location entered by the user.

#### 6) searchList()

This function returns the correct Node of the ID asked.
We use the while loop for reaching to the node in which ```temp->rollNo == id``` (which was provided by the user).
```
while (temp->rollNo != id)
{
   temp = temp->next;
}
```
And then we return the node address.
```return temp->next;```

#### 7) printNode()

This function prints the data of a particular Node.
It uses the same logic as searchList for finding the node which matches the ID, but instead of returning the node pointer it prints the node data (i.e, Name , rollNo , Marks)

#### 8) printList()

This Function prints the complete List.
It uses while loop and keeps printing the data of each node till the end of the list is reached.

#### 9) deleteB()

This function deletes the node from the beginning of the list(i.e, the first node)
Also checks if the list is empty (if it is gives an error message)
```
if (root = NULL)
{
   printf("The list is empty \n");
}
```
We points the root to the second node and free the first node , thus deleting the link from the list.
```
temp = root;
root = temp->next;
temp->next = NULL;
free(temp);
```

#### 10) deleteE()

In this function we delete the node from the ending(i.e, the last node)
The logic is that we create two struct pointer type variable 
```
while(temp->next != NULL)
    {
        temp = p;
        temp = temp->next;
    }
    p->next = NULL;
```
The first node pointer variable goes from first to last node in the list.
And the second node pointer variable keeps pointing to the previous node of the first pointer, as soon as the first pointer reaches the last node , the while loop breaks and then the second pointer points the last second node and makes it point to NULL , removing the link between the last node and the list and then we free both the pointer variables.
```
free(p);
free(temp);
```

#### 11) deleteAP()

This function deletes a particular node from a specified location entered by the user.
In this function we uses ```if-else``` statement , with the first comaprison been between the location entered by the user and the length of list using the length() method described earlier.
The second statement compares if the location is one , if-true then we put the logic used in deleteB() (i.e, deleting the last node from the list).
Now if the loaction entered by the user is in middle of the list somewhere , we will create two additional struct pointer type variables apart from the temp struct pointer type varialbe.
The logic used it that one pointer will point at the previous node before the location entered in the list and the second pointer will point at the node just after the location and then the previous pointer will point at the second pointer popping out the node from the middle , hereby deleting the node from that particular location. We will use an interger variable to keep check on the location if the pointer.
```
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
```

#### 12) reverseList()

This function is used to reverse the nodes in place(i.e, reversing the linked list).
The logic used in this function used is that we create two struct type pointer, and points each one of them at the extreme (i.e, start and the end of the list), and we swap each of the node from last and first , and we keep increasing an integer variable to keep check on the length and as soon as both the pointer comes at the middle of the list the while loop terminates and what we get is a reverse list.
```
while(i<j)
    {
        k=0;
        while(k<j)
        {
            q = q->next;
            k++;
        }
        temp1 = p ->marks;                    // Swapping of Marks
        p->marks = q->marks;
        q->marks = temp1;

        temp = p ->rollNo;                    // Swapping of RollNo
        p->rollNo = q->rollNo;
        q->rollNo = temp;

        temp2 = p ->name;                     // Swapping of Name
        p->name = q->name;
        q->name = temp2;

        i++;
        j--;
        p = p->next;
        q = root;
    }
 ```

#### 13) printLtoM()

This functions prints the last M number of nodes.
We use struct pointer type variable to reach the M th node and the we exit the loop and in the next loop we print the rest of the data till the end of the node.
If m = 0 , we print the last node using the if-else statement.

### 14) main() Implementation

In this we implement the linked list and we have craeted the switch case and we have a while loop with an option to exit it in a case.



## Errors and Difficulty Faced during the Testing of the Code

While implementing the code I faced several errors such as :

##### 1) Mismatching of the return type specifier
##### 2) Error during returning struct pointer type variable
##### 3) Copying the string while swapping it in the reverseList() method

All this was solved by debugging tools and help from my batchmates and searching the solution over the internet.