#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define LL __int64
const LL INF=0x3f3f3f3fLL*0x3f3f3f3fLL;
LL a[100500];
LL sum[100500];
LL Dis(int x,int y){
    LL ret=0;
    ret=sum[y-1]-sum[x-1];
    return ret;
}

int main(){
    int cases,n,m;
    scanf("%d",&cases);
    while (cases--){
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n-1;i++)
            scanf("%I64d",&a[i]);
        sum[0]=0;
        for (int i=1;i<=n-1;i++){
            sum[i]=sum[i-1]+a[i];
        }
        int x,y;
        for (int i=1;i<=m;i++){
            scanf("%d%d",&x,&y);
			cout<<x<<' '<<y<<endl;
            int s=(i-1)%n +1;
            LL ans=INF;
            if (s<=x&&x<=y)
                ans=min(ans,Dis(s,y));
            if (s<=y&&y<=x)
                ans=min(ans,Dis(s,n)+Dis(y,n));
            if (x<=s&&s<=y)
                ans=min(ans,Dis(s,n)+Dis(1,n)+Dis(1,x)+Dis(x,y));
            if (x<=y&&y<=s)
                ans=min(ans,Dis(s,n)+Dis(1,n)+Dis(1,x)+Dis(x,y));
            if (y<=s&&s<=x)
                ans=min(ans,Dis(s,n)+Dis(y,n));
            if (y<=x&&x<=s)
                ans=min(ans,Dis(s,n)+Dis(y,n));
            printf("%I64d\n",ans);
        }
    }
    return 0;
}
