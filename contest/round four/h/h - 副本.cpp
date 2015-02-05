#include<stdio.h>
#include<string.h>
//#include<iostream>
//using namespace std;
int father[10010],bf[10010];
int getFather(int x){
	if(father[x]!=x) father[x]=getFather(father[x]);
	return father[x];
}
int main(){
	int i,a,b,fa,fb,n,m,temp,count=0;
	while(scanf("%d%d",&n,&m)!=EOF){
		count=0;
		memset(father,0,sizeof(father));
		memset(bf,0,sizeof(bf));
		for(i=1;i<=n;++i)father[i]=i;
		for(i=0;i<m;++i){
			scanf("%d%d",&a,&b);
			if(a>b)temp=a,a=b,b=temp;
			fa=getFather(a);
			fb=getFather(b);
			if(b!=n){
				father[fb]=fa;	
				if(getFather(b)==1&&bf[b]) ++count;
				//cout<<"1:"<<count<<endl;
			}
			else{
				bf[a]=1;
				if(getFather(a)==1&&bf[a]) ++count;
				//cout<<"2:"<<count<<endl;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
