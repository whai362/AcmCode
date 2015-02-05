#include<stdio.h>
#include<queue>
using namespace std;
int used[100010],step[100010];
int main(){
	int i,n,k,min,s;
	queue<int> q;
	scanf("%d%d",&n,&k);
	if(n>k) printf("%d\n",n-k);
	else{
	min=k-n;
	while(n<k){
		if((n-1)>=0&&!step[n-1]){
			q.push(n-1);
			step[n-1]=step[n]+1;
		}
		if((n+1)<k&&!step[n+1]){
			q.push(n+1);
			step[n+1]=step[n]+1;
		}
		else if((n+1)>=k){
			q.push(n+1);
			s=step[n]+1;
			if(s<min) min=s;
		}
		if(2*n<k&&!step[2*n]){
			q.push(2*n);
			step[2*n]=step[n]+1;
		}
		else if(2*n>=k){
			q.push(2*n);
			s=step[n]+2*n-k+1;
			if(s<min) min=s;
		}
		n=q.front();
		while(used[n]){
			q.pop();
			n=q.front();	
		}
		used[n]=1;
		if(n==k){
			if(step[n]<min) min=step[n];
		}
		q.pop();
	}
	printf("%d\n",min);
	}
	return 0;
}
