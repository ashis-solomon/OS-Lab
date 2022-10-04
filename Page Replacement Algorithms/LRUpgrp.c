#include<stdio.h>
#include<stdbool.h>

#define MAX_SIZE 100


int frameSize;
int page[MAX_SIZE],rString[MAX_SIZE];
int len=0,r;
int pagefault=0;

void pline(int x){
	printf("\n");
	for(int i=0; i<x; i++){
		printf("-");
	}
	printf("\n");
}

int inPage(int data,int frameSize){
	for(int i=0; i<frameSize; i++){
		if(page[i] == data){
			return 1;
		}
	}
	return 0;
}

int isEmpty(int frameSize){
	for(int i=0; i<frameSize; i++){
		if(page[i] == -1){
			return 1;
		}
	}
	return 0;
}

int indexEmpty(int frameSize){
	for(int i=0; i<frameSize; i++){
		if(page[i] == -1){
			return i;
		}
	}
	return -1;
}

void main(){
	pline(50);
	printf("\tLRU PAGE REPLACEMENT ALGORITHM");
	pline(50);
	printf("\n");
	
	printf("Enter the Frame Size : ");
	scanf("%d",&frameSize);
	printf("Enter the Reference String [terminated by '-1'] : \n");
	while(1){
		scanf("%d",&r);
		if(r==-1){
			break;
		}
		rString[len] = r;
		len += 1;
	}
	printf("\n");
	
	//intial page empty value = -1
	for(int i=0; i<frameSize; i++){
		page[i] = -1;
	}
	
	int proc = 0;
	while(proc < len){
		int data = rString[proc];
		if(inPage(data,frameSize)){
			printf("\nHIT\n");
			int temp[frameSize-1];
			int var =0;
			for(int k=0; k<frameSize; k++){
				if(page[k]!=data){
					temp[var] = page[k];
					var+=1;
				}
			}
			page[0] = data;
			for(int k=1; k<frameSize; k++){
				page[k] = temp[k-1];
			}
			
			// display
			for(int k=0; k<frameSize; k++){
				printf("Page %d : %d\n",k+1,page[k]);
			}
			printf("\n");
		}
		else{
			printf("\nMISS\n");	
			pagefault += 1;
			int temp[frameSize-1];
			for(int k=0; k<frameSize-1; k++){
				temp[k] = page[k];
			}
			page[0] = data;
			for(int k=1; k<frameSize; k++){
				page[k] = temp[k-1];
			}
			
			//display
			for(int k=0; k<frameSize; k++){
				printf("Page %d : %d\n",k+1,page[k]);
			}
			printf("\n");
		}
		proc += 1;
	}
	
	pline(50);
	printf("\n");
	printf("Total no. of Page Faults = %d\n",pagefault);
	pline(50);
	
}
