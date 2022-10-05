#include<stdio.h>


#define MAX_SIZE 10

struct PCB{
	int pid;
	int at;
	int bt;
	int ct;
	int tat;
	int wt;
	int rbt;
	int completed;
	int order;
}p[MAX_SIZE];


void pline(int x){
	printf("\n");
	for(int i=0; i<x; i++){
		printf("-");
	}
	printf("\n");
}

void swap(int *x, int *y){
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
				swap(&p[i].rbt,&p[j].rbt);
			}
		}
	}
}

void display(int num){
	printf("\n");
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
	int quant;
	
	pline(50);
	printf("\tROUND ROBIN SCHEDULING ALGORITHM");
	pline(50);
	printf("\n");
	
	printf("Enter the Number of Processes : ");
	scanf("%d",&num);
	printf("Enter the Time Quantum : ");
	scanf("%d",&quant);
	printf("\n");
	for(int i=0; i<num; i++){
		p[i].pid = i+1;
		printf("Arrival Time of Process P%d : ",p[i].pid);
		scanf("%d",&p[i].at);
		printf("Burst Time of Process P%d : ",p[i].pid);
		scanf("%d",&p[i].bt);
		p[i].rbt = p[i].bt;
		printf("\n");
	}
	
	sort(num);
	
	int i=0;
	int currentTime =0;
	
	float avg_tat = 0;
	float avg_wt = 0;
	while(i<num){
		int temp = 0;
		for(int j=0; j<num; j++){
			if(p[j].at <= currentTime && p[j].completed==0){
				if(p[j].rbt <= quant){
					temp = 1;
					currentTime += p[j].rbt;
					p[j].rbt = 0;
					p[j].ct = currentTime;
					p[j].tat = p[j].ct - p[j].at;
					p[j].wt = p[j].tat - p[j].bt;
					if(p[j].wt < 0){
						p[j].wt = 0;
					}
					p[j].completed = 1;
					p[j].order = i;
					avg_tat += p[j].tat;
					avg_wt += p[j].wt;
					i = i+1;
					//break;
				}
				else if(p[j].rbt > quant){
					temp = 1;
					p[j].rbt = p[j].rbt - quant;
					currentTime += quant;
					//break;
				}
			}
		}
		
		if(temp==0){
			currentTime += 1;
		}
	
	}
	
	display(num);
	printf("\n");
	printf("Avg TAT = %.2f\n",avg_tat/num);
	printf("Avg  WT = %.2f\n",avg_wt/num);
	pline(50);
}








