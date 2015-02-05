#include<cstdio>
using namespace std;
int hash[6000];
int Min(int a,int b,int c,int d){
    int ans=2000000001;
    if(a<ans) ans=a;
    if(b<ans) ans=b;
    if(c<ans) ans=c;
    if(d<ans) ans=d;
    return ans;
}
int main(){
    int i,n,p1,p2,p3,p4,t1,t2,t3,t4;
    p1=p2=p3=p4=1,hash[1]=1;
    for(i=2;i<=5842;i++){
		t1=2*hash[p1];
		t2=3*hash[p2];
		t3=5*hash[p3];
		t4=7*hash[p4];
		hash[i]=Min(t1,t2,t3,t4);
		if(hash[i]==t1) p1++;
		if(hash[i]==t2) p2++;
		if(hash[i]==t3) p3++;
		if(hash[i]==t4) p4++;
    }
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
        if(n%10==1 && n%100!=11) printf("The %dst number is %d.\n",n,hash[n]);
        else if(n%10==2 && n%100!=12) printf("The %dnd number is %d.\n",n,hash[n]);
        else if(n%10==3 && n%100!=13) printf("The %drd number is %d.\n",n,hash[n]);
        else printf("The %dth number is %d.\n",n,hash[n]);
    }
    return 0;
}

