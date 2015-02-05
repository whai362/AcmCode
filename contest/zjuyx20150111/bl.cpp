#include<iostream>
using namespace std;
#define LL __int64
//求组合数
LL Ext_gcd(LL a,LL b,LL &x,LL &y){
    if(b==0) { x=1, y=0; return a; }
    LL ret= Ext_gcd(b,a%b,y,x);
    y-= a/b*x;
    return ret;
}

LL Inv(LL a,int m){   ///求逆元
    LL d,x,y,t= (LL)m;
    d= Ext_gcd(a,t,x,y);
    if(d==1) return (x%t+t)%t;
    return -1;
}

LL Cm(LL n, LL m, LL p)  ///组合数学
{
     LL a=1, b=1;
	 if(m>n) return 0;
     while(m)
     {
         a=(a*n)%p;
         b=(b*m)%p;
         m--;
         n--;
     }
     return (LL)a*Inv(b,p)%p;  ///（a/b）%p 等价于 a*（b，p）的逆元
}

int main(){
	int n;
	cin>>n;
	int cnt=0;
	for(int i=0;i<=n;++i){
		int tmp=Cm(n,i,1000000007);
		cout<<tmp<<endl;
		if(tmp%9==0) ++cnt;
	}	
	cout<<cnt<<endl;
}
