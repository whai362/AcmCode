#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
const int mod=1e9+7;

struct matri{
    int m[33][33];
}em,a[70],r,pre[70],suf[70];

ll N,K;

void iprint(matri x){
    int i,j;
    for(i=0;i<=K;i++){
        for(j=0;j<=K;j++)
        cout<<x.m[i][j]<<' ';
        cout<<endl;
    }
    cout<<endl;
}

matri imulti(matri a,matri b){
    int i,j,k;
    matri c=em;
    for(k=0;k<=K;k++){
        for(i=0;i<=K;i++){
            for(j=0;j<=K;j++){
                ll tmp=((ll)a.m[i][k]*b.m[k][j])%mod;
                c.m[i][j]=(c.m[i][j]+tmp)%mod;
            }
        }
    }
    //iprint(a);iprint(b);iprint(c);
    return c;
}

void ical(){
    int i;
    pre[0]=a[0];
    for(i=1;i<K;i++)
        pre[i]=imulti(pre[i-1],a[i]);
    suf[K-1]=a[K-1];
    for(i=K-2;i>=0;i--)
        suf[i]=imulti(a[i],suf[i+1]);
    a[0]=suf[0];
    for(i=1;i<K;i++){
        a[i]=imulti(suf[i],pre[i-1]);
		iprint(a[i]);
	}
}

void iWork(){
    cin>>N>>K;
    int i,j;
    r=em;
    for(i=0;i<K;i++){
        a[i]=em;
        for(j=0;j<=K;j++)
            a[i].m[j][j]=1;
        for(j=0;j<=K;j++)
            a[i].m[j][i]=1;
        r.m[i][i]=1;
    }
    //iprint(a[1]);
    r.m[K][K]=1;
    //iprint(r);
    for(;N>0;N/=K){
        int tt=N%K;
        if(tt){
            ll pos=0,tmp=N,out=0;
            while(tmp){
				out=(out+(tmp/K));
                pos=(pos+(tmp/=K))%K;
			}
            for(i=tt-1;i>=0;i--){
                r=imulti(a[(pos+i)%K],r);
				//iprint(a[(pos+i)%K]);
                //iprint(r);
            }
        }
        ical();
    }
    int ans=1;
    for(i=0;i<K;i++)
    ans=(ans+r.m[K][i])%mod;
    cout<<ans<<endl;
}

int main(){
    iWork();
    return 0;
}
