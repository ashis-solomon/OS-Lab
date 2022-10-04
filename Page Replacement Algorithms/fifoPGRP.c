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

int inPage(int num,int frameSize){
	for(int i=0; i<frameSize; i++){
		if(page[i] == num){
			return 1;
		}
	}
	
	return 0;
}

void main(){

	pline(50);
	printf("\tFIFO PAGE REPLACEMENT ALGO");
	pline(50);
	printf("\n");
	
	printf("Enter the number of Frames : ");
	scanf("%d",&frameSize);
	printf("Enter the Reference String [Terminate with '-1'] : \n");
	while(1){
		scanf("%d",&r);
		if(r == -1){
			break;
		}
		rString[len] = r;
		len += 1;
	}
	printf("\n");
	
	// empty condition of the page is assigned value -1
	for(int i=0; i<frameSize; i++){
		page[i] = -1;
	}
	
	int ptr = 0;
	int proc = 0;
	while(proc < len){
		int data = rString[proc];
		if(inPage(data,frameSize)){
			printf("\nHIT\n");
		}
		else{
			printf("\nMISS\n");
			pagefault += 1;
			page[ptr] = data;
			for(int k=0; k<frameSize; k++){
				if(k==ptr){
					printf("Page %d : %d *\n",k,page[k]);
				}else{
					printf("Page %d : %d\n",k,page[k]);
				}
			}
			printf("\n");
			ptr += 1;
			if(ptr == frameSize){
				ptr = 0;
			}
		}
		proc += 1;
	}
	
	printf("\n");
	pline(50);
	printf("Total No. of Page Faults = %d\n",pagefault);
	float ratio = (pagefault*100)/len; 
	printf("Page Fault Ratio = %.2f %%\n",ratio);
	pline(50);
	
}





