#include <stdio.h>
#include <stdlib.h>

#define VERTICES        6
#define VISITED         1
#define NOT_VISITED     0

int count;
int start = 0;
unsigned int result[VERTICES-1];
int visited[VERTICES];
unsigned int adj[VERTICES][VERTICES];

void iterate(int vertex)
{
	int j;
	unsigned int dist = 0;
	int curVert = vertex;

	for(j = 0; j < VERTICES; j++)
	{
	//	if(start == j) continue;
	//	if(vertex != j)
		{
			printf("min([%d + %d = ", result[vertex], adj[start][vertex]);
	//		if(adj[vertex][j] < result[j])
			{
				dist = adj[vertex][j] + result[vertex];//result[vertex];
				printf("%d], %d) -> ", dist, result[j]);
				if(dist < result[j])
					result[j] = dist;
			}
		}
		printf(" %d\n", result[j]);
	}	
	printf("\n");
}

int find_min()
{
	int i;
	int vertex;
	int small = 0x7FFFFFFF;
	/* Search for the vertex with smallest distance value */
        for(i = 0; i < VERTICES; i++)
        {
		if(VISITED == visited[i]) continue; 
                if(result[i] < small)
                {
                        small = result[i];
                        vertex = i;
                }
        }
	printf("* %d -> %d\n", vertex, small);
	return vertex;
}

void dijkstra(int vertex)
{
	int i;
	for(i = 0; i < VERTICES; i++)
	{
		iterate(vertex);
		visited[vertex] = VISITED;
		if(i < VERTICES-1)
		{
			printf("* Finding Minimum\n");
			vertex = find_min();
		}
		
	}
}
int main()
{
	int i, j;

        count = 0;
        for(i = 0; i < VERTICES; i++)
                for(j = 0; j < VERTICES; j++)
                        adj[i][j] = 0x7FFFFFFF;

        for(i = 1; i < VERTICES; i++)
		result[i] = 0x7FFFFFFF;

	adj[0][0] = 0;
	adj[1][1] = 0;
	adj[2][2] = 0;
	adj[3][3] = 0;
	adj[4][4] = 0;
	adj[5][5] = 0;

	adj[0][1] = 7;
        adj[0][2] = 9;
        adj[0][5] = 14;

        adj[1][0] = 7;
        adj[1][2] = 10;
        adj[1][3] = 15;

        adj[2][0] = 9;
        adj[2][1] = 10;
        adj[2][3] = 11;
        adj[2][5] = 2;

        adj[3][1] = 15;
        adj[3][2] = 11;
        adj[3][4] = 6;

        adj[4][3] = 6;
        adj[4][5] = 9;

        adj[5][0] = 14;
        adj[5][2] = 2;
        adj[5][4] = 9;

        for(i = 0; i < VERTICES; i++)
                visited[i] = NOT_VISITED;

        printf("* ---- Adjacency Matrix ---- \n");
        for(i = 0; i < VERTICES; i++)
        {
                for(j = 0; j < VERTICES; j++)
                {
                        printf("%08x ", adj[i][j]);
                }
                printf("\n");
        }
        printf("* -------------------------- \n");

	dijkstra(0);

        printf("\n\n");
        printf("* ---- Shortest Path Matrix ---- \n");
        for(i = 1; i < VERTICES; i++)
		printf(" %d ", result[i]);
	printf("\n");
        printf("* ------------------------------ \n");

	return 0;
}
