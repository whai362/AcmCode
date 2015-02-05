#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int main(){
    int n,k,sum=0;
    scanf("%d%d",&n,&k);
    for(int i=0; i<n; i++){
        int l,r;
        scanf("%d%d",&l,&r);
        sum+=r-l+1;
    }
    if(sum%k==0) printf("0\n");
    else printf("%d\n",k-sum%k);
    return 0;
}

