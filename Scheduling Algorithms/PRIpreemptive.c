/*
	Program: Priority Scheduling 
	Mode: Preemptive
*/

#include<stdio.h>


#define MAX_SIZE 10

struct PCB{
	int pid;
	int prio;
	int at;
	int bt;
	int ct;
	int tat;
	int wt;
	int rbt;
	int completed;
}p[MAX_SIZE];


void pline(int x){
	printf("\n");
	for(int i=0; i<x; i++){
		printf("-");
	}
	printf("\n");
}

void display(int num){
	pline(50);
	printf(" PID\tPRIO\tAT\tBT\tCT\tTAT\tWT\t\n");
	pline(50);
	for(int i=0; i<num; i++){
		printf(" %d\t%d\t%d\t%d\t%d\t%d\t%d\t\n",p[i].pid,p[i].prio,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
	}
	pline(50);
}

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

void sort(int num){
	for(int i=0; i<num; i++){
		for(int j=i+1; j<num; j++){
			if(p[i].)
		}
	}
}

void main(){
	int num;
	int quant;
	
	pline(50);
	printf("    PRIORITY [PREEMPTIVE] SCHEDULING ALGORITHM");
	pline(50);
	printf("\n");
	
	printf("Enter the number of Processes : ");
	scanf("%d",&num);
	printf("Enter the Time Quantum : ");
	scanf("%d",&quant);
	printf("\n");
	
	for(int i=0; i<num; i++){
		p[i].pid = i+1;
		printf("Priority of Process P%d : ",p[i].pid);
		scanf("%d",&p[i].prio);
		printf("Arrival Time of Process P%d : ",p[i].pid);
		scanf("%d",&p[i].at);
		printf("Burst Time of Process P%d : ",p[i].pid);
		scanf("%d",&p[i].bt);
		printf("\n");
	}
	
	display(num);
}










