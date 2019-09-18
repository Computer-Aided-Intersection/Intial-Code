#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void QsortRec(float arr[], int first, int last);
int partition(float arr[], int first, int last);
void swap(float *a, float *b);
void printArray(float arr[]);

int main(int argc, char *argv[]){ 

	int i, j;
	srand(time(0));
	
	int n = 10; 
	float time[n];
	int size = sizeof(time)/sizeof(time[0]) - 1;
	int vda[n][3];// allocates space easy way
	
	for(i = 0; i < n; i++){
		for (j = 0; j < 3; j++){
			if(j
			vda[i][j] = ((rand() % 25 ) + 25);// puts random variables in to arraty
		}
	}
	
	for(i = 0; i < n; i ++)
		time[i] = (float)(vda[i][0]) / (float)(vda[i][1]);
	
	
	printf("Before:");
	printArray(time);
	QsortRec(time, 0, size); 
	printf("After:");
	printArray(time);
	
}

void QsortRec(float arr[], int first, int last){
	
	if(first >= last) return;
	
	int pivotPos = partition(arr, first, last);
	QsortRec(arr, first, pivotPos-1);
	QsortRec(arr, pivotPos + 1, last);
	
}

int partition(float arr[], int first, int last){
	
	float pivotVal = arr[last];
	int i = first - 1, j = last;
	
	for(int j = first; j <= last - 1; j++){
		
		if(arr[j] < pivotVal){
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[last]);
	
	return i+1;
}

void swap(float *a, float *b){
	
	float temp = *a;
	*a = *b;
	*b = temp;
	
}

void printArray(float arr[]){
	int i;
	printf("\n");
	for(i = 0; i < 10; i++){
		printf("%f, ", arr[i]);
	}
	printf("\n");
}
