#include <stdio.h>
#include <stdlib.h>

#define VERTICES	8
#define VISITED		1
#define NOT_VISITED	0

int count;
int result[VERTICES];
int visited[VERTICES];
int adj[VERTICES][VERTICES];

void dfs(int vertex)
{
	int j;
	result[count] = vertex;
	count++;
	visited[vertex] = VISITED;
	printf(" %d ", vertex);
	for(j = 0; j < VERTICES; j++)
	{
		if(1 == adj[vertex][j])
		{
			if(NOT_VISITED == visited[j])
			{
				printf("->");
				dfs(j);
			}
		}
	}
}

int main()
{
	int i, j;

	count = 0;
	for(i = 0; i < VERTICES; i++)
		for(j = 0; j < VERTICES; j++)
			adj[i][j] = 0;

	#if 0
	adj[0][1] = 1;
	adj[0][2] = 1;
	adj[0][5] = 1;

	adj[1][0] = 1;
	adj[1][2] = 1;
	adj[1][3] = 1;

	adj[2][0] = 1;
	adj[2][1] = 1;
	adj[2][3] = 1;
	adj[2][5] = 1;

	adj[3][1] = 1;
	adj[3][2] = 1;
	adj[3][4] = 1;

	adj[4][3] = 1;
	adj[4][5] = 1;

	adj[5][0] = 1;
	adj[5][2] = 1;
	adj[5][4] = 1;
	#endif

	#if 1  
	adj[0][1] = 1;
	adj[0][3] = 1;
	adj[0][6] = 1;

	adj[1][0] = 1;
	adj[1][4] = 1;
	adj[1][5] = 1;

	adj[2][5] = 1;
	adj[2][7] = 1;

	adj[3][0] = 1;
	adj[3][5] = 1;

	adj[4][1] = 1;
	adj[4][6] = 1;

	adj[5][1] = 1;
	adj[5][2] = 1;
	adj[5][3] = 1;

	adj[6][0] = 1;
	adj[6][4] = 1;

	adj[7][2] = 1;
	#endif

	for(i = 0; i < VERTICES; i++)
		visited[i] = NOT_VISITED;

	printf("* ---- Adjacency Matrix ---- \n");
	for(i = 0; i < VERTICES; i++)
	{
		for(j = 0; j < VERTICES; j++)
		{
			printf("%d ", adj[i][j]);
		}
		printf("\n");
	}
	printf("* -------------------------- \n");

	dfs(0);

	printf("\n\n");
	printf("* ---- DFS Order ---- \n");
	for(i = 0; i < count; i++)	
		printf(" %d ", result[i]);
	printf("\n");
	printf("* ------------------- \n");
	return 0;
}	
