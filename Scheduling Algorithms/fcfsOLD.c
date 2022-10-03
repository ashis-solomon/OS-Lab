#include<stdio.h>
#include<stdbool.h>

#define MAX_SIZE 10

struct PCB{
	int pid;
	int at;
	int bt;
	int ct;
	int tat;
	int wt;
}p[MAX_SIZE];

void pline(int x){
	for(int i=0; i<x; i++){
		printf("-");
	}
	printf("\n");
}

void display(int num){
	printf("\n");
	pline(50);
	printf("  PID\tAT\tBT\tCT\tTAT\tWT\t\n");
	pline(50);
	for(int i=0; i<num; i++){
		printf("  %d\t%d\t%d\t%d\t%d\t%d\t\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
	}
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sort(int num){
	for(int i=0; i<num; i++){
		for(int j=i+1; j<num; j++){
			if(p[i].at > p[j].at){
				swap(&p[i].pid,&p[j].pid);
				swap(&p[i].at,&p[j].at);
				swap(&p[i].bt,&p[j].bt);
			}
		}
	}
}

void main(){
	int num;
	
	pline(50);
	printf("\tFCFS SCHEDULING ALGORITHM\n");
	pline(50);
	
	printf("Enter the number of processes : ");
	scanf("%d",&num);
	printf("\n");
	
	for(int i=0; i<num; i++){
		printf("Arrival Time of Process %d : ",i+1);
		scanf("%d",&p[i].at);
		printf("Burst Time of Process %d : ",i+1);
		scanf("%d",&p[i].bt);
		p[i].pid = i+1;
		printf("\n");
	}
	
	sort(num);
	int currentTime = 0;
	int i=0;
	float avg_tat = 0;
	while(i<num){
		if(currentTime < p[i].at){
			currentTime++;
		}
		else{
			currentTime = currentTime + p[i].bt;
			p[i].ct = currentTime;
			p[i].tat = p[i].ct - p[i].at;
			p[i].wt = p[i].tat - p[i].bt;
			avg_tat += p[i].tat;
			i = i+1;
		}
	}
	printf("\n");
	display(num);
	pline(50);
	printf("Avg. TAT = %.2f ",avg_tat/num);
}





