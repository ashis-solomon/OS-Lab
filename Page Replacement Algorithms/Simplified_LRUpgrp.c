#include<stdio.h>


#define MAX_SIZE 100

int page[MAX_SIZE],count[MAX_SIZE],rString[MAX_SIZE];
int frameSize,len=0,r;
int ctr = 0;
int pagefault = 0;

void pline(int x){
	printf("\n");
	for(int i=0; i<x; i++){
		printf("-");
	}
	printf("\n");
}

int findIndex(int frameSize){
	int index = 0;
	int temp_ctr = count[0];
	
	for(int i=0; i<frameSize; i++){
		if(count[i] < temp_ctr){
			index = i;
			temp_ctr = count[i];
		}
	}
	return index;
}

int inPage(int data,int frameSize){
	for(int i=0; i<frameSize; i++){
		if(page[i] == data){
			return 1;
		}
	}
	
	return 0;
}

void incCounter(int data,int frameSize){
	for(int i=0; i<frameSize; i++){
		if(page[i] == data){
			ctr += 1;
			count[i] = ctr;
			
		}
	}
}

void display(int data,int frameSize){
	for(int i=0; i<frameSize; i++){
		if(page[i] == data){
			printf("Page %d : %d *\n",i+1,page[i]);
		}else{
			printf("Page %d : %d\n",i+1,page[i]);
		}
	}
	printf("\n");
}

void main(){
	pline(50);
	printf("\tLRU PAGE REPLACEMENT ALGORITHM [V2]");
	pline(50);
	printf("\n");
	
	printf("Enter the Frame Size : ");
	scanf("%d",&frameSize);
	printf("Enter the Reference String ['-1' to terminate] :\n");
	while(1){
		scanf("%d",&r);
		if(r==-1){
			break;
		}
		rString[len] = r;
		len += 1;
	}
	printf("\n");
	
	//initialize empty pages to -1 and count array to 0
	for(int i=0; i<frameSize; i++){
		page[i] = -1;
		count[i] = 0;
	}
	
	int proc = 0;
	while(proc < len){
		int data = rString[proc];
		if(inPage(data,frameSize)){
			printf("\nHIT\n");	
			incCounter(data,frameSize);
			display(data,frameSize);
		}else{
			printf("\nMISS\n");
			pagefault += 1;
			int k = findIndex(frameSize);
			page[k] = data;
			ctr += 1;
			count[k] = ctr;
			display(data,frameSize);
		}
		proc += 1;
	}
	
	pline(50);
	printf("No. of Page Faults = %d",pagefault);
	pline(50);
}








