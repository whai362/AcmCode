#include<stdio.h>
int main(){
	int i,tmp=2;
	double sum=2.5;
	printf("n e\n- -----------\n0 1\n1 2\n2 2.5\n");
	for(i=3;i<10;++i){
		tmp=tmp*i;
		sum=sum+1.0/tmp;
		printf("%d %.9f\n",i,sum);
	}
	return 0;
}
