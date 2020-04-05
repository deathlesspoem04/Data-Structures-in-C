## Trees Data Structures Assignment 02

### This readme file contains details about the implementaion of all the functions and prototypes and logic used in the program.
### It also includes the problems faced during the testing of the code.

#### Algorithm - Inorder Without Recursion
1. Initialize current as root 
2. While current is not NULL
   If the current does not have left child
      a) Print current’s data
      b) Go to the right, i.e., current = current->right
   Else
      a) Make current as the right child of the rightmost 
         node in current's left subtree
      b) Go to this left child, i.e., current = current->left

#### Algorithm - PreOrder Without Recursion
1. If left child is null, print the current node data. Move to right child.
```if (node->left == NULL) ```
2. Find inorder predecessor .
3. If the right child of inorder predecessor already points to this node.
4. If right child doesn't point to this node, then print this node and make right child point to this node.

#### Algorithm - PostOrder Without Recursion
We use a Boolean Variable to check if we have visited a node or not.
1. Visited left subtree 
    ```if (temp->left && temp->left->visited == false)```
        ```temp = temp->left; ```
  
2. Visited right subtree 
    ```else if (temp->right && temp->right->visited == false)``` 
        ```temp = temp->right;```
3. ```else { 
            printf("%d %d %s-> ", temp->rollNo,temp->marks,temp->name);
            temp->visited = true; 
            temp = head; 
        }```

#### Algorithm – Mirror(tree):

(1)  Call Mirror for left-subtree    i.e., Mirror(left-subtree)
(2)  Call Mirror for right-subtree  i.e., Mirror(right-subtree)
(3)  Swap left and right subtrees.
          temp = left-subtree
          left-subtree = right-subtree
          right-subtree = temp

