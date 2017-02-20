#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Queue{

	int front;
	int rear;
	int size;	
	int *a;
};

struct Queue *create(int capacity)
{

	struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
	queue->front = queue->rear = -1;
	queue->size = capacity -1;
	queue->a = (int *)malloc(sizeof(int) * (capacity));
	
	return queue;
}

int  Full(struct Queue *queue)
{
	return (queue->size < queue->rear);
}

int Empty(struct Queue *queue)
{
	return((queue->front == -1) || (queue->front > queue->rear)) ;
}

void eq(struct Queue *queue,int x)
{
	if (((queue->front == -1) && (queue->rear == -1) )) {

		queue->front = 0;
		queue->rear = 0;
		queue->a[queue->rear] = x;

	}else if (!Full(queue)) {

		queue->rear = queue->rear + 1;
		queue->a[queue->rear] = x;
	}
}

int dq(struct Queue *queue)
{
	if(!Empty(queue)) {

		int item = queue->a[queue->front];
		queue->front = (queue->front + 1);
		return item;

	}
}



void bfs (int s, struct Queue* queue,int state[],int g[][1000],int v)
{

	int i;
	
	eq(queue,s);

	printf("INSIDE BFS :\n");	

	while (!Empty(queue)) {

		int x;
		x = dq(queue);
		state[x] = 1;
		printf("%d ",x);
				
		for (i = 0; i < v; i++) {

			if (g[x][i] == 1) {

				if (state[i] == -1) {
			
					state[i] = 0;
					eq(queue,i);

				}
			}
		}

		printf("\n");
	}
}

int main()
{
	int i;
	int v;
	int e;
	int x;
	int y;
	int s;
	int j;

	scanf("%d %d",&v,&e);

	int g[1000][1000];

	for (i = 0; i <v ; i++) {

		for (j = 0; j < v; j++) {
		
			g[i][j] = 0;
		}
	}

	for (i = 0; i < e; i++) {

		scanf("%d %d",&x,&y);
		g[x][y] = 1;
		g[y][x] = 1;
	}

	scanf("%d",&s);

	int state [v];

	for (i = 0; i <v ;i++) {

		state[i] = -1;
	}

	state[s] = 0;

	struct Queue* queue = NULL;
	queue = create(v);
	bfs(s,queue,state,g,v);

	return 0;
}
