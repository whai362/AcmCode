#include<iostream>
#include<cstdio>
using namespace std;
#define LL long long
LL a[3],b[3];
int main(){
	int n;
	cin>>n;
	while(n--){
		for(int i=0;i<4;++i) cin>>a[i];
		for(int i=0;i<4;++i) cin>>b[i];
		LL room1=a[0]*b[0];
		LL room2=a[1]*b[1]+a[2]*b[2];
		LL res=(1LL<<60);
		for(int i=0;i<=a[2];++i){
			LL L=0,R=a[3];
			while(L+2<R){
				LL m_l=(L+R)>>1;
				LL m_r=(m_l+R)>>1;
				LL tmp1=max(room1+m_l*b[3],room2+(a[3]-m_l)*b[3]);
				LL tmp2=max(room1+m_r*b[3],room2+(a[3]-m_r)*b[3]);
				if(tmp1<tmp2) R=m_r;
				else L=m_l;
			}
			LL tmp=(1LL<<60);
			for(int i=L;i<=R;++i) tmp=min(tmp,
					max(room1+(LL)i*b[3],room2+(a[3]-i)*b[3]));
			res=min(res,tmp);
			room1+=b[2];
			room2-=b[2];
		}
		cout<<res<<endl;
	}
}
