/*poj 2247
  题意：
  找出所有因子中只有2,3,5,7的数，给出n，求出第n个这样的数
  限制：
  1 <= n <= 5842
 */
#include<cstdio>
using namespace std;
int ans[6000];
int Min(int a,int b,int c,int d){
    int ans=a;
    if(b<ans) ans=b;
    if(c<ans) ans=c;
    if(d<ans) ans=d;
    return ans;
}
int main(){
    int i,n,p1,p2,p3,p4,t1,t2,t3,t4;
    p1=p2=p3=p4=1,ans[1]=1;
    for(i=2;i<=5842;i++){
		t1=2*ans[p1];
		t2=3*ans[p2];
		t3=5*ans[p3];
		t4=7*ans[p4];
		ans[i]=Min(t1,t2,t3,t4);
		if(ans[i]==t1) p1++;
		if(ans[i]==t2) p2++;
		if(ans[i]==t3) p3++;
		if(ans[i]==t4) p4++;
    }
    while(scanf("%d",&n) && n){
        if(n%10==1 && n%100!=11) printf("The %dst humble number is %d.\n",n,ans[n]);
        else if(n%10==2 && n%100!=12) printf("The %dnd humble number is %d.\n",n,ans[n]);
        else if(n%10==3 && n%100!=13) printf("The %drd humble number is %d.\n",n,ans[n]);
        else printf("The %dth humble number is %d.\n",n,ans[n]);
    }
    return 0;
}
