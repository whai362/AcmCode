#include<iostream>
#include<stdio>
#include<map>
#include<string>
using namespace std;
struct Dt{
	int name_id;
	int score;
	int type;
}a[N];
int buff[N][N];
int ans=0;
void gao(int p,int a,int b,int c,int d,int s){
	if(p
	if(a==4 && b==
}
int main(){
	string name,type;
	int score;
	while(cin>>name){
		cin>>score>>type;
		init();
		name_pool[name]=tot;
		a[tot++]=Dt(tot,score,get_type(type));
		for(int i=2;i<=23;++i){
			cin>>name>>score>>type;
			name_pool[name]=tot;
			a[tot++]=Dt(tot,score,get_type(type));
		}
		int m;
		cin>>m;
		for(int i=0;i<m;++i){
			string name1,name2,score;
			cin>>name1>>name2>>score;
			int name_id1=name_pool[name1];
			int name_id2=name_pool[name2];
			buff[name_id1][name_id2]=buff[name_id2][name_id1]=score;
		}
		gao(0,0,0,0,0,0);
		printf("%d\n",ans);
	}
	return 0;
}
