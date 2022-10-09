#include<stdio.h>


#define MAX_SIZE 100

int page[MAX_SIZE],count[MAX_SIZE],rString[MAX_SIZE];
int frameSize;
int len,ctr=0;
int pageFault=0;

void pline(int x){
	printf("\n");
	for(int i=0; i<x; i++){
		printf("-");
	}
	printf("\n");
}

int findDataIndex(int data,int frameSize){
	for(int i=0; i<frameSize; i++){
		if(page[i] == data){
			return i;
		}
	}
	return -1;
}

void display(int data, int frameSize){
	printf("\n");
	for(int i=0; i<frameSize; i++){
		if(page[i] == data){
			printf("Page %d : %d * \n",i+1,page[i]);
		}else{
			printf("Page %d : %d \n",i+1,page[i]);
		}
	}
	printf("\n");
}

void pushPage(int data, int frameSize){
	int temp = count[0];
	int temp_index = 0;
	for(int i=0; i<frameSize; i++){
		if(count[i] < temp){
			temp = count[i];
			temp_index = i;
		}
	}
	
	page[temp_index] = data;
	count[temp_index] = ctr;
	ctr += 1;

}

void lru(){
	for(int i=0; i<len; i++){
		int data = rString[i];
		int temp = findDataIndex(data,frameSize);
		if(temp == -1){
			printf("\nMISS");
			pageFault += 1;
			pushPage(data,frameSize);
			display(data,frameSize);
		}else{
			printf("\nHIT");
			count[temp] = ctr;
			ctr += 1;
			display(data,frameSize);
		}
	}

}

void main(){
	pline(50);
	printf("\tLRU PAGE REPLACEMENT ALGORITHM");
	pline(50);

	printf("\n");
	printf("Enter the frame size  : ");
	scanf("%d",&frameSize);
	printf("Enter the reference string ['-1' to terminate] : \n");
	int data;
	while(1){
		scanf("%d",&data);
		if(data == -1){
			break;
		}
		rString[len] = data;
		len += 1;
	}
	
	//initialize empty page as -1 and count array
	for(int i=0; i<frameSize; i++){
		page[i] = -1;
		count[i] = -1;
	}
	
	lru();
	printf("No. of Page Faults = %d",pageFault);
	pline(50);
}
