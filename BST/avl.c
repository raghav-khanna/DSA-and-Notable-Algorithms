#include<stdio.h>
#include<stdlib.h>

struct avlnode{
    int key;
    int bf;
    struct avlnode* right;
    struct avlnode* left;
};

struct avlnode *create(int key){
    struct avlnode *temp = NULL;
    temp = (struct avlnode *)malloc(sizeof(struct avlnode));
    temp->key = key;
    temp->left = NULL;
    temp->right = NULL;
    temp->bf = 0;
    return temp;
}

struct avlnode *rightRotate(struct avlnode* x){
    struct avlnode* y = x->left;
    struct avlnode* t = y->right;
    printf("Rotating %d to right\n",x->key);
    y->right = x;
    x->left = t;
    if(t != NULL){
        x->bf = abs(t->bf);
        y->bf -= 1; 

    }else{
        x->bf -= 2;
        y->bf -= 2;
    }    

    return y;
}

struct avlnode* leftRotate(struct avlnode* x){
    struct avlnode* y = x->right;
    struct avlnode* t = y->left;
    printf("Rotating %d to left\n",x->key);
    y->left = x;
    x->right = t;
    if(t != NULL){
        x->bf = 0 - abs(t->bf);
        y->bf += 1;
    }else{
        x->bf = 1;
        y->bf += 2;
    }
    // printf("HELLO\n");
    // printf("HELLO\n");

    return y;
}

struct avlnode* LL(struct avlnode *root){
    return rightRotate(root);
}

struct avlnode* RR(struct avlnode *root){
    return leftRotate(root);
}

struct avlnode* LR(struct avlnode *root){
    root->left = leftRotate(root->left);
    root = rightRotate(root);
    root->bf = 0;
    return root;
}

struct avlnode* RL(struct avlnode *root){
    root->right = rightRotate(root->right);
    root = leftRotate(root);
    printf("RL Rotation is done, returning new root \n");
    root->bf = 0;
    return root;
}

int isLeaf(struct avlnode *node){
    if(node == NULL) return 0;
    if(node->left == NULL && node->right == NULL)
        return 1;
    else 
        return 0;
}

void inOrder(struct avlnode *root){

    if(root!= NULL)
     {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
     }
}

struct avlnode* insertNode(struct avlnode *root, int key){
    if(root == NULL){
        root = create(key);
        return root;
    }
    if(key < root->key){
        root->left = insertNode(root->left,key);
        printf("Inserted %d to the left of %d \n",key,root->key);
        if(!(root->left->bf == 0 && !isLeaf(root->left)))
            root->bf += 1;
        printf("New balance factor of the node %d is %d \n",root->key,root->bf);
        if(root->bf == 2){
            if(key < root->left->key){
                root = LL(root);
            }else{
                printf("Performing the LR Rotation\n");
                root = LR(root);
                inOrder(root);
                printf("\n");
            }
        }
    }else if(key > root->key){
        root->right = insertNode(root->right,key);
        printf("Inserted %d to the right of %d \n",key,root->key);
        if(!(root->right->bf == 0 && !isLeaf(root->right)))
            root->bf -= 1;
        printf("New balance factor of the node %d is %d \n",root->key,root->bf);
        if(root->bf == -2){
            if(key < root->right->key){
                printf("Performing the RL Rotation\n");
                root = RL(root);
                inOrder(root);
                printf("\n");
                
            }else{
                root = RR(root);
            }
        }
    }
    return root;
}



int height(struct avlnode* root){

    if(root == NULL) return 0;

    int lHeight = height(root->left);
    int rHeight = height(root->right);

    return (lHeight>rHeight) ? lHeight + 1 : rHeight + 1;
}

void printCurrentLevel(struct avlnode *root, int level){
    if(root == NULL) return;
    if(level == 1)
    {
        printf("%d ", root->key);
        return;
    } 

    printCurrentLevel(root->left, level - 1);
    printCurrentLevel(root->right, level - 1);

}

void levelOrder(struct avlnode *root){
    int h = height(root);
    for(int i=1;i<=h;i++)
        printCurrentLevel(root, i);
}

int main(){
    struct avlnode* root = NULL;
    int ch;
    printf("Enter the Element[-1 for terminating] - ");
    scanf("%d", &ch);
    while(ch != -1){
        root = insertNode(root,ch);
        printf("\nEnter the Element[-1 for terminating] - ");
        scanf("%d", &ch);
    }
    printf("\n Level Order Traversal of the AVL Tree is - \n");
    inOrder(root);
    printf("\n");
    levelOrder(root);
    printf("\n");
    return 1;
}