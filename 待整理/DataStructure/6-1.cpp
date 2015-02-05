#include<iostream>
using namespace std;
struct ArcNode{
	int adjvex,info;
	ArcNode *nextarc;
};
void addarc(ArcNode *head[],int u,int v){
	ArcNode *p=new ArcNode();
	p->adjvex=v;
	p->nextarc=head[u-1];
	head[u-1]=p;
}
void delarc(ArcNode *head[],int u,int v){
	ArcNode *p,*q;
	for(p=head[u-1];p;p=p->nextarc){
		if(p->nextarc && p->nextarc->adjvex==v){
			q=p->nextarc;
			p->nextarc=q->nextarc;
			delete q;
			break;
		}
	}
}
void create(ArcNode *head[],int n,int e){
	int i,u,v;
	for(i=0;i<n;++i){
		head[i]=NULL;
	}
	for(i=0;i<e;++i){
		cin>>u>>v;
		addarc(head,u,v);
	}
}
void print(ArcNode *head[],int n){
	int i;
	ArcNode *p;
	for(i=0;i<n;++i){
		for(p=head[i];p;p=p->nextarc){
			cout<<i+1<<' '<<p->adjvex<<endl;
		}
	}
}
int main(){
	int n,e,u,v;
	cout<<"输入图: "<<endl;
	cin>>n>>e;
	ArcNode **head=new ArcNode *[n];
	create(head,n,e);
	cout<<"原图: "<<endl;
	print(head,n);
	cout<<"输入要加的边: "<<endl;
	cin>>u>>v;
	addarc(head,u,v);
	cout<<"加边后的图: "<<endl;
	print(head,n);
	cout<<"输入要删的边: "<<endl;
	cin>>u>>v;
	delarc(head,u,v);
	cout<<"删边后的图: "<<endl;
	print(head,n);
	return 0;
}
