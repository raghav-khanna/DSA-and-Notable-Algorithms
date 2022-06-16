#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node * left;
    int data;
    struct node* right;
};

struct queue{
    struct node *front;
    struct node *rear;

};

struct node* create()
{
	struct node* p;
	int val;
	printf("Enter val(-1 for terminate):");
	scanf("%d",&val);
	if(val==-1)
	  return NULL;
	p=(struct node *)malloc(sizeof(struct node ));
	p->data=val;
	printf("Enter left child of %d:\n",val);
	p->left=create();
 	printf("Enter right child of %d:\n",val);
	p->right=create();
	return p;
}

void preOrder(struct node *root){
    if(root == NULL) return ;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(struct node *root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    printf("%d ",root->data);
    // if(root->right == NULL) return;
    inOrder(root->right);
}

void postOrder(struct node *root){
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ",root->data);
}

int isSkew(struct node *root){
    static int flag = 0;
    if(root->left != NULL) {
        if(root->right != NULL)
             flag = 1;
        isSkew(root->left);
    }else if(root->right != NULL) {
        if(root->left != NULL) 
            flag = 1;
        isSkew(root->right);
    }
    return (flag==1?0:1);
}

// int flag = 1;

int check(struct node *root){
    //Question 2
    static int flag = 1;
    int left,right;
    
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return root->data;
    
    
    left = check(root->left);
    right = check(root->right);
    
    if(left + right != root->data) flag = 0;
    // return root->data;
    return (!flag?-1:root->data);
}

//Question - 2 From GFG

/* returns 1 if children sum property holds 
for the given node and both of its children*/
int isSumProperty(struct node* node)
{
    /* left_data is left child data and
       right_data is for right child data*/
    int left_data = 0, right_data = 0;
      
    /* If node is NULL or it's a leaf node 
    then return true */
    if(node == NULL ||
        (node->left == NULL && 
         node->right == NULL))
        return 1;
    else
    {
        /* If left child is not present then 0 
        is used as data of left child */
        if(node->left != NULL)
        left_data = node->left->data;
      
        /* If right child is not present then 0 
        is used as data of right child */
        if(node->right != NULL)
        right_data = node->right->data;
      
        /* if the node and both of its children 
        satisfy the property return 1 else 0*/
        if((node->data == left_data + right_data)&&
            isSumProperty(node->left) &&
            isSumProperty(node->right))
        return 1;
        else
        return 0;
    }
}

int node(struct node *root){
    
    if(root == NULL) return 0;
    return node(root->left) + 1 + node(root->right);
}

int isFull(int nodes){
    if(!((nodes-1)%2)) return 1;
    else return 0;
}

int height(struct node* root){

    if(root == NULL) return 0;

    int lHeight = height(root->left);
    int rHeight = height(root->right);

    return (lHeight>rHeight) ? lHeight + 1 : rHeight + 1;
}

void printCurrentLevel(struct node *root, int level){
    if(level == 1)
    {
        printf("%d ", root->data);
        return;
    } 

    printCurrentLevel(root->left, level - 1);
    printCurrentLevel(root->right, level - 1);

}

void printLevelOrder(struct node *root){
    int h = height(root);
    for(int i=1;i<=h;i++)
        printCurrentLevel(root, i);
}

void levelOrderTraversal(struct node* root){
    printLevelOrder(root);
}

void levelOrderTraversalQueue(struct node *root){


}

void invertBT(struct node *root){
    if(root->left == NULL && root->right == NULL) return;
    
    invertBT(root->left);
    
    invertBT(root->right);
    struct node *temp;
    temp = root->left;
    root->left = root->right;
    root->right = temp;
}

int main(){
    struct node * root;
    root = create();
    //Preorder Traversal
    // preOrder(root);

    //In-Order Traversal
    inOrder(root);
     
     //Question - 1
    // isSkew(root) ? printf("The tree is Skew ") : printf("The Tree is not Skew ");
    
    //Question - 2
    // check(root);
    // flag ? printf("Property Satisfied ") :printf("Property not satisfied ");

    // check(root) != -1 ? printf("Property Satisfied ") :printf("Property not satisfied ");

    //Question - 2 [From GFG]
    // isSumProperty(root) ? printf("Property Satisfied ") :printf("Property not satisfied ");

    //Question - 3
    // int nodes = node(root);
    // isFull(nodes) ? printf("Tree is Full") : printf("Tree is not full");

    //Question - 4
    //Level Order Traversal [BFS]

    printf("\n");
    levelOrderTraversal(root);

    printf("\n Inverted Binary Tree is -> \n");
    invertBT(root);
    levelOrderTraversal(root);
    //Post-Order Traversal
    // postOrder(root);
    
    return 0;
}