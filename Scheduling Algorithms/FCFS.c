#include<stdio.h>

#define MAX_SIZE 100

struct PCB{
	int pid;
	int at;
	int bt;
	int ct;
	int tat;
	int wt;
}p[MAX_SIZE];

void pline(int x){
	printf("\n");
	for(int i=0; i<x;i++){
		printf("-");
	}
	printf("\n");
}

void display(int x){
	printf("\n");
	pline(50);
	printf("  PID\tAT\tBT\t");
	pline(50);
	for(int i=0; i<x; i++){
		printf("  %d\t%d\t%d\t\n",p[i].pid,p[i].at,p[i].bt);
	}
	pline(50);
}

void sort(int arr, int x){

}

void fcfs(int num){
	

}

void main(){
	int num;

	pline(50);
	printf("\tFCFS SCHEDULING ALGORITHM");
	pline(50);
	printf("\n");
	
	printf("Enter the number of processes : ");
	scanf("%d",&num);
	printf("\n");
	
	for(int i=0; i<num; i++){
		printf("Arrival Time of Process %d : ",i+1);
		scanf("%d",&p[i].at);
		printf("Burst Time of Process %d : ",i+1);
		scanf("%d",&p[i].at);
		p[i].pid = i;
		printf("\n");
	}
	
	fcfs(num);
	
	display(num);
}












