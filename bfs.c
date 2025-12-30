#include<stdio.h>
#include<stdlib.h>

#define MAX_NODES 10

int queue[MAX_NODES], visited[MAX_NODES], adjacency_matrix[MAX_NODES][MAX_NODES];
int front = -1, rear = -1;

void enqueue(int node)
{
    if(rear == MAX_NODES - 1)
    {
        printf("Queue overflow\n");
        exit(1);
    }
    if(front == -1)
        front = 0;
    rear++;
    queue[rear] = node;
}

int dequeue()
{
    int node;
    if(front == -1)
    {
        printf("Queue underflow\n");
        exit(1);
    }
    node = queue[front];
    if(front == rear)
        rear = front = -1;
    else
        front++;
    return node;
}

void bfs(int start_node, int num_nodes)
{
    int i, current_node;
    enqueue(start_node);
    visited[start_node] = 1;

    while(front != -1)
    {
        current_node = dequeue();
        printf("%d ", current_node);

        for(i = 0; i < num_nodes; i++)
        {
            if(adjacency_matrix[current_node][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

int main()
{
    int i, j, num_nodes, start_node;

    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);

    printf("Enter the adjacency matrix:\n");
    for(i = 0; i < num_nodes; i++)
    {
        for(j = 0; j < num_nodes; j++)
        {
            scanf("%d", &adjacency_matrix[i][j]);
        }
    }

    // Initialize visited array
    for(i = 0; i < num_nodes; i++)
        visited[i] = 0;

    printf("Enter the start node: ");
    scanf("%d", &start_node);   // ✅ FIXED

    bfs(start_node, num_nodes);

    return 0;
}
