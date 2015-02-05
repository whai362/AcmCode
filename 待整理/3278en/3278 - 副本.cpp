#include<stdio.h>
#include<queue>
//#include<iostream>
using namespace std;
int used[100010],step[100010];
int main(){
	int i,n,k,min,s;
	queue<int> q;
	scanf("%d%d",&n,&k);
	min=k-n;
	q.push(n);
	while(!q.empty()){
		n=q.front();
		while(used[n]){
			q.pop();
			n=q.front();	
		}
		used[n]=1;
		q.pop();
		if(n==k){
			if(step[n]<min) min=step[n];
		//	cout<<"min"<<min<<endl;	
		}
		
		if((n-1)>=0&&!step[n-1]){
			q.push(n-1);
			step[n-1]=step[n]+1;
		//	cout<<n-1<<':'<<step[n-1]<<endl;
		}
		if((n+1)<k&&!step[n+1]){
			q.push(n+1);
			step[n+1]=step[n]+1;
		//	cout<<n+1<<':'<<step[n+1]<<endl;
		}
		else if((n+1)>=k){
			s=step[n]+1;
			if(s<min) min=s;
		//	cout<<n+1<<':'<<s<<endl;
		//	cout<<"min"<<min<<endl;
		}
		if(2*n<k&&!step[2*n]){
			q.push(2*n);
			step[2*n]=step[n]+1;
		//	cout<<2*n<<':'<<step[n+1]<<endl;
		}
		else if(2*n>=k){
			s=step[n]+2*n-k+1;
			if(s<min) min=s;
		//	cout<<2*n<<':'<<s<<endl;
		//	cout<<"min"<<min<<endl;
		}
	}
	printf("%d\n",min);
}
