#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
bool cmp1(char a,char b){ return a>b; };
bool cmp2(char a,char b){ return a<b; };
int main(){
	char n1[10],n2[10],n3[10];
	int a,b,count;
	while(scanf("%s",n1) && n1[0]!='-'){
		printf("N=%s:\n",n1);
		if(n1[0]==n1[1] && n1[0]==n1[2] && n1[0]==n1[3] || strlen(n1)!=4){
			printf("No!!\n");
			continue;
		}
		strcpy(n2,n1);
		strcpy(n3,n1);
		sort(n2,n2+strlen(n2),cmp1);
		sort(n3,n3+strlen(n3),cmp2);
		sscanf(n2,"%d",&a);
		sscanf(n3,"%d",&b);
		printf("%d-%d=%d\n",a,b,a-b);
		count=1;
		while(a-b!=6174 && a!=b){
			sprintf(n2,"%d",a-b);
			strcpy(n3,n2);
			sort(n2,n2+strlen(n2),cmp1);
			sort(n3,n3+strlen(n3),cmp2);
			sscanf(n2,"%d",&a);
			sscanf(n3,"%d",&b);
			printf("%d-%d=%d\n",a,b,a-b);
			++count;
		}
		printf("Ok!! %d times\n",count);
	}
	return 0;
}	
