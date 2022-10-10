#include<stdio.h>
#include<dirent.h>

struct dirent *dptr;

void main(){
	char buff[100];
	DIR *dirp;
	
	printf("Enter the directory name : ");
	scanf("%s",buff);
	
	if((dirp=opendir(buff))==NULL){
		printf("\nDIRECTORY DOESNT EXIST !\n");
		return;
	}
	
	while((dptr=readdir(dirp))){
		printf("%s\n",dptr->d_name);
	}

	closedir(dirp);
	return;
}


