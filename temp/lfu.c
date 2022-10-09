#include<stdio.h>


#define MAX_SIZE 100

int page[MAX_SIZE],rString[MAX_SIZE],freq[MAX_SIZE],timeStore[MAX_SIZE];
int time=0;
int frameSize;
int len=0;
int pageFault=0;

void pline(int x){
	printf("\n");
	for(int i=0; i<x; i++){
		printf("-");
	}
	printf("\n");
}

void display(int data){
	printf("\n");
	for(int i=0; i<frameSize; i++){
		if(page[i] == data){
			printf("Page %d : %d * \n",i+1,page[i]);
			//printf("Page %d : %d *  freq = %d   timeStore = %d\n",i+1,page[i],freq[i],timeStore[i]);
		}else{
			printf("Page %d : %d \n",i+1,page[i]);
			//printf("Page %d : %d   freq = %d   timeStore = %d\n",i+1,page[i],freq[i],timeStore[i]);
		}
	}
	printf("\n");
}

int findIndex(int data){
	for(int i=0; i<frameSize; i++){
		if(page[i] == data){
			return i;
		}
	}
	return -1;
}

int findMinFreq(){
	int min = freq[0];
	for(int i=0; i<frameSize; i++){
		if(freq[i] < min){
			min = freq[i];
		}
	}
	return min;
}

void pushPageHit(int data){
	int temp_index;
	
	for(int i=0; i<frameSize; i++){
		if(page[i] == data){
			temp_index = i;
			freq[temp_index] += 1;
			timeStore[temp_index] = time;
			time += 1;
		}
	}
}

void pushPageMiss(int data){
	int min = findMinFreq();
	int temp_time;
	int temp_index;
	for(int i=0; i<frameSize; i++){
		if(freq[i] == min){
			temp_time = timeStore[i];
			temp_index = i;
			break;
		}
	}
	
	for(int i=0; i<frameSize; i++){
		if(freq[i] == min){
			if(timeStore[i] < temp_time){
				temp_time = timeStore[i];
				temp_index = i;
			}
		}
	}

	page[temp_index] = data;
	freq[temp_index] = 0;
	timeStore[temp_index] = time;
	time += 1;

}

void lfu(){
	for(int i=0; i<len; i++){
	
		int data = rString[i];
		int temp = findIndex(data);

		if(temp != -1){
			printf("\nHIT");
			pushPageHit(data);
			display(data);
		}else{
			printf("\nMISS");
			pageFault += 1;
			pushPageMiss(data);
			display(data);
		}
	
	}

}


void main(){
	pline(50);
	printf("\tLFU PAGE REPLACEMENT ALGORITHM");
	pline(50);
	
	printf("\n");
	printf("Enter the frame size : ");
	scanf("%d",&frameSize);
	printf("\nEnter the reference String ['-1' to terminate]: \n");
	int data;
	while(1){
		scanf("%d",&data);
		if(data == -1){
			break;
		}
		rString[len++] = data;
	}
	printf("\n");
	
	
	//initialize arrays
	for(int i=0; i<MAX_SIZE; i++){
		page[i] = -1;
		freq[i] = -1;
		timeStore[i] = -1;
	}
	
	lfu();
	printf("No. of Page Faults = %d",pageFault);
	pline(50);
}







