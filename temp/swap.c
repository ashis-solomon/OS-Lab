#include<stdio.h>


void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

void main(){
	int a=0, b=1;
	printf("a = %d .... b = %d\n",a,b);
	swap(&a,&b);
	printf("a = %d .... b = %d\n",a,b);

}
