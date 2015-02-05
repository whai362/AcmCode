#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
struct data{
	int n,step,op,pre,id;
	data(){}
	data(int _n,int _step,int _op,int _pre,int _id){
		n=_n;
		step=_step;
		op=_op;
		pre=_pre;
		id=_id;
	}
};
int cnt=0;
data pool[1000005];
int main(){
	int a,b,c,d,x,y;
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&x,&y);
	cnt=0;
	data da;
	queue<data> q;
	q.push(pool[cnt]=data(x+a,1,1,-1,cnt));
	++cnt;
	q.push(pool[cnt]=data(x/b,1,4,-1,cnt));
	++cnt;
	while(!q.empty()){
		da=q.front();
		q.pop();
		if(da.op==1){
			if(da.step+1<=32){
				q.push(pool[cnt]=data(da.n/b,da.step+1,4,da.id,cnt));
				++cnt;
				q.push(pool[cnt]=data(da.n*c,da.step+1,3,da.id,cnt));
				++cnt;
				q.push(pool[cnt]=data(da.n-d,da.step+1,2,da.id,cnt));
				++cnt;
			}
		}
		else if(da.op==2){
			if(da.n==y) break;
			if(da.step+1<=32){
				q.push(pool[cnt]=data(da.n+a,da.step+1,1,da.id,cnt));
				++cnt;
				q.push(pool[cnt]=data(da.n*c,da.step+1,3,da.id,cnt));
				++cnt;
				q.push(pool[cnt]=data(da.n/b,da.step+1,4,da.id,cnt));
				++cnt;
			}
		}
		else if(da.op==3){
			if(da.n==y) break;
			if(da.step+1<=32){
				q.push(pool[cnt]=data(da.n+a,da.step+1,1,da.id,cnt));
				++cnt;
				q.push(pool[cnt]=data(da.n-d,da.step+1,2,da.id,cnt));
				++cnt;
				q.push(pool[cnt]=data(da.n/b,da.step+1,4,da.id,cnt));
				++cnt;
			}
		}
		if(da.op==4){
			if(da.step+1<=32){
				q.push(pool[cnt]=data(da.n+a,da.step+1,1,da.id,cnt));
				++cnt;
				q.push(pool[cnt]=data(da.n-d,da.step+1,2,da.id,cnt));
				++cnt;
				q.push(pool[cnt]=data(da.n*c,da.step+1,3,da.id,cnt));
				++cnt;
			}
		}
	}
	cout<<da.step<<endl;
	int ans[40],cc=0;
	for(int i=1;i<=da.step;++i){
		ans[cc++]=pool[da.id].op;
		da.id=pool[da.id].pre;
	}
	cout<<endl;
	return 0;
}
