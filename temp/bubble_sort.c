#include<stdio.h>


void display(int arr[], int len){
	for(int i=0; i<len; i++){
		printf("%d\t",arr[i]);
	}
	printf("\n");
}

void sort(int arr[], int len){
	for(int i=0; i<len; i++){
		for(int j=i+1; j<len; j++){
			if(arr[i]>arr[j]){
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void main(){
	int arr[] = {6,5,4,3,2,1,-2,-1};
	display(arr,sizeof(arr)/sizeof(int));
	sort(arr,sizeof(arr)/sizeof(int));
	display(arr,sizeof(arr)/sizeof(int));
	
}
