// Data Structures Assignment 3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 40
// Arrays of size of number of vertices for time.
int pre[5], post[5];

struct queue {
    int items[SIZE];
    int front;
    int rear;
};

struct queue* createQueue();
void enqueue(struct queue* q, int);
int dequeue(struct queue* q);
void display(struct queue* q);
int isEmpty(struct queue* q);
void printQueue(struct queue* q);
 
struct node
{
    int vertex;             // Roll No. (Unique Info , i.e , Vertex / Node)
    char name[20] = "";
    int marks = 0;
    struct node* next;
};

struct node* createNode(int v);

struct Graph
{
    int numVertices;
    int* visited;
    struct node** adjLists; // we need int** to store a two dimensional array. Similary, we need struct node** to store an array of Linked lists
};

struct Graph* createGraph(int);
void addEdge(struct Graph*, int, int);
void printGraph(struct Graph*);
void DFS(struct Graph*, int);
void BFS(struct Graph* graph, int startVertex);
void dfsTime(struct Graph* graph, int vertex);

int main()
{
    int n,ch;
    printf("Enter the number of Vertices you want :");
    scanf("%d", &n);

    struct Graph* graph = createGraph(n);
    while(1)
    {
        
        printf("Enter 1: Adding an edge in the graph \nEnter 2: Print the Existing Graph \nEnter 3: Perform DFS on a particular Roll No.\nEnter 4: Perform BFS on a particular Roll No.\nEnter 5: To get the Arrival & Dep. Time \nPress 6: Exit\nEnter Choice :");
        scanf("%d" ,&ch);
        switch(ch)
        {
            case 1: {
                    printf("Enter the values of Roll_1 and Roll_2 :");
                    int a, b;
                    scanf("%d", &a);
                    scanf("%d", &b);
                    addEdge(graph, a, b);
                    break;}

            case 2: {
                    printGraph(graph);
                    break;}
                    
            case 3 :{
                    printf("Enter the Roll No. to perform DFS: ");
                    int rno;
                    scanf("%d", &rno);
                    DFS(graph, rno);
                    break;}
                    
            case 4 :{ 
                    printf("Enter the Roll No. to perform BFS: ");
                    int rno;
                    scanf("%d", &rno);       
                    BFS(graph, rno);
                    break;}
            case 5 :{printf("Enter the Roll No. toGet Time on: ");
                    int rno;
                    scanf("%d", &rno);
                    dfsTime(graph, rno);
                    break;}
            case 6 :{
                    exit(1);
                    break;}
        }
    }
    return 0;
}

void DFS(struct Graph* graph, int vertex) {
        struct node* adjList = graph->adjLists[vertex];
        struct node* temp = adjList;
        
        graph->visited[vertex] = 1;
        printf("Visited %d \n", vertex);
    
        while(temp!=NULL) {
            int connectedVertex = temp->vertex;
        
            if(graph->visited[connectedVertex] == 0) {
                DFS(graph, connectedVertex);
            }
            temp = temp->next;
        }       
}

 
struct node* createNode(int v)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->vertex = v;
    if (newNode->marks != 0 && newNode->name != 0)
    {printf("Marks and Name:");
    scanf("%d",&newNode->marks);
    gets(newNode->name);}
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices)
{
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
 
    graph->adjLists = (struct node **)malloc(vertices * sizeof(struct node*));
    
    graph->visited = (int *)malloc(vertices * sizeof(int));
 
    int i;
    for (i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}
 
void addEdge(struct Graph* graph, int src, int dest)
{
    // Add edge from src to dest
    struct node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
    
    
    // Add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}
 
void printGraph(struct Graph* graph)
{
    int v;
    for (v = 0; v < graph->numVertices; v++)
    {
        struct node* temp = graph->adjLists[v];
        printf("\n Adjacency list of vertex %d\n ", v);
        while (temp)
        {
            printf("%d -> ", temp->vertex);
            printf("%s -> ", temp->name);
            printf("%d -> \t", temp->marks);
            temp = temp->next;
        }
        printf("\n");
    }
}


//

void BFS(struct Graph* graph, int startVertex) {

    struct queue* q = createQueue();
    
    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);
    
    while(!isEmpty(q)){
        printQueue(q);
        int currentVertex = dequeue(q);
        printf("Visited %d\n", currentVertex);
    
       struct node* temp = graph->adjLists[currentVertex];
    
       while(temp) {
            int adjVertex = temp->vertex;

            if(graph->visited[adjVertex] == 0){
                graph->visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
       }
    }
}

struct queue* createQueue() {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    return q;
}


int isEmpty(struct queue* q) {
    if(q->rear == -1) 
        return 1;
    else 
        return 0;
}

void enqueue(struct queue* q, int value){
    if(q->rear == SIZE-1)
        printf("\nQueue is Full!!");
    else {
        if(q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(struct queue* q){
    int item;
    if(isEmpty(q)){
        printf("Queue is empty");
        item = -1;
    }
    else{
        item = q->items[q->front];
        q->front++;
        if(q->front > q->rear){
            printf("Resetting queue");
            q->front = q->rear = -1;
        }
    }
    return item;
}

void printQueue(struct queue *q) {
    int i = q->front;

    if(isEmpty(q)) {
        printf("Queue is empty");
    } else {
        printf("\nQueue contains \n");
        for(i = q->front; i < q->rear + 1; i++) {
                printf("%d ", q->items[i]);
        }
    }    
}


int time = 1;
// Function for arrival and departure time
void dfsTime(struct Graph* graph, int vertex) {
        struct node* adjList = graph->adjLists[vertex];
        struct node* temp = adjList;
        
        pre[vertex] = time;
        time++;
        graph->visited[vertex] = 1;

        // Going into depth of graph with recurssion
        while(temp!=NULL) {
            int connectedVertex = temp->vertex;
        
            if(graph->visited[connectedVertex] == 0) {
                dfsTime(graph, connectedVertex);
            }
            temp = temp->next;
            post[vertex] = time;
            time++;
        }
        
}
