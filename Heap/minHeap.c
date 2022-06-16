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

int Parent(struct Heap *h,int i)
{
    if(i <= 0 || i > h->count)
    {
        return -1;
    }
    int parent = h->arr[(i-1)/2];
    return parent;
}

int LeftChild(struct Heap *h,int i)
{
    int left =  2*i+1;
    return left;
}

int RightChild(struct Heap *h,int i)
{
    int right = 2*i+2;
    return right;
}

int getMin(struct Heap *h)
{
    return h->arr[0];
}

void swap(int *a,int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int ifsmaller(int parent,int child)
{
    if(parent <= child)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void heapify(struct Heap **h,int i)
{
    int left,right,min,n;
    left = LeftChild((*h),i);
    right = RightChild((*h),i);
    min = i;
    n = (*h)->count;
    printf("1\n");
    while(left < n && (*h)->arr[left] < (*h)->arr[min])
    {
        printf("2\n");
        min = left;
    }

    while(right < n && (*h)->arr[right] < (*h)->arr[min])
    {
        printf("3\n");
        min = right;
    }

    if(min != i)
    {
        printf("4\n");
        swap(&(*h)->arr[min],&(*h)->arr[i]);
        heapify(&(*h),min);
    }
}

struct Heap* insert(struct Heap *h,int data)
{
    // resize
    int i = h->count;
    h->arr[i] = data;
    h->count++;
    // if(i == 0) return h;
    while(i>0 && h->arr[i] < h->arr[(i-1)/2])
    {
        swap(&h->arr[i],&h->arr[(i-1)/2]);
        i = (i-1)/2;
    }
    return h;
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
    heap = insert(heap,15);
    printf("Inserted %d \n",15);
    heap = insert(heap,5);
    printf("Inserted %d \n",5);

    heap = insert(heap,20);
    printf("Inserted %d \n",20);

    heap = insert(heap,1);
    printf("Inserted %d \n",1);

    heap = insert(heap,17);
    printf("Inserted %d \n",17);
    heap = insert(heap,10);
    printf("Inserted %d \n",10);
    heap = insert(heap,30);
    printf("Inserted %d \n",30);

   // printf("This is the number before delete %d\n",heap->arr[0]);
    printheap(heap);
    printf("\n");
    int x = delete(&heap);
    printf("This is the number %d\n",x);
    printheap(heap);
    return 0;
}