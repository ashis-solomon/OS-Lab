#include<stdio.h>


int max[10][10],alloc[10][10],avail[10],need[10][10];
int finish[10];

int n,r;

void pline(int x){
	printf("\n");
	for(int i=0; i<x; i++){
		printf("-");
	}
	printf("\n");
}

void input(){
	printf("Enter the number of processes : ");
	scanf("%d",&n);
	printf("Enter the number of resources : ");
	scanf("%d",&r);
	
	printf("\n");
	printf("Enter the MAX matrix : \n");
	for(int i=0; i<n; i++){
		for(int j=0; j<r; j++){
			scanf("%d",&max[i][j]);
		}
	}
	
	printf("\n");
	printf("Enter the ALLOCATION matrix : \n");
	for(int i=0; i<n; i++){
		for(int j=0; j<r; j++){
			scanf("%d",&alloc[i][j]);
		}
	}

	printf("\n");
	printf("Enter the AVAILABLE matrix : \n");
	for(int i=0; i<r; i++){
		scanf("%d",&avail[i]);
	}
	
	// calculate the need matrix
	for(int i=0; i<n; i++){
		for(int j=0; j<r; j++){
			need[i][j] = max[i][j] - alloc[i][j];
		}
	}
	
	// initialize finish matrix
	for(int i=0; i<n; i++){
		finish[i] = 0;
	}
	
}

void display(){
	printf("\n");
	pline(56);
	printf("  PID\t  MAX\t      ALLOC\t  NEED\t     AVAILABLE");
	pline(56);
	
	for(int i=0; i<n; i++){
		printf("  %d\t",i+1);
		
		for(int j=0; j<r; j++){
			printf("%d  ",max[i][j]);
		}
		printf("    ");
		
		for(int j=0; j<r; j++){
			printf("%d  ",alloc[i][j]);
		}
		printf("    ");
		
		for(int j=0; j<r; j++){
			printf("%d  ",need[i][j]);
		}
		printf("    ");
		
		if(i==0){
			for(int j=0; j<r; j++){
				printf("%d  ",avail[j]);
			}
			printf("    ");
		}
		
		
		printf("\n");
	}
}

void calculate(){
	int flag = 1;
	
	while(flag){
		flag=0;
		for(int i=0; i<n; i++){
			int ctr =0;
			for(int j=0; j<r; j++){
				if((finish[i]==0)  && (need[i][j]<=avail[j])){
					ctr++;
					if(ctr==r){
						for(int k=0; k<r; k++){
							avail[k] += alloc[i][k];
							finish[i]=1;
							flag=1;
						}
						printf("P%d -> ",i+1);
						if(finish[i]==1){
							i=n;
						}
					}
				}
			}
		}
	}
	
	int c=0;
	for(int i=0; i<n; i++){
		if(finish[i]==1){
			c++;
		} else {
            printf("P%d->", i);
        }
	}
	
	if (c == n) {
        printf("\n THE SYSTEM IS IN SAFE STATE");
    }
    else {
        printf("\n PROCESS ARE IN DEAD LOCK");
        printf("\n SYSTEM IS IN UNSAFE STATE");
    }
	
}

void main(){
	pline(56);
	printf("\t\tBANKERS ALGORITHM");
	pline(56);

	printf("\n");
	
	input();	
	display();
	calculate();
	}





