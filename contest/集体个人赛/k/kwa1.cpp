#include<iostream>
#include<string.h>
using namespace std;
int f[110],c[110],f1[110],c1[110],imf[110];
int main(){
	int i,j,t,n,p,mp,temp,m,count,sum,max;
	cin>>t;
	while(t--){
		cin>>n;
		m=0,count=0,sum=0,max=0;
		memset(imf,0,sizeof(imf));
		for(i=1;i<n;++i){
			cin>>f[i];
			++imf[f[i]];
			if(imf[f[i]]>max&&f[i]!=1) max=imf[f[i]],mp=f[i];
		}
		for(i=1;i<n;++i) cin>>c[i];
		for(i=1;i<n;++i) if(f[i]!=1) f1[m]=f[i],c1[m++]=c[i];
		if(n%2==0) p=max-(n-1-m)+1;
		else p=max-(n-1-m)+1;
		if(p<=0) cout<<0<<endl;
		else{
			for(i=0;i<m-1;++i)
				for(j=i+1;j<m;++j)
					if(c1[i]>c1[j]){
						temp=c1[i],c1[i]=c1[j],c1[j]=temp;
						temp=f1[i],f1[i]=f1[j],f1[j]=temp;
					}
			for(i=0;i<m;++i){
				sum=sum+c1[i];
				++count;
				if(f1[i]==mp) --p;
				if(count>=p) break;
			}
			cout<<sum<<endl;
		}
	}
	return 0;
	
}
