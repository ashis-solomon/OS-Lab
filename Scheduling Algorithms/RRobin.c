#include<stdio.h>


#define MAX_SIZE 100

struct PCB{
	int index;
	int at;
	int bt;
	int rbt;
	int ct;
	int tat;
	int wt;
	int completed;
}p[MAX_SIZE];

int num;
int quant;

void pline(int x){
	printf("\n");
	for(int i=0; i<x; i++){
		printf("-");
	}
	printf("\n");
}

void display(int num){
	pline(50);
	printf("  PID\tAT\tBT\tCT\tTAT\tWT\t");
	pline(50);
	for(int i=0; i<num; i++){
		printf("  %d\t%d\t%d\t%d\t%d\t%d\t\n",p[i].index,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
	}
	pline(50);
}

void main(){
	pline(50);
	printf("\tROUND ROBIN SCHEDULING ALGORITHM");
	pline(50);
	
	printf("\n");
	printf("Enter the number of processes : ");
	scanf("%d",&num);
	printf("Enter the time quantum : ");
	scanf("%d",&quant);
	printf("\n");
	for(int i=0; i<num; i++){
		p[i].index = i;
		p[i].completed = 0;
		printf("Arrival time of process %d : ",p[i].index+1);
		scanf("%d",&p[i].at);
		printf("Burst time of process %d : ",p[i].index+1);
		scanf("%d",&p[i].bt);
		p[i].rbt = p[i].bt;
		printf("\n");
	}
	
	int currentTime=0;
	int proc = num;
	int i=0;
	int flag=0;
	float total_tat=0, total_wt=0;
	
	while(proc != 0){
		if(p[i].rbt<=quant && p[i].rbt>0){
			currentTime += p[i].rbt;
			p[i].rbt = 0;
			flag = 1;
			
		}else if(p[i].rbt>quant){
			currentTime += quant;
			p[i].rbt -= quant;
		}
		
		if(p[i].rbt==0 && flag==1){
			p[i].ct = currentTime;
			p[i].tat = p[i].ct - p[i].at;
			p[i].wt = p[i].tat - p[i].bt;
			total_tat += p[i].tat;
			total_wt += p[i].wt;
			flag=0;
			proc -= 1;
		}
		
		if(i==num-1){
			i=0;
		}else if(p[i+1].at <= currentTime){
			i++;
		}else{
			i=0;
		}
		
	}
	
	display(num);
	
	printf("Avg TAT = %.2f \n",total_tat/num);
	printf("Avg WT = %.2f ",total_wt/num);
	pline(50);
	
}







