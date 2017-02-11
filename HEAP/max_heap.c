#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void MAX_HEAPIFY(int*,int,int);
void BUILD_HEAP(int*,int);
void HEAP_SORT(int*,int);


void MAX_HEAPIFY(int arr[],int i,int heapsize)
{
	int l;
	int r;
	int largest;
	int temp;
	
	l = 2*i + 1;
	r = 2*i + 2;

	if ((l <= heapsize) && (arr[l] >  arr[i])) {

		largest = l;
	}else {

		largest = i;
	}	
	
	if ((r <= heapsize)  && (arr[r] > arr[largest] )) {

		largest = r;

	}

	if (largest != i) {

		temp = arr[largest];
		arr[largest] = arr[i];
		arr[i]  = temp; 
		MAX_HEAPIFY(arr,largest,heapsize);
	}
}

void BUILD_HEAP(int arr[],int heapsize)
{
	int i;
	
	for (i = (heapsize+1)/2; i >= 0; i--) {
		
		MAX_HEAPIFY(arr,i,heapsize);
	}
}

void HEAP_SORT (int arr[],int heapsize)
{
	int i;
	int temp;
	int n = heapsize;

	BUILD_HEAP(arr,heapsize);

	for (i = n; i >= 0; i--) {	

		temp   = arr[0];
		arr[0] = arr[i];		
		arr[i] = temp;
		
		heapsize = heapsize - 1;	
		
		MAX_HEAPIFY(arr,0,heapsize);
	}
}

int main()
{
	int i;
	int n;
	int q;
	char x;
	
	scanf("%d",&n);
	int arr[100];

	for (i = 0;i < n; i++) {
		
		scanf("%d",&arr[i]);
	}

	BUILD_HEAP(arr,n-1);

	printf("MAX HEAP IS \n");

	for (i = 0; i < n; i++) {

		printf("%d\n",arr[i]);

	}

	HEAP_SORT(arr,n-1);

	printf("After Heapsort\n");

	for (i = 0; i < n; i++) {

              printf("%d\n",arr[i]);
       }
	
	return 0;
}
