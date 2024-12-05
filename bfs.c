#include<stdio.h>
#include<stdlib.h>

typedef struct queue
{
    int *arr,size, front, end;
} Queue;
void createQueue(Queue *queue,int n)
{
    queue->size=n;
    queue->arr=(int *)malloc(n*sizeof(int));
    queue->front=queue->end=-1;
}
void enqueue(Queue *queue, int n)
{
    if(queue->end==queue->size-1)
    {
        printf("OVERFLOW\n");
        return;
    }
    if(queue->front==-1)
    queue->front=queue->end=0;
    else
    queue->end++;
    queue->arr[queue->end]=n;
}
void dequeue(Queue *queue)
{
    if(queue->front==-1)
    {
        printf("UNDERFLOW\n");
        return;
    }
    int p = queue->front;
    if(queue->front==queue->end)
    queue->front=queue->end=-1;
    else
    queue->front++;
    printf("Dequeued element = %d\n",queue->arr[p]);
}

int isEmpty(Queue *queue)
{
    if(queue->front==-1 && queue->end==-1)
    return 1;
    return 0;
}

int main()
{
    int noofnodes;
    printf("Enter number of nodes : ");
    scanf("%d",&noofnodes);

    Queue q;
    q.arr=(int*)malloc(noofnodes*sizeof(int));

    int **array = (int **)malloc(noofnodes * sizeof(int *));
    if (array == NULL) {
        perror("Failed to allocate memory for rows");
        return 1;
    }

    for (int i = 0; i < noofnodes; i++) {
        array[i] = (int *)malloc(noofnodes * sizeof(int));
        if (array[i] == NULL) {
            perror("Failed to allocate memory for columns");
            return 1;
        }
    }

}