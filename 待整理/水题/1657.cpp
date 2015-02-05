#include<stdio.h>
#include<stdlib.h>
#include<math.h>
char p1[5],p2[5];
int main(){
	int t,tmp,tmp1,tmp2;
	scanf("%d",&t);
	while(t--){
		scanf("%s%s",p1,p2);
		if(p1[0]==p2[0]&&p1[1]==p2[1]) printf("%d %d %d %d\n",0,0,0,0);
		else if(p1[0]==p2[0]){
			tmp=abs(p1[1]-p2[1]);
			printf("%d %d %d ",tmp,1,1);
			if(tmp%2==0) printf("%d\n",2);
			else printf("Inf\n");
		}
		else if(p1[1]==p2[1]){
			tmp=abs(p1[0]-p2[0]);
			printf("%d %d %d ",tmp,1,1);
			if(tmp%2==0) printf("%d\n",2);
			else printf("Inf\n");
		}
		else{
			tmp=abs(p1[0]-p2[0]);
			tmp1=abs(p1[1]-p2[1]);
			if(tmp==tmp1)
				printf("%d %d %d %d\n",tmp,1,2,1);
			else{
				if(tmp>tmp1) tmp2=tmp,tmp=tmp1,tmp1=tmp2;
				tmp1=tmp1-tmp;
				printf("%d %d %d ",tmp+tmp1,2,2);
				if(tmp1%2==0) printf("%d\n",2);
				else printf("Inf\n");
			}
		}
	}
	return 0;
}
