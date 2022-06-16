#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct treenode
{
    int data;
    int height;
    struct treenode *left;
    struct treenode *right;
};

struct treenode *insert(struct treenode *root, int data);

int maxNum(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

int height(struct treenode* node)
{
    if (node == NULL)
        return 0;
    else {
        int lDepth = height(node->left);
        int rDepth = height(node->right);
 
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

int getbalance(struct treenode *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return (height(n->left) - height(n->right));
}

struct treenode *search(struct treenode *ptr, int data)
{
    if(ptr != NULL)
    {
        if(data < ptr->data)
        {
            ptr = search(ptr->left, data);
        }
        else if(data > ptr->data)
        {
            ptr = search(ptr->right, data);
        }
    }
    return (ptr);
}

void inorder(struct treenode *ptr)
{
    if (ptr != NULL)
    {
        inorder(ptr->left);
        printf("%d ", ptr->data);
        inorder(ptr->right);
    }
}

struct treenode *singleRightRotation(struct treenode *root)
{
    struct treenode *y = root->left;
    struct treenode *t2 = y->right;
    y->right = root;
    root->left = t2;

    root->height = maxNum(height(root->left), height(root->right)) + 1;
    y->height = maxNum(height(y->left), height(y->right)) + 1;
    return y;
}

struct treenode *singleleftRotation(struct treenode *root)
{
    struct treenode *y = root->right;
    struct treenode *t2 = y->left;
    y->left = root;
    root->right = t2;

    root->height = maxNum(height(root->left), height(root->right)) + 1;
    y->height = maxNum(height(y->left), height(y->right)) + 1;
    return y;
}

struct treenode *insert(struct treenode *root, int data)
{
    if (root == NULL)
    {
        struct treenode *root = (struct treenode *)malloc(sizeof(struct treenode));
        root->data = data;
        root->left = root->right = NULL;
        root->height = 1;
    }
    else
    {
        if (data < root->data)
        {
            root->left = insert(root->left, data);
        }
        else
        {
            root->right = insert(root->right, data);
        }
    }
    root->height = maxNum(height(root->left), height(root->right)) + 1;
    int balancedFac = getbalance(root);

    if (balancedFac > 1)
    {
        if (data < root->left->data)
        {
            return singleRightRotation(root);
        }
        else
        {
            root->left = singleleftRotation(root->left);
            return singleRightRotation(root);
        }
    }
    else if (balancedFac < -1)
    {
        if (data > root->right->data)
        {
            return singleleftRotation(root);
        }
        else
        {
            root->right = singleRightRotation(root->right);
            return singleleftRotation(root);
        }
    }
    return root;
}

int main()
{
    int data;
    int option;
    struct treenode *root = (struct treenode *)malloc(sizeof(struct treenode));
    root = NULL;
    while (1)
    {
        printf("1.Insert\n");
        printf("2.Display\n");
        printf("3.Quit\n");
        printf("Enter your option : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Enter the value to be inserted : ");
            scanf("%d", &data);
            if (search(root, data) == NULL)
                root = insert(root, data);
            else
                printf("Duplicate value ignored\n");
            break;

        case 2:
            if (root == NULL)
            {
                printf("Tree is empty\n");
                continue;
            }
            printf("Inorder Traversal is : ");
            inorder(root);
            printf("\n");
            break;

        case 3:
            exit(1);
        default:
            printf("Wrong option\n");
        }
    }
}