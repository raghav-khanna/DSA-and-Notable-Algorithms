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

void insert_binarytree(struct treenode *root, int key)
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

struct treenode* inorder_successor(struct treenode *root)
{
    struct treenode *cur= NULL;
   
    if(root == NULL)
           return NULL;
    
    if(root->right!= NULL) 
      {
        cur = root->right;
        while(cur->left!= NULL)
        {
          cur= cur->left;
         }
      }
    return cur;
}
 

struct treenode* inorder_pre(struct treenode* root){
   struct treenode *cur = NULL;
   if(root == NULL)
      return NULL;
   if(root->left != NULL){
      cur = root->left;
      while(cur->left!=NULL){
         cur = cur->right;
      }

   }
   return cur;
}

 //https://www.javatpoint.com/deletion-in-binary-search-tree - Similar Deletion approach
void deleteNode(struct treenode **root,struct treenode **parent){
   //Root is the node which is to be deleted
   if(*root == NULL){
       printf("Element Not Found!!\n");
       return;
   }
   struct treenode *curr = *root;
   printf("To be deleted - %d, child of parent - %d\n",(*root)->key,(*parent)->key);
   if((*root)->left != NULL && (*root)->right != NULL){
      struct treenode *temp = inorder_successor(*root);
      (*root)->key = temp->key;
      (*parent) = searchParent((*root),temp->key);
      deleteNode(&temp,&(*parent));
   }else if((*root)->left == NULL && (*root)->right != NULL){
      (*root)->key = (*root)->right->key;
      parent = root;
      deleteNode(&((*root)->right),&(*parent));
   }else if((*root)->left != NULL && (*root)->right == NULL){
      (*root)->key = (*root)->left->key;
      parent = root;
      deleteNode(&((*root)->left),&(*parent));
   }else if((*root)->left == NULL && (*root)->right == NULL){
       if((*parent)->left !=  NULL && ((*parent)->left->key == (*root)->key)){
          (*parent)->left = NULL;
         //  free(curr);
         //  *root = NULL;
       }else{
          (*parent)->right = NULL;
         //  free(curr);
         //  *root = NULL;
       }
   }
   // return root;
}

void inOrder(struct treenode *root)
{
    if(root!= NULL)
     {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
     }
}

void main()
{
  struct treenode *root=NULL;  // otherwise it will be dangling pointer 
  struct treenode *temp, *parent;
  int key;
  while(1)
  {
     printf("\nEnter positive integer:");
     scanf("%d", &key);
     if(key<0)
         break;
     else
        {
             if(root== NULL)
               root = create_treenode(key);
             else
               insert_binarytree(root, key);
        }
  }// end of while

   inOrder(root);
   printf("\n");
   while(1){
      int ch;
      printf("Enter the number to be deleted [-1 for termination] ");
      scanf("%d",&ch);
      if(ch==-1) break;
      parent = searchParent(root,ch);
      temp = parent->left->key == ch?parent->left:parent->right;
      deleteNode(&temp,&parent);
      printf("New tree - \n");
      inOrder(root);
      printf("\n");
   }
   

}// End of main()   