#include<cstdio>
#include<cstring>
using namespace std;
#define N 4005
int a[N][N],ca[N][N];
int len,n;
int find(int b[]){
	int count=0,i,tmp=0,front=0;
	for(i=0;i<len;++i){
		tmp+=b[i];
		if(tmp==n) ++count;
		else if(tmp>n){
			tmp-=b[front];
			++front;
		}
	}
	return count;
}

int main(){
	char str[N];
	int ans=0,i,j;
	scanf("%d%s",&n,str);
	len=strlen(str);
	for(i=0;i<len;++i)
	  for(j=i;j<len;++j){
		  ca[i][j]=ca[j][i]=a[i][j]=a[j][i]=(str[i]-'0')*(str[j]-'0');
	  }
	for(int d=0;d<len;++d){
		if(d!=0){
			for(int i=0;i<len-d;++i){
			    for(int j=i+1;j<=d+i+1;++j){
					for(int k=0;k<len;++k){
					    a[i][k]=a[i][k]+a[j][k];
			        }
			    }
			}
		}
		for(int i=0;i<len-d;++i)
		  ans+=find(a[i]);
		for(int i=0;i<len;++i){
			for(int j=0;j<len;++j){
				a[i][j]=ca[i][j];
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
