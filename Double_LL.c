struct node 
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

void append()
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter Node data: \n");
    scanf("%d\n",temp->data);
    temp->left = NULL;
    temp->right= NULL;
    if (root == NULL)
        root = temp;
    else
    {
        struct node *p;
        p = root;
        while(p->right!=NULL)
            p = p->right;
        p->right = temp;
        temp->right=p;
    }
    
}

void addatBegin()
{
    struct node * temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter Node data: \n");
    scanf("%d\n",temp->data);
    temp->left = NULL;
    temp->right= NULL;
    if (root == NULL)
        root = temp;
    else
    {
        temp->right = root;                    //(right connection linking)
        temp->left  = temp;                    //(right connection deletion)
        root = temp;                           //(left connection linking)
    }
}

int length()
{
    struct node* temp;
    temp = root;
    int count = 0;
    while (temp!=NULL)
    {
        count++;
        temp = temp->right;
    }
    return count;
}

void display()
{
    struct node * temp;
    temp = root;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp = temp ->right;
    }
}

void addatafter()
{
    int loc, len , i = 1;
    struct node *temp,*p;
    printf("Enter Location to Add : \n");
    scanf("%d\n",&loc);
    len = length();
    if(loc>len)
    {
        printf("Invalid Location \n");
        printf("List contains %d nodes \n",len);
    }
    else
    {
        printf("Enter data : \n");
        temp = (struct node*)malloc(sizeof(struct node));
        scanf("%d\n",temp->data);
        temp->left = NULL;
        temp->right= NULL;
        p = root;
        while(i<loc)
        {
            p = p->right;
            i++;
        }
        temp->right = p->right;
        p->right->left = temp;
        temp ->left = p;
        p ->right =temp;
    }
    
}