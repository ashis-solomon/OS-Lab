#include<stdio.h>


#define MAX_SIZE 100

struct PCB{
	int size;
	int allocated;
}process[MAX_SIZE];

struct Block{
	int size;
	int index;
}blocks[MAX_SIZE];


void pline(int x){
	printf("\n");
	for(int i=0; i<x; i++){
		printf("-");
	}
	printf("\n");
}

void main(){
	pline(66);
	printf("        \tFIRST FIT MEMORY ALLOCATION ALGORITHM");
	pline(66);
	
	int bnum,pnum;
	printf("\n");
	printf("Enter the number of blocks : ");
	scanf("%d",&bnum);
	printf("Enter the block sizes : \n");
	for(int i=0; i<bnum; i++){
		scanf("%d",&blocks[i].size);
		blocks[i].index = i;
	}	
	printf("\nEnter the number of processes : ");
	scanf("%d",&pnum);
	printf("Enter the process sizes : \n");
	for(int i=0; i<pnum; i++){
		scanf("%d",&process[i].size);
		process[i].allocated = 0;
	}
	printf("\n");
	pline(66);
	printf("   Process No.\tProcess Size\tBlock No.   Remaining Block Size");
	pline(66);

	for(int i=0; i<pnum; i++){
		for(int j=0; j<bnum; j++){
			if(blocks[j].size >= process[i].size){
				process[i].allocated = 1;
				blocks[j].size -= process[i].size;
				printf("\t%d\t\t%d\t\t%d\t\t%d\n",i+1,process[i].size,blocks[j].index+1,blocks[j].size);
				break;
			}
			if(process[i].allocated == 0 && j>=bnum-1){
				printf("\t%d\t\t%d\tNot Allocated\t\t-\n",i+1,process[i].size);
			}
		}
	}
	
	pline(66);

}









