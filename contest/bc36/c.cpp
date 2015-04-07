#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=50005;
struct Dt{
	int x,i;
}a[N],q[N];
int ans[N];
int st[N];
bool cmp(Dt a,Dt b){
	return a.x<b.x;
}
void In(int &x){
	char c; x=0; c=getchar();
	int sign=1;
	while(!(c>='0'&&c<='9' || c=='-')) c=getchar();
	if(c=='-') sign=-1,c=getchar();
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	x*=sign;
}

void Out(int x){
	if(x<0){ x=-x; putchar('-');}
	if(x>9)
        Out(x/10);
    putchar(x%10+'0');
}
void print(int n){
	for(int i=0;i<n;++i){
		cout<<st[i]<<' ';
	}
	cout<<endl;
}
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=0;i<n;++i){
			In(a[i].x);
			a[i].i=i;
		}
		sort(a,a+n,cmp);
		for(int i=0;i<m;++i){
			In(q[i].x);
			q[i].i=i;
		}
		sort(q,q+m,cmp);
		memset(st,0,sizeof(st));	
		int cn=1;
		int p=0;
		for(int i=0;i<m;++i){
			int kan=q[i].x;
			//cout<<'h'<<q[i].x<<endl;
			while(p<n && a[p].x<=kan){
				int pos=a[p].i;
				if(pos==0){
					if(n==1) cn=0;
					else{
						if(st[1]==1)
							--cn;
					}
					st[0]=1;
				}
				else if(pos==n-1){
					if(st[pos-1]==1)
						--cn;
					st[pos]=1;
				}
				else{
					if(st[pos-1]==0 && st[pos+1]==0) ++cn;
					else if(st[pos-1]==1 && st[pos+1]==1) --cn;
					st[pos]=1;
				}
				++p;
				//cout<<"cn"<<cn<<endl;
				//print(n);
			}
			ans[q[i].i]=cn;
		}
		for(int i=0;i<m;++i){
			Out(ans[i]);
			puts("");
		}
	}
	return 0;
}
