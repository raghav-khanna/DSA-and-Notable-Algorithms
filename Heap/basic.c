#include<stdio.h>
#include<stdlib.h>

struct Heap
{
    int *arr;
    int count; //current number of elements
    int cap; // size of array;
};

struct Heap *create_heap(int capacity)
{
    struct Heap* heap = (struct Heap*) malloc(sizeof(struct Heap));
    heap->count = 0;
    heap->cap = capacity;
    heap->arr = (int *)malloc(sizeof(int)*capacity);
    return heap;
}

int Parent(struct Heap *node,int i)
{
    if(i <= 0 || i > node->count)
    {
        return -1;
    }
    int parent = node->arr[(i-1)/2];
    return parent;
}

int LeftChild(struct Heap *node,int i)
{
    int left =  2*i+1;
    return left;
}

int RightChild(struct Heap *node,int i)
{
    int right = 2*i+2;
    return right;
}

int getMax(struct Heap *node)
{
    return node->arr[0];
}

void swap(int *a,int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int ifgreater(int parent,int child)
{
    if(parent >= child)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void heapify(struct Heap **node,int i)
{
    int left,right,max,n;
    left = LeftChild((*node),i);
    right = RightChild((*node),i);
    max = i;
    n = (*node)->count;
   
    while(left < n && (*node)->arr[left] > (*node)->arr[max])
    {
        max = left;
    }

    while(right < n && (*node)->arr[right] > (*node)->arr[max])
    {
        max = right;
    }

    if(max != i)
    {
        swap(&(*node)->arr[max],&(*node)->arr[i]);
        heapify(&(*node),max);
    }
}

struct Heap* insert(struct Heap *node,int data)
{
    // resize
    int i = node->count;
    node->arr[i] = data;
    node->count++;
    // if(i == 0) return node;
    while(i>0 && node->arr[i] > node->arr[(i-1)/2])
    {
        swap(&node->arr[i],&node->arr[(i-1)/2]);
        i = (i-1)/2;
    }
    return node;
}

int delete(struct Heap **h)
{
    struct Heap *ptr = *h;
  
    int data;
    if((*h)->count == 0)
    {
        return 0;
    }
    data = (*h)->arr[0];
    (*h)->arr[0] = (*h)->arr[(*h)->count-1];
    (*h)->count--;
    heapify(&ptr,0);
    return data;
}

struct Heap *heapsort(struct Heap *h)
{
    struct Heap* ptr = create_heap(h->count);
    for(int i = 0;i<h->count;i++)
    {
        ptr = insert(ptr,delete(&h));
    }
    return ptr;
}

void printheap(struct Heap *h)
{
    for(int i = 0;i<h->count;i++)
    {
        printf("%d,",h->arr[i]);
    }
}

int main()
{
    struct Heap* heap = NULL;
    heap = create_heap(10);
    heap = insert(heap,45);
    heap = insert(heap,12);
    heap = insert(heap,56);
    heap = insert(heap,33);
    heap = insert(heap,87);
    heap = insert(heap,20);
    heap = insert(heap,70);
    heap = insert(heap,5);
    heap = insert(heap,66);
    heap = insert(heap,90);


   // printf("This is the number before delete %d\n",heap->arr[0]);
    printheap(heap);
   
    return 1;
}