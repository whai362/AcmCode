#include<stdio.h>
int a_b(int a,int b){
    int result=1;
	int digit[32],i,k;
    i=0;
    while(b){
        digit[i++]=b%2;
        b>>=1;
    }
    for(k=i-1;k>=0;k--){
        result=result*result;
        if(digit[k]==1){
            result=result*a;
        }
    }
    return result;
}
int main(){
	int b,i,n,tmp1,tmp2;
	while(scanf("%d%d",&b,&n)&&(b||n)){
		i=1,tmp1=1;
		while(tmp1<b){
			++i;
			tmp1=a_b(i,n);
		}
		tmp2=a_b(i-1,n);
		if(tmp1-b<b-tmp2) printf("%d\n",i);
		else printf("%d\n",i-1);
	}
	return 0;
}
