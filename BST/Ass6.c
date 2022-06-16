#include <stdio.h>
#include <stdlib.h>
struct treenode
{
   int key;              
   struct treenode *left;  
   struct treenode *right; 
};

struct treenode* create_treenode(int key)
{
    struct treenode *temp;
    
    temp= (struct treenode*)malloc(sizeof(struct treenode));  
    // 12 bytes block will be allocated
    
    temp->key = key;
    temp->left = NULL;
    temp->right= NULL;
    return temp;
}

void insert_bst(struct treenode *root, int key)
{
   struct treenode *newnode, *p,*q;

   newnode =  create_treenode(key);
   if(root == NULL)
     root = newnode;
   else
     {
          p = q = root;
          while(p!= NULL)
           {
               q = p;
               if(p->key<key)
                 p = p->right;
               else
                 p = p->left;
           }
          if(q->key>key)
               q->left = newnode;
          else
               q->right= newnode;
      }
}// end of insert tree function

struct treenode *search(struct treenode *root, int key)
{
   
     if(root== NULL)
          return root;
     
     if(root->key == key)
         return root;
     
     if(key<root->key)
        return search(root->left,key);
     else
        return search(root->right,key);
}

//Question - 1 -> Returns the Parent of the Key
struct treenode *searchParent(struct treenode *root, int key)
{
   
     if(root == NULL)
          return root;
     
     if(root->left->key == key || root->right->key == key)
         return root;
     
     if(key < root->key)
        return searchParent(root->left,key);
     else
        return searchParent(root->right,key);
}


void inorder_binarytree(struct treenode *root)
{
    if(root!= NULL)
     {
        inorder_binarytree(root->left);
        printf("%d ", root->key);
        inorder_binarytree(root->right);
     }
}

void q1(struct treenode *root){
      struct treenode *temp;
      int key;
      printf("\n Enter the key to search [This returns the Parent Node] (-1 to Terminate): ");
      scanf("%d", &key);
        if(key<0)
            return;
        if(key == root->key){
            printf("Has no Parent as it is the root node \n");
        }else{
            temp = searchParent(root,key);
            if(temp == NULL)
                printf("\n Key does not exist");
            else
                printf("\n Key exists. It's Parent Node is %d ", temp->key);
        }

}

int inorderSuccessor(struct treenode *temp){
    if(temp == NULL){
        // printf("No Inorder Successor!\n");
        return 0;
    }
    //If leaf Node
    if(temp->right == NULL && temp->left == NULL){
        printf("Inorder Successor is : %d \n",temp->key);
        return 1;
    }
    if(!inorderSuccessor(temp->left))
        inorderSuccessor(temp->right);
}

void q2(struct treenode *root){
    struct treenode *temp;
    int key;
    while(1){
        printf("\nEnter the Node whose Inorder Successor is to be found (-1 To Terminate) : ");
        scanf("%d", &key);
        if(key == -1) break;
        temp = search(root,key);
        if(temp == NULL)
            printf("\n Key does not exist");
        else if(temp->right == NULL) 
            printf("Inorder Successor doesn't exist\n");
        else
            key = inorderSuccessor(temp->right);
    }
    
}

struct treenode* q3(struct treenode *root,int a, int b){
    if(root == NULL) return NULL;

    if(root->key < a && root->key < b)
        return q3(root->right,a,b);

    if(root->key > a && root->key > b)
        return q3(root->left,a,b);

    return root;
}

struct treenode* q5(struct treenode* root){
    static int k = -1;
    struct treenode* min;
    if(k == -1){
        printf("Enter the Value of K for kth smallest Element in BST - ");
        scanf("%d",&k);
    }
    if(root == NULL)
        return NULL;
    min = q5(root->left);
    if(min != NULL){
        return min;
    }
    k--;
    if(k == 0)
        return root;
    else
        return q5(root->right);

}

void main()
{
  struct treenode *root=NULL;  
  struct treenode *temp, *lca;
  int key,a,b,k;
  while(1)
  {
     printf("\nEnter positive integer (-1 to Terminate): ");
     scanf("%d", &key);
     if(key<0)
         break;
     else
        {
             if(root== NULL)
               root = create_treenode(key);
             else
               insert_bst(root, key);
        }
  }

   inorder_binarytree(root);
   printf("\n");

    //    q1(root);

    //    q2(root);

    //Q3 of Assignment - 6
        // printf("Enter Two numbers to find their Lowest Common Ancestor - ");
        // scanf("%d %d",&a,&b);
        // lca = q3(root,a,b);
        // if(lca == NULL){
        //     printf("No LCA \n");
        // }else
        //     printf("LCA of %d and %d is %d \n",a,b,lca->key);
    //

    //Q5 of Assignment - 6
        
        temp = q5(root);
        if(temp == NULL){
            printf("Less than K elements in the BST \n");
        }else
            printf("Kth Smallest Element is %d \n",temp->key);
    //

}// End of main()   