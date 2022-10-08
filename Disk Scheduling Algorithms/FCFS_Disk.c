#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100

void pline(int x){
	printf("\n");
	for(int i=0; i<x; i++){
		printf("-");
	}
	printf("\n");
}

void display(int arr[], int num, int start){
	printf("\nTracks : \n");
	printf("%d  ->  ",start);
	for(int i=0; i<num-1; i++){
		printf("%d  ->  ",arr[i]);
	}
	printf("%d",arr[num-1]);
	printf("\n");

}

void fcfs(int tracks[], int num, int start){
	int temp = start;
	int seekCount = 0;
	
	for(int i=0; i<num; i++){
		seekCount += abs(tracks[i] - temp);
		temp = tracks[i];
	}
	
	printf("\nSeek Count = %d\n",seekCount);

}

void main(){
	pline(50);
	printf("FCFS - DISK SCHEDULING");
	pline(50);
	
	
	int num,start;
	int tracks[MAX_SIZE];
	printf("\n\n");
	printf("Enter the number of tracks to be seeked : ");
	scanf("%d",&num);
	printf("Enter the current position of R/W head : ");
	scanf("%d",&start);
	printf("Enter tracks to be seeked : \n");
	for(int i=0; i<num; i++){
		scanf("%d",&tracks[i]);
	}
	printf("\n");
	display(tracks,num,start);
	fcfs(tracks,num,start);
}
