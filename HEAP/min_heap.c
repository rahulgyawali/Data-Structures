#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void MIN_HEAPIFY(int*,int,int);
void BUILD_HEAP(int*,int);
int HEAP_MIN(int*);
int EXTRACT_MIN(int*,int*);
void DECREASE_KEY(int*,int,int);
void INSERT(int*,int,int);
	
void MIN_HEAPIFY(int arr[],int i,int heapsize)
{
	int l;
	int r;
	int smallest;
	int temp;
	
	l = 2*i + 1;
	r = 2*i + 2;

	if ((l <= heapsize) && (arr[l] <  arr[i])) {

		smallest = l;
	}else {

		smallest = i;
	}	
	
	if ((r <= heapsize)  && (arr[r] < arr[smallest] )) {

		smallest = r;

	}

	if (smallest != i) {

		temp = arr[smallest];
		arr[smallest] = arr[i];
		arr[i]  = temp; 
		MIN_HEAPIFY(arr,smallest,heapsize);
	}
}

void BUILD_HEAP(int arr[],int heapsize)
{

	int i;
	
	for (i = (heapsize+1)/2; i >= 0; i--) {

		MIN_HEAPIFY(arr,i,heapsize);
	}

}

int HEAP_MIN(int arr[])
{
		
	return arr[0];
	
}

int EXTRACT_MIN(int arr[],int* heapsize)
{
	int min;
	int hsize;
	
	min = arr[0];
	arr[0] = arr[*heapsize];
	*heapsize--;
	hsize = *heapsize;
	MIN_HEAPIFY(arr,0,hsize);
	return min;
}

void DECREASE_KEY(int arr[],int i,int key)
{
	int temp;
	arr[i] = key;
	
	while (i > 0 && (arr[i/2] > arr[i])) {

		temp = arr[i];
		arr[i] = arr[i/2];
		arr[i/2] = temp;
		
		i = i/2;
	}
}

void INSERT(int arr[],int key,int heapsize)
{
	heapsize++;
	arr[heapsize] = INT_MAX;
	DECREASE_KEY(arr,heapsize,key);
}

int main()
{
	int i;
	int n;
	int heapsize;
	
	scanf("%d",&n);

	heapsize = n-1;
	int arr[100];

	for (i = 0; i < n; i++) {
		
		scanf("%d",&arr[i]);

	}

	BUILD_HEAP(arr,n-1);

	printf("MIN HEAP IS \n");

	for (i = 0; i < n; i++) {

		printf("%d\n",arr[i]);

	}

		
	printf("MIN_EXTRACT: %d\n",EXTRACT_MIN(arr,&heapsize));
	printf("MAIN_EXTRACT: %d\n",EXTRACT_MIN(arr,&heapsize));
	INSERT(arr,10,heapsize);
	printf("MIN_EXTRACT: %d\n",EXTRACT_MIN(arr,&heapsize));

	return 0;
}


