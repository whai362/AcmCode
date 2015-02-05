#include<iostream>
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
	while(cin>>n>>k){
		ans=a_b_Mod_c(2,n,p);
		if(n%2)
			ans=(((ans*k)%p*k)%p*2)%p;
		else ans=((ans*k)%p*k)%p;
		cout<<ans<<endl;
	}
    return 0;
}


