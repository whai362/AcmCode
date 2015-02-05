#include<iostream>
#define p 10000007
using namespace std;
long long a_b_Mod_c(long long a, int b, int c){
    long long result=1;
    int digit[5000];
    int i,k;
    i=0;
    while(b){
        digit[i++]=b%2;
        b>>=1;
    }
    for(k=i-1;k>=0;k--){
        result=(result*result)%c;
        if(digit[k]==1){
            result=(result*a)%c;
        }
    }
    return result;
}
int main(){
    int i,n,k;
	long long ans;
	cin>>n>>k;
	ans=a_b_Mod_c(3,n,k);
	ans=ans-1;
	if(ans<0) ans+=k;
	cout<<ans<<endl;
    return 0;
}

