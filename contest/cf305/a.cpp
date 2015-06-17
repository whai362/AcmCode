#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define LL __int64
const int N=1e6+5;
int t1[N],c1,st1,ha1[N];
int t2[N],c2,st2,ha2[N];
int m;
void predo(LL h,LL x,LL y,int &c,int &st,int ha[],int t[]){
	while(t[h]==-1){
		t[h]=c++;
		h=(x*h+y)%m;
	}
	st=h;
	c=0;
	while(ha[h]==0){
		ha[h]=1;
		c++;
		h=(x*h+y)%m;
	}
}
LL Ext_gcd(LL a,LL b,LL &x,LL &y){
	if(b==0){ x=1,y=0; return a; }
	LL ret=Ext_gcd(b,a%b,y,x);
	y-=a/b*x;
	return ret;
}
int main(){
	int h1,a1;
	int h2,a2;
	int x1,y1;
	int x2,y2;
	scanf("%d",&m);
	scanf("%d%d",&h1,&a1);
	scanf("%d%d",&x1,&y1);
	scanf("%d%d",&h2,&a2);
	scanf("%d%d",&x2,&y2);
	memset(t1,-1,sizeof(t1));
	memset(t2,-1,sizeof(t2));
	c1=c2=0;
	predo(h1,x1,y1,c1,st1,ha1,t1);
	predo(h2,x2,y2,c2,st2,ha2,t2);
	//cout<<c1<<' '<<c2<<endl;
	if(t1[a1]==-1 || t2[a2]==-1) puts("-1");
	else{
		LL tmp1=t1[a1],tmp2=t2[a2];
		if(ha1[a1]==0 && ha2[a2]==0){
			if(tmp1==tmp2) printf("%I64d\n",tmp1);
			else puts("-1");
			return 0;
		}
		else if(ha1[a1]==0 && ha2[a2]){
			if(tmp1>=tmp2 && (tmp1-tmp2)%c2==0) printf("%I64d\n",tmp1);
			else puts("-1");
			return 0;
		}
		else if(ha1[a1] && ha2[a2]==0){
			if(tmp2>=tmp1 && (tmp2-tmp1)%c1==0) printf("%I64d\n",tmp2);
			else puts("-1");
			return 0;
		}
		if(tmp1>tmp2){
			swap(c1,c2);
			swap(tmp1,tmp2);
		}
		LL A=c1;
		LL B=c2;
		LL C=(tmp2-tmp1)%B;
		LL x,y;
		LL d=Ext_gcd(A,B,x,y);
		//cout<<A<<' '<<B<<' '<<C<<endl;
		if(C%d!=0) puts("-1");
		else{
			LL ans=(x*(C/d)%(B/d)+(B/d))%(B/d);
			//cout<<ans<<endl;
			while(ans*c1+tmp1-tmp2<0 || (ans*c1+tmp1-tmp2)%c2!=0){
				//cout<<"!"<<endl;
				ans+=B/d;
			}
			ans=ans*c1+tmp1;
			printf("%I64d\n",ans);
		}
	}
	return 0;
}
