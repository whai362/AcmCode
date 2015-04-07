/*codeforces 525 E Anya and Cubes
  题意：
  给出n个数a1,a2,...,an，要求从中选出一些数，可以把其中最多k个变成它自己的阶乘，然后选出的数求和，问最后和等于s的选法有多少种。
  限制：
  1 <= n <= 25; 0 <= k <= n; 1<= s <= 1e16; 1 <= ai <= 1e9
  思路：
  一般数据量20~30都会考虑中途相遇法，就是折半暴力。
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include <tr1/unordered_map>
using namespace std;
using namespace std::tr1;

#define LL unsigned __int64
#define MP make_pair
const int N=30;
const LL BEI=(LL)1e16+1;
int a[N];
unordered_map<LL,LL> mp;
LL ans=0;

int n,k;
LL s;
LL f[50];
LL fac(int x){
	if(x<50) return f[x];
	return 0;
}
void predo(int x){
	LL sum=0;
	int p=0;
	int cnt=0;
	int cx=x;
	while(x){
		int ch=x%3;
		if(ch==1) sum+=(LL)a[p];
		else if(ch==2){
			if(fac(a[p])==0) return ;
			else sum+=fac(a[p]);
			++cnt;
			if(cnt>k) return ;
		}
		if(sum>s) return ;
		x/=3;
		++p;
	}
	//cout<<"q"<<' '<<cx<<' '<<sum<<' '<<cnt<<endl;
	//++mp[MP(sum,cnt)];
	//cout<<BEI*(cnt+1)+sum<<endl;
	++mp[BEI*(cnt+1)+sum];
	if(sum==s) ++ans;
}
void gao(int n1,int x){
	LL sum=0;
	int p=n1;
	int cnt=0;
	int cx=x;
	while(x){
		int ch=x%3;
		if(ch==1) sum+=(LL)a[p];
		else if(ch==2){
			if(fac(a[p])==0) return ;
			else sum+=fac(a[p]);
			++cnt;
			if(cnt>k) return ;
		}
		if(sum>s) return ;
		x/=3;
		++p;
	}
	//cout<<cx<<' '<<sum<<' '<<cnt<<endl;
	if(s==sum) ++ans;
	else{
		for(int i=0;i<=k-cnt;++i)
			ans+=mp[BEI*(i+1)+(s-sum)];
	}
}
int main(){
	scanf("%d%d%I64u",&n,&k,&s);
	memset(f,0,sizeof(f));
	f[0]=1;
	for(int i=1;i<50;++i){
		f[i]=f[i-1]*i;
		//cout<<f[i]<<endl;
		if(f[i]>s){
			f[i]=0;
			break;
		}
	}
	for(int i=0;i<n;++i)
		scanf("%d",&a[i]);
	int n1=n/2;
	int lim1=1;
	for(int i=0;i<n1;++i) lim1*=3;
	for(int i=0;i<lim1;++i){
		predo(i);
	}
	int n2=n-n1;
	int lim2=1;
	for(int i=0;i<n2;++i) lim2*=3;
	for(int i=1;i<lim2;++i){
		gao(n1,i);
	}
	printf("%I64u\n",ans);
	return 0;
}
