#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

void main(){
	int p = fork();
	
	if(p == 0){
		printf("\nIn Child Process\n");
		printf("Process ID = %d\n",getpid());
		printf("Parent Process ID = %d\n",getppid());
		exit(EXIT_SUCCESS);
	}else if(p > 0){
		printf("\nIn Parent Process\n");
		printf("Process ID = %d\n",getpid());
		wait(NULL);
	}else{
		printf("\nPROCESS CREATION FAILED !\n");
		return;
	}
	
	return;
}
