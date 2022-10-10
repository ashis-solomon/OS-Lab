#include<stdio.h>


#define MAX_SIZE 100


struct PCB{
	int pid;
	int pri;
	int at;
	int bt;
	int ct;
	int tat;
	int wt;
	int visited;
	int order;
}p[MAX_SIZE];


int num;

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

void sort(int num){
	for(int i=0; i<num; i++){
		for(int j=i+1; j<num; j++){
			if(p[i].pri > p[j].pri){
				swap(&p[i].pid,&p[j].pid);
				swap(&p[i].pri,&p[j].pri);
				swap(&p[i].at,&p[j].at);
				swap(&p[i].bt,&p[j].bt);
				swap(&p[i].ct,&p[j].ct);
				swap(&p[i].tat,&p[j].tat);
				swap(&p[i].wt,&p[j].wt);
				swap(&p[i].visited,&p[j].visited);
			}
		}
	}

}

void sort_order(int num){
	for(int i=0; i<num; i++){
		for(int j=i+1; j<num; j++){
			if(p[i].order > p[j].order){
				swap(&p[i].pid,&p[j].pid);
				swap(&p[i].pri,&p[j].pri);
				swap(&p[i].at,&p[j].at);
				swap(&p[i].bt,&p[j].bt);
				swap(&p[i].ct,&p[j].ct);
				swap(&p[i].tat,&p[j].tat);
				swap(&p[i].wt,&p[j].wt);
				swap(&p[i].visited,&p[j].visited);
				swap(&p[i].order,&p[j].order);
			}
		}
	}

}

void display(int num){
	pline(55);
	printf("  PID\tPRI\tAT\tBT\tCT\tTAT\tWT\t");
	pline(55);
	for(int i=0; i<num; i++){
		printf("   %d\t%d\t%d\t%d\t%d\t%d\t%d\t\n",p[i].pid+1,p[i].pri,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
	}
}

void main(){
	pline(55);
	printf("\t  PRIORITY SCHEDULING ALGORITHM");
	pline(55);
	
	
	printf("\n");
	printf("Enter the number of processes : ");
	scanf("%d",&num);
	printf("\n");
	for(int i=0; i<num; i++){
		p[i].pid = i;
		p[i].visited = 0;
		printf("Priority of Process %d [lower number has higher priority] : ",p[i].pid+1);
		scanf("%d",&p[i].pri);
		printf("Arrival Time of Process %d : ",p[i].pid+1);
		scanf("%d",&p[i].at);
		printf("Burst Time of Process %d : ",p[i].pid+1);
		scanf("%d",&p[i].bt);
		printf("\n");
	}

	sort(num);
	
	int i=0;
	int currentTime=0;
	int flag=0;
	float total_tat=0,total_wt=0;
	while(i<num){
		flag=0;
		for(int j=0; j<num; j++){
			if(p[j].at <=currentTime && p[j].visited==0){
				flag=1;
				p[j].visited = 1;
				currentTime += p[j].bt;
				p[j].ct = currentTime;
				p[j].tat = p[j].ct - p[j].at;
				p[j].wt = p[j].tat - p[j].bt;
				total_tat += p[j].tat;
				total_wt += p[j].wt;
				if(p[j].wt < 0){
					p[j].wt = 0;
				}
				p[j].order = i;
				i+=1;
			}
		}
		
		if(flag==0){
			currentTime += 1;
		}
		
	}
	sort_order(num);
	display(num);
	pline(55);
	
	printf("Avg TAT = %.2f \n",total_tat/num);
	printf("Avg WT = %.2f ",total_wt/num);
	pline(55);
}













