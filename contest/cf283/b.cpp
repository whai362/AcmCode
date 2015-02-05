#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005,INF=0x3f3f3f3f;
int a[N];
int p1[N],p2[N];
int cnt=0;
struct Ans{
	int t,c1,c2,s;
}ans[N];
bool cmp(Ans a,Ans b){
	if(a.s==b.s) return a.t<b.t;
	return a.s<b.s;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		scanf("%d",&a[i]);
	
	int win=1;
	if(a[n-1]==2) win=2;

	if(a[0]==1) ++p1[0];
	else ++p2[0];
	for(int i=1;i<n;++i){
		p1[i]=p1[i-1];
		p2[i]=p2[i-1];
		if(a[i]==1)
			++p1[i];
		else
			++p2[i];
	}
	for(int i=1;i<=n;++i){
		ans[cnt].t=i;
		int flag=1;
		int j;
		for(j=i-1;j<n;j+=i){
			int t1=p1[j]-p1[j-i];
			int t2=p2[j]-p2[j-i];
			int l=j-i,r=j;
			//cout<<r<<endl;
			while(r<n && t1<i && t2<i){
				r=r+(i-max(t1,t2));
				//cout<<r<<endl;
				t1=p1[r]-p1[l];
				t2=p2[r]-p2[l];
			}
			if(t1>=i)
				++ans[cnt].c1;
			else if(t2>=i)
				++ans[cnt].c2;
			else flag=0;
			j=r;
		}
		if(j==n-1+i && flag) ++cnt;
		else
			ans[cnt].c1=ans[cnt].c2=0;
	}
	int okcnt=0;
	for(int i=0;i<cnt;++i){
		//cout<<ans[i].t<<' '<<ans[i].c1<<' '<<ans[i].c2<<endl;
		if(win==1){
			if(ans[i].c1>ans[i].c2){
				++okcnt;
				ans[i].s=ans[i].c1;
			}
			else ans[i].s=INF;
		}
		else{
			if(ans[i].c2>ans[i].c1){
				++okcnt;
				ans[i].s=ans[i].c2;
			}
			else ans[i].s=INF;
		}
	}
	sort(ans,ans+cnt,cmp);
	printf("%d\n",okcnt);
	for(int i=0;i<okcnt;++i)
		printf("%d %d\n",ans[i].s,ans[i].t);
	return 0;
}
