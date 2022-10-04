#include<stdio.h>

#define MAX_SIZE 10

struct PCB{
	int pid;
	int at;
	int bt;
	int ct;
	int tat;
	int wt;
	int visited;
	int order;
}p[MAX_SIZE];

void swap(int* x, int* y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

void sort(int x){
	for(int i=0; i<x; i++){
		for(int j=i+1; j<x; j++){
			if(p[i].bt > p[j].bt){
				swap(&p[i].pid,&p[j].pid);
				swap(&p[i].at,&p[j].at);
				swap(&p[i].bt,&p[j].bt);
			}
		}
	}
}

void sort_order(int x){
	for(int i=0; i<x; i++){
		for(int j=i+1; j<x; j++){
			if(p[i].order > p[j].order){
				swap(&p[i].pid,&p[j].pid);
				swap(&p[i].at,&p[j].at);
				swap(&p[i].bt,&p[j].bt);
				swap(&p[i].ct,&p[j].ct);
				swap(&p[i].tat,&p[j].tat);
				swap(&p[i].wt,&p[j].wt);
			}
		}
	}
}

void pline(int x){
	printf("\n");
	for(int i=0; i<x; i++){
		printf("-");
	}
	printf("\n");
}

void display(int num){
	pline(50);
	printf("  PID\tAT\tBT\tCT\tTAT\tWT\t\n");
	pline(50);
	for(int i=0; i<num; i++){
		printf("  %d\t%d\t%d\t%d\t%d\t%d\t\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
	}
	pline(50);
}

void main(){
	int num;
	
	pline(50);
	printf("\tSJF SCHEDULING ALGORITHM");
	pline(50);
	printf("\n");
	
	printf("Enter the number of Processes : ");
	scanf("%d",&num);
	printf("\n");
	
	for(int i=0; i<num; i++){
		p[i].pid = i+1;
		p[i].visited = 0;
		printf("Arrival Time of Process P%d : ",p[i].pid);
		scanf("%d",&p[i].at);
		printf("Burst Time of Process P%d : ",p[i].pid);
		scanf("%d",&p[i].bt);
		printf("\n");
	}
	
	sort(num);
	
	int i=0;
	int currentTime = 0;
	
	float avg_tat = 0;
	float avg_wt = 0;
	while(i<num){
		int temp = 0;
		for(int j=0; j<num; j++){
			if((p[j].at <= currentTime) && (p[j].visited == 0)){
				temp = 1;
				p[j].visited = 1;
				p[j].order = i;
				currentTime += p[j].bt;
				p[j].ct = currentTime;
				p[j].tat = p[j].ct - p[j].at;
				p[j].wt = p[j].tat - p[j].bt;
				if(p[j].wt < 0){
					p[j].wt = 0;
				}
				avg_tat += p[j].tat;
				avg_wt += p[j].wt;
				i = i+1;
			}
		}
		if(temp==0){
			currentTime += 1;
		}
	
	}
	sort_order(num);
	display(num);
	printf("\n");
	printf("Avg TAT = %.2f \n",avg_tat/num);
	printf("Avg WT  = %.2f \n",avg_wt/num);
	pline(50);
	
}





