#include <stdio.h>
#define MAX 10

int parent[MAX];
int rankArr[MAX];

void make_set(int x) 
{
    	parent[x] = x;
    	rankArr[x] = 0;
    	printf("Set created for element %d\n", x);
}

int find_set(int x) 
{
    if (parent[x] != x)
        parent[x] = find_set(parent[x]);
    return parent[x];
}

void union_set(int x, int y)
{
	int rootX = find_set(x);
    	int rootY = find_set(y);
    	if (rootX == rootY)
        	printf("They are already in the same set.\n");
    	else
    	{
    		if (rankArr[rootX] < rankArr[rootY])
        		parent[rootX] = rootY;
    				if (rankArr[rootX] > rankArr[rootY])
        				parent[rootY] = rootX;
    				else
    				{
        				parent[rootY] = rootX;
        				rankArr[rootX]++;
        			}
    	}
    	printf("Union done for %d and %d\n", x, y);
}

void display_array()
{
	printf("Parent array: ");
    	for (int i = 0; i < MAX; i++) 
        	printf("%d ", parent[i]);
    	printf("\n");
	printf("Rank array: ");
    	for (int i = 0; i < MAX; i++) 
        	printf("%d ", rankArr[i]);
    	printf("\n");
}

int main() 
{
	int choice, x, y;
    	do 
    	{
        	printf("\n===== DISJOINT SET MENU =====\n 1. Make Set 2. Find Set 3. Union Sets 4. Exit\n");
        	printf("Enter your choice: ");
        	scanf("%d", &choice);
        	switch (choice) 
        	{
            		case 1: printf("Enter element: ");
                		scanf("%d", &x);
                		make_set(x);
                		break;
            		case 2: printf("Enter element: ");
                		scanf("%d", &x);
                		printf("Representative: %d\n", find_set(x));
                		break;
			case 3: printf("Enter first element: ");
                		scanf("%d", &x);
                		printf("Enter second element: ");
                		scanf("%d", &y);
                		union_set(x, y);
                		display_array();
                		break;
                	case 4: printf("Exiting...\n"); 
            			break;
            		default: printf("Invalid choice! Try again.\n");
            	}
        } while (choice != 4);
        
	return 0;
}

