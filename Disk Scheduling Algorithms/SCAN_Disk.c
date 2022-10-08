#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100

int tracks[MAX_SIZE];

void pline(int x){
	printf("\n");
	for(int i=0; i<x; i++){
		printf("-");
	}
	printf("\n");
}

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

void sort(int num){
	for(int i=0; i<num; i++){
		for(int j=i+1; j<num; j++){
			if(tracks[i]>tracks[j]){
				swap(&tracks[i],&tracks[j]);
			}
		}
	}
}

void scan(int tracks[], int num, int start,char dir, int size){
	sort(num);
	int Rval,Lval;
	if(dir == 'R' || dir == 'r'){
		Rval = size-1;
		Lval = tracks[0];
	}
	else if(dir == 'L' || dir == 'l'){
		Rval = 0;
		Lval = tracks[num-1];
	}
	int seekCount = abs(start-Rval) + abs(Rval-Lval);
	printf("\nSeek Count = %d \n",seekCount);
}

void main(){
	pline(50);
	printf("SCAN - DISK SCHEDULING");
	pline(50);
	
	
	int num,start,size;
	char dir;
	
	printf("\n\n");
	printf("Enter the size of the disk : ");
	scanf("%d",&size);
	printf("Enter the number of tracks to be seeked : ");
	scanf("%d",&num);
	printf("Enter the current position of R/W head : ");
	scanf("%d",&start);
	printf("Enter tracks to be seeked : \n");
	for(int i=0; i<num; i++){
		scanf("%d",&tracks[i]);
		if(tracks[i] >= size){
			printf("\nExceeded Disk Size. Retry!\n\n");
			i=i-1;
		}
	}
	printf("\n");
	while(1){
		fflush(stdin);
		scanf("%c",&dir);
		printf("Enter the seek direction [R/L] : ");
		scanf("%c",&dir);
		if(dir=='r' || dir=='R' || dir=='L' || dir=='l' ){
			break;
		}
		else{
			printf("\nEnter a valid direction !!\n");
		}
	}
	printf("\n");
	scan(tracks,num,start,dir,size);
}
