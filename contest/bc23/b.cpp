/*树状数组加深理解*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define LL __int64
const int N=50005;
int a[N];
LL s[N],ss[N],c[N];
int n;
int lowbit(int x){ return x&-x; }
LL sum(int x){
	LL s=0;
	while(x>0){
		s+=c[x];
		x-=lowbit(x);
	}
	return s;
}
void update(int x){
	while(x<=n){
		++c[x];
		x+=lowbit(x);
	}
}
int read(){
	char c;int ret=0;c=getchar();
	int sign=1;
	while(!(c>='0'&&c<='9' || c=='-')) c=getchar();
	if (c=='-') sign=-1,c=getchar();
	while (c>='0'&&c<='9'){
		ret=(ret<<3)+(ret<<1)+c-'0';
		c=getchar();
	}
	return ret*sign;
}
int main(){
	int T;
	//scanf("%d",&T);
	T=read();
	while(T--){
		//scanf("%d",&n);
		n=read();
		memset(s,0,sizeof(s));
		memset(ss,0,sizeof(ss));
		for(int i=1;i<=n;++i)
			//scanf("%d",&a[i]);
			a[i]=read();
		memset(c,0,sizeof(c));
		for(int i=1;i<=n;++i){
			s[i]=sum(a[i]);
			update(a[i]);
		}
		//for(int i=1;i<=n;++i)
		//	cout<<s[i]<<' ';
		//cout<<endl;
		for(int i=n;i>=1;--i)
			ss[i]=ss[i+1]+(n-i-(a[i]-s[i]-1));
		//for(int i=1;i<=n;++i)
		//	cout<<ss[i]<<' ';
		//cout<<endl;
		LL ans=0;
		for(int i=2;i<=n;++i){
			ans+=s[i]*ss[i+1];
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
