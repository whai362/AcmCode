#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f3f
string name[13]={"Head", "Shoulder", "Neck", "Torso", "Hand", "Wrist", "Waist", "Legs", "Feet", "Finger", "Shield", "Weapon", "Two-Handed"};
int gettype(string s){
	int i;
	for(i=0;i<13;++i){
		if(s==name[i]) return i;
	}
}
struct equ{
	string s;
	int d,t;
}e[305];
struct type{
	int cnt;
	int e[305];
}t[13];
int p[13];
bool cmp(equ e1,equ e2){
	if(e1.d>e2.d || (e1.d==e2.d && e1.t>e2.t)) return 1;
	return 0;
}
bool ok1(){
	int i;
	for(i=0;i<12;++i){
		if(p[i]<t[i].cnt) return 1;
	}
	return 0;
}
int main(){
	int i,n,m,tmp;
	cin>>n>>m;
	memset(t,0,sizeof(t));
	memset(p,0,sizeof(p));
	for(i=0;i<n;++i){
		cin>>e[i].s>>e[i].d>>e[i].t;
	}
	sort(e,e+n,cmp);
	for(i=0;i<n;++i){
		tmp=gettype(e[i].s);
		t[tmp].e[t[tmp].cnt++]=i;
	}
	int sum_d=0,sum_t=0,_min;
	while(ok1()){
		for(i=0;i<13;++i){
			if(t[i].cnt){
				tmp=t[i].e[p[i]];
				sum_d+=e[tmp].d;
				sum_t+=e[tmp].t;
			}
		}
		if(sum_t>=m) break;
		_min=INF;
		for(i=0;i<13;++i){
			if(t[i].cnt){
				if(p[i]+1<t[i].cnt){
					
				}
			}
		}
	}
	return 0;
}
