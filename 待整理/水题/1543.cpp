#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct cube{
	char a,b,c,d;
}cu[1000000];
char hash[102*102*102+1];

bool cmp(cube c1,cube c2){
	if(c1.a<c2.a) return 1;
	else if(c1.a==c2.a){
	  if(c1.b<c2.b) return 1;
	  else if(c1.b==c2.b){
		  if(c1.c<c2.c) return 1;
		  else if(c1.c==c2.c){
			  if(c1.d<c2.d) return 1;
			  else return 0;
		  }
	  }
	}
	return 0;
}

int pow(int x,int n){
	int i,ans=1;
	for(i=0;i<n;++i)
		ans*=x;
	return ans;
}

int main(){
	int count,i,j,k,n,tmp1,tmp2;
	scanf("%d",&n);
	count=0;
	memset(hash,0,sizeof(hash));
	for(i=0;i<102;++i)
		hash[pow(i,3)]=i;
	tmp1=pow(n,3);
	for(i=2;i<n;++i)
		for(j=i+1;j<n;++j)
			for(k=j+1;k<n;++k){
				tmp2=pow(i,3)+pow(j,3)+pow(k,3);
				if(hash[tmp2] && tmp2<=tmp1) cu[count].a=hash[tmp2],cu[count].b=i,cu[count].c=j,cu[count++].d=k;
			}
	sort(cu,cu+count,cmp);
	for(i=0;i<count;++i)
	  printf("Cube = %d, Triple = (%d,%d,%d)\n",(int)cu[i].a,(int)cu[i].b,(int)cu[i].c,(int)cu[i].d);
	return 0;
}
