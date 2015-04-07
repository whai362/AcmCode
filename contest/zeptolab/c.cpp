#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
const int N=1000000;
#define LL __int64
map<LL,int> mp;
int a[N],r[N],cnt;
int main(){
	LL c,Hr,Hb,Wr,Wb;
	cin>>c>>Hr>>Hb>>Wr>>Wb;
	if(Wr<Wb){
		swap(Hr,Hb);
		swap(Wr,Wb);
	}
	cnt=0;
	LL lim=min(Wb+1,c/Wr+1);
	//cout<<lim<<endl;
	for(int i=0;i<=lim;++i){
		LL tmp=((c-Wr*i)%Wb+Wb)%Wb;
		//cout<<tmp<<endl;
		if(mp.find(tmp)==mp.end()){
			r[cnt]=tmp;
			a[cnt++]=i;
			mp[tmp]=1;
		}
	}
	LL ans=0;
	if(Hr*Wb<=Hb*Wr){
		for(int i=0;i<cnt;++i){
			LL tmp=Wr*a[i];
			if(tmp>c) continue;
			ans=max(ans,Hr*a[i]+(c-tmp)/Wb*Hb);
		}
	}
	else{
		for(int i=0;i<cnt;++i){
			LL d=__gcd(Wr,Wb);
			LL nn=(c/Wr-a[i])/(Wb/d);
			nn=nn*Wb/d+i;
			LL tmp=nn*Wr;
			if(tmp>c) continue;
			ans=max(ans,Hr*nn+(c-tmp)/Wb*Hb);
		}
	}
	cout<<ans<<endl;
	return 0;
}
