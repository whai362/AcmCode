#include<iostream>
#include<cstdio>
using namespace std;
#define LL __int64
const int N=50;
const LL MAX=1e18+5;
LL T[55],B[55];

void get_bell(int n){
    B[0]=1;
    B[1]=1;
    T[0]=1;
    for(int i=2;i<=n;++i){
        T[i-1]=B[i-1];
        for(int j=i-2;j>=0;--j)
            T[j]=T[j]+T[j+1];
		if(T[0]>MAX) return ;
        B[i]=T[0];
    }
}
int get_pos(LL k){
	for(int i=0;i<N;++i)
		if(B[i]>k) return i;
}
int ans[55],cnt=0;
int vis[55];
int get_v(int cc,int n){
	for(int i=1;i<=n;++i){
		if(vis[i]==0) --cc;
		if(cc==0) return i;
	}
}
void gao(int n,LL k){
	int pos=get_pos(k);
	for(int i=0;i<n-pos;++i){
		ans[cnt++]=i+1;
		vis[i+1]=1;
		//cout<<i<<' ';
	}
	//cout<<endl;
	--pos;
	if(pos==n && B[pos]==k){
		cnt=n;
		for(int i=0;i<n;++i){
			ans[i]=n-i;
		}
	}
	else{
		while(pos){
			int cc=(k+B[pos]-1)/B[pos];
			cout<<B[pos]<<' '<<k<<' '<<cc<<endl;
			int val=get_v(cc,n);
			ans[cnt++]=val;
			vis[val]=1;
			if(k%B[pos]) k-=(cc-1)*B[pos];
			else k-=cc*B[pos];
			--pos;
		}
		ans[cnt++]=get_v(1,n);
	}
	for(int i=0;i<cnt;++i){
		cout<<ans[i]<<' ';
	}
	cout<<endl;
}
int main(){
	get_bell(50);
	//for(int i=0;i<7;++i){
	//	cout<<B[i]<<' ';
	//}
	//cout<<endl;
	int n;
	LL k;
	cin>>n>>k;
	gao(n,k);
	return 0;
}
