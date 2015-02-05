#include<stdio.h>
#include<math.h>
int main(){
	int count=0,i,j,n,num,m,rank,temp;
	scanf("%d",&n);
	for(i=0;i<n;++i){
		count=0;
		scanf("%d%d",&rank,&num);
		m=sqrt(2*num);
		for(j=2;j<=m;++j){
			temp=(1+j)*j/2;
			if((num-temp)%j==0) ++count;
		} 
		printf("%d %d\n",rank,count);
	}
	return 0;
}

