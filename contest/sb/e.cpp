#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int T;
	int a,b,c,d,h1,h2,ch1,ch2;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&h1,&h2);
		ch1=h1,ch2=h2;
		int hc=h2/a;
		if(h2%a) ++hc;
		if(h1 > (hc-1)*d ) puts("YES");
		else{
			int flag=0;
			while(h1>2*c){
				h2-=b;
				h1-=c;
				if(h2<=0){
					flag=1;
					break;
				}
				h1-=2*d;
				if(h1<=0){
					flag=0;
					break;
				}
				hc=h2/a;
				if(h2%a) ++hc;
				if(h1 > (hc-1)*d ){
					flag=1;
					break;
				}
			}
			//cout<<h1<<' '<<h2<<endl;
			if(flag) puts("YES");
			else{
				while(ch1>2*c){
					ch1-=d;
					ch2-=a;
					if(ch1>2*c && ch2<=b){
						flag=1;
						break;
					}
				}
				if(flag) puts("YES");
				else puts("NO");
			}
		}
	}
	return 0;
}
