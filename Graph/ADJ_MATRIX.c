#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
	int j;
	int v;
	int e;
	int x;
	int y;
	int t;

	scanf("%d %d",&v,&e);

	int g[v+1][v+1];

	for (i = 0; i <=v; i++) { 

		for (j = 0; j <=v ; j++) {
	
			g[i][j] = 0;
		}
	}

	for (i = 0; i < e; i++) {

		scanf("%d %d",&x,&y);
		
		g[x][y] = 1;
		g[y][x] = 1;
	}

	scanf("%d",&t);

	while (t--) {

		scanf("%d %d",&x,&y);

		if (g[x][y] == 1) {

			printf("YES\n");
		}else {

			printf("NO\n");
		}
	}	
	
	return 0;
}
