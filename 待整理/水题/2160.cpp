#include<stdio.h>
#include<algorithm>
using namespace std;
struct line{
	int w,h;
};
bool cmp(line a,line b){
	if(a.w<b.w) return 1;
	else if(a.w==b.w&&a.h<b.h) return 1;
	return 0;
}

int main(){
	int i,a,b,tmp,flag=1;
	line l[6];
	for(i=0;i<6;++i){
		scanf("%d%d",&a,&b);
		if(a>b) tmp=a,a=b,b=tmp;
		l[i].w=a;
		l[i].h=b;
	}
	sort(l,l+6,cmp);
	for(i=0;i<3;++i) if(l[i].w!=l[i+1].w){ flag=0; break; }
	if(flag)
	  for(i=2;i<5;++i) if(l[i].h!=l[i+1].h){ flag=0; break; }
	if(flag)
	  for(i=0;i<2;++i) if(l[i].h!=l[i+4].w){ flag=0; break; }
	if(flag) printf("POSSIBLE\n");
	else printf("IMPOSSIBLE\n"); 
	return 0;
}
