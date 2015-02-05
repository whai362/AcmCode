#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
struct stu{
	int s,c;
}s[100005];
bool cmp(stu a,stu b){
	return a.s>b.s;
}
int main(){
	int i,j,n,c,f,t,T,s1,s2;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&c,&f);
		priority_queue< int,vector<int>,greater<int> > minh2;
		priority_queue< int,vector<int>,greater<int> > tmp;
		priority_queue< int,vector<int>,less<int> > maxh1;
		priority_queue< int,vector<int>,less<int> > maxh2;
		s1=s2=0;
		for(i=0;i<c;++i)
		  scanf("%d%d",&s[i].s,&s[i].c);
		sort(s,s+c,cmp);
		t=(n-1)/2;
		for(i=0;i<t;++i){
			s1+=s[i].c;
			maxh1.push(s[i].c);
		}
		for(i=t+1;i<c;++i){
			minh2.push(s[i].c);
		}
		for(i=0;i<t;++i){
			s2+=minh2.top();
			maxh2.push(minh2.top());
			minh2.pop();
		}
		for(i=t;i<c-t-1;++i){
			if(s1+s2+s[i].c<=f) break;
			else{
				if(s[i].c<maxh1.top()){
					s1=s1-maxh1.top()+s[i].c;
					maxh1.pop();
					maxh1.push(s[i].c);
				}
				if(s[i+1].c<maxh2.top()){
					if(!tmp.empty() && minh2.top()==tmp.top()){
						while(!tmp.empty() && minh2.top()==tmp.top()){
							minh2.pop();
							tmp.pop();
						}
					}
					s2=s2-s[i+1].c+minh2.top();
					maxh2.push(minh2.top());
					minh2.pop();
				}
				else{
					tmp.push(s[i+1].c);
				}
			}
		}
		if(s1+s2+s[i].c<=f)
		  printf("%d\n",s[i].s);
		else printf("-1\n");
	}
	return 0;
}

