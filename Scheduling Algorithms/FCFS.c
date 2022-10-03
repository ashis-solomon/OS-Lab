#include<stdio.h>


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
	printf("\n");
	for(int i=0; i<x; i++){
		printf("-");
	}
	printf("\n");
}

void display(int num){
	printf("\n");
	pline(50);
	printf("   PID\tAT\tBT\tCT\tTAT\tWT\t\n");
	pline(50);
	for(int i=0; i<num; i++){
		printf("   %d\t%d\t%d\t%d\t%d\t%d\t\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
	}
	pline(50);
}

void swap(int* x, int* y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

void sort(int x){
	for(int i=0; i<x; i++){
		for(int j=i+1; j<x; j++){
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
	printf("\tFCFS SCHEDULING ALGORITHM");
	pline(50);
	printf("\n");
	
	printf("Enter the number of processes : ");
	scanf("%d",&num);
	printf("\n");
	
	for(int i=0; i<num; i++){
		p[i].pid = i+1;
		printf("Arrival Time of Process P%d : ",p[i].pid);
		scanf("%d",&p[i].at);
		printf("Burst Time of Process P%d : ",p[i].pid);
		scanf("%d",&p[i].bt);
		printf("\n");
	}
	
	sort(num);
	int currentTime = 0;
	
	int i=0;
	float avg_tat = 0;
	float avg_wt = 0;
	while(i<num){
		if(currentTime < p[i].at){
			currentTime += 1;
		}else{
			currentTime += p[i].bt;
			p[i].ct = currentTime;
			p[i].tat = currentTime - p[i].at;
			p[i].wt = p[i].tat - p[i].bt;
			if(p[i].wt < 0){
				p[i].wt = 0;
			}
			avg_tat += p[i].tat;
			avg_wt += p[i].wt;
			i = i+1;
		}
	}
	display(num);
	printf("\n");
	printf("Avg TAT = %.2f",avg_tat/num);
	printf("\n");
	printf("Avg WT  = %.2f",avg_wt/num);
	pline(50);
}







