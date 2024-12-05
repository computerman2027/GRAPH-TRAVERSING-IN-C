#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int *arr, size, front, end;
} Queue;
void createQueue(Queue *queue, int n)
{
    queue->size = n;
    queue->arr = (int *)malloc(n * sizeof(int));
    queue->front = queue->end = -1;
}
void enqueue(Queue *queue, int n)
{
    if (queue->end == queue->size - 1)
    {
        printf("OVERFLOW\n");
        return;
    }
    if (queue->front == -1)
        queue->front = queue->end = 0;
    else
        queue->end++;
    queue->arr[queue->end] = n;
}
int dequeue(Queue *queue)
{
    if (queue->front == -1)
    {
        printf("UNDERFLOW\n");
        return -99999;
    }
    int p = queue->front;
    if (queue->front == queue->end)
        queue->front = queue->end = -1;
    else
        queue->front++;
    return queue->arr[p];
}
int isEmpty(Queue *queue)
{
    if (queue->front == -1 && queue->end == -1)
        return 1;
    return 0;
}

int main()
{
    int noofnodes;
    int i, j;
    printf("Enter number of nodes : ");
    scanf("%d", &noofnodes);

    Queue q;
    q.size=noofnodes;
    q.front=-1;
    q.end=-1;
    q.arr = (int *)malloc(noofnodes * sizeof(int));

    int *visited = (int *)malloc(noofnodes * sizeof(int));
    for (i = 0; i < noofnodes; i++)
    {
        visited[i] = 0;
    }
    int **array = (int **)malloc(noofnodes * sizeof(int *));
    if (array == NULL)
    {
        perror("Failed to allocate memory for rows");
        return 1;
    }

    for (i = 0; i < noofnodes; i++)
    {
        array[i] = (int *)malloc(noofnodes * sizeof(int));
        if (array[i] == NULL)
        {
            perror("Failed to allocate memory for columns");
            return 1;
        }
    }

    printf("Enter graph in terms of adjagency matrix :\n");
    for (i = 0; i < noofnodes; i++)
    {
        for (j = 0; j < noofnodes; j++)
        {
            scanf("%d", &array[i][j]);
        }
    }

    int startnode;
    printf("Enter start node node : ");
    scanf("%d", &startnode);

    printf("%d ", startnode);
    visited[startnode] = 1;
    enqueue(&q, startnode);

    while (!isEmpty(&q))
    {
        int node = dequeue(&q);
        // printf("node = %d\n",node);
        for(j=0;j<noofnodes;j++)
        {
            if(array[node][j]==1 && visited[j]==0)
            {
                printf("%d ",j);
                visited[j]=1;
                enqueue(&q,j);
            }
        }
    }

    return 0;
}