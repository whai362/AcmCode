#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define LL __int64
const int N=50005;
struct Dt{
    int a,b;
}a[N];
bool cmp(Dt a,Dt b){
    return a.a<b.a;
}
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
            //scanf("%d",&a[i].a);
			a[i].a=read();
        for(int i=1;i<=n;++i)
            a[i].b=a[a[i].a].a;
        sort(a+1,a+1+n,cmp);
        memset(c,0,sizeof(c));
        //for(int i=1;i<=n;++i){
        //    cout<<a[i].a<<' '<<a[i].b<<endl;
        //}
        for(int i=1;i<=n;++i){
            s[i]=sum(a[i].b);
            update(a[i].b);
        }

        //for(int i=1;i<=n;++i){
        //    cout<<s[i]<<' ';
        //}
        //cout<<endl;
        //
        //cout<<"!"<<endl;

        for(int i=1;i<=n;++i){
            a[i].a=n+1-a[i].a;
            a[i].b=n+1-a[i].b;
        }
        sort(a+1,a+1+n,cmp);
        memset(c,0,sizeof(c));
        LL tmp=0;
        //cout<<"!"<<endl;
        for(int i=1;i<=n;++i){
            tmp+=sum(a[i].b);
            ss[n+1-i]=tmp;
            update(a[i].b);
        }
        
        //for(int i=1;i<=n;++i){
        //    cout<<ss[i]<<' ';
        //}
        //cout<<endl;

        LL ans=0;
        for(int i=2;i<=n;++i){
            ans+=s[i]*ss[i+1];
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
