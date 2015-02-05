#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=5*1e5+5;
char str[N];
bool tab[30];
double sum[N],s[N];
int main(){
	tab['I'-'A']=1;
	tab['E'-'A']=1;
	tab['A'-'A']=1;
	tab['O'-'A']=1;
	tab['U'-'A']=1;
	tab['Y'-'A']=1;
	scanf("%s",str);
	int len=strlen(str);
	sum[len]=1.0/len;
	//cout<<"!!!"<<endl;
	for(int i=len-1;i>0;--i){
		sum[i]=sum[i+1]+double(len-i+1)/i;
	}
	s[1]=1;
	for(int i=2;i<=len;++i){
		s[i]=s[i-1]+1.0/i;
	}
	double ans=0;
	for(int i=0;i<len;++i){
		if(tab[str[i]-'A']){
			int l=i+1;
			int r=len-i;
			if(l>r) swap(l,r);
			ans+=(double)l;
			//cout<<ans<<endl;
			int en=len-l+1;
			if(en>=l+1)
				ans+=(double)l*(s[en]-s[l]);
			//cout<<ans<<endl;
			int tt=max(en+1,l+1);
			if(tt<=len) ans+=sum[tt];
			//cout<<ans<<endl;
		}
	}
	printf("%.7f\n",ans);
	return 0;
}
