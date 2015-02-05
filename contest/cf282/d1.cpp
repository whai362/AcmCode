#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define LL __int64
const int N = 1000005,
	  MOD=1000000007;
int next[N];
bool en[N];
char S[N], T[N];
int slen, tlen;

LL dp[N],sum[N],ss[N];

void getNext(){
	int i,j;
	i=0;
	j=next[0]=-1;
	while(i<tlen){
		if(j==-1 || T[i]==T[j])
			next[++i]=++j;
		else
			j=next[j];
	}
}
void predo(){
    int i, j = 0;

    if(slen == 1 && tlen == 1){
        if(S[0] == T[0])
			en[0]=true;
    }
    getNext();
    for(i = 0; i < slen; i++){
        while(j > 0 && S[i] != T[j])
            j = next[j];
        if(S[i] == T[j])
            j++;
        if(j == tlen){
			en[i] = true;
            j = next[j];
        }
    }
	//for(i = 0;i< slen; i++){
	//	cout<<en[i]<<' ';
	//}
	//cout<<endl;
}
int main(){
	scanf("%s%s",S,T);
	slen = strlen(S);
	tlen = strlen(T);
	//cout<<slen<<' '<<tlen<<endl;
	predo();
	for(int i=0;i<slen;++i){
        if(i<tlen-1){
            if(i==0)
                dp[i]=0;
            else
                dp[i]=dp[i-1];
        }
        else{
            if(en[i]){
                if(i==0 || i==tlen-1)
                    dp[i]=i-tlen+2;
                else{
					//cout<<'!'<<i-tlen<<endl;
                    dp[i]=ss[i-tlen]+i-tlen+2;
				}
            }
            else{
                if(i==0)
                    dp[i]=0;
                else
                    dp[i]=dp[i-1];
            }
        }
        if(i==0){
            sum[i]=dp[i];
            ss[i]=dp[i];
        }
        else{
            sum[i]=(sum[i-1]+dp[i])%MOD;
            ss[i]=(ss[i-1]+sum[i])%MOD;
        }
		//cout<<dp[i]<<' '<<sum[i]<<' '<<sum[slen-1]<<endl;
    }
    printf("%I64d\n",sum[slen-1]);
    return 0;
}

