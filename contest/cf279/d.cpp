#include<iostream>
#include<cstdio>
#include<map>
#include<queue>
using namespace std;
#define LL long long
const int N=1000000;
const int INF=0x3f3f3f3f;
struct Node{
    int l,t;
	Node(){}
	Node(int _l,int _t){
		l=_l;
		t=_t;
	}
};
int a1,b1,a2,b2;
Node l1[N],l2[N],l3[N],l4[N];
struct Data{
    int w,l,t;
    Data(){}
    Data(int _l,int _w,int _t){
        l=_l;
        w=_w;
        t=_t;
    }
};
map< LL,Data > _map;
map< int,int > _vis;
void deal(int n,int &len,Node s[]){
	queue<Node> q;
	_vis.clear();
	Node now;
	s[len]=Node(n,0);
	q.push(s[len]);
	_vis[s[len].l]=1;
	++len;
	while(!q.empty()){
		now=q.front();
		q.pop();
		if(now.l%2==0 && _vis[now.l/2]==0){
			s[len]=Node(now.l/2,now.t+1);
			q.push(s[len]);
			_vis[s[len].l]=1;
			++len;
		}
		if(now.l%3==0 && _vis[now.l/3*2]==0){
			s[len]=Node(now.l/3*2,now.t+1);
			q.push(s[len]);
			_vis[s[len].l]=1;
			++len;
		}
	}
}
int main(){
    scanf("%d%d%d%d",&a1,&b1,&a2,&b2);
    int c1=0,c2=0,c3=0,c4=0;
    deal(a1,c1,l1);
    deal(b1,c2,l2);
    deal(a2,c3,l3);
    deal(b2,c4,l4);
	
	//for(int i=0;i<c1;++i)
	//	cout<<l1[i].l<<endl;
	
    for(int i=0;i<c1;++i){
        for(int j=0;j<c2;++j){
            LL s=(LL)l1[i].l*l2[j].l;
            int t=l1[i].t+l2[j].t;
            if(_map.find(s)==_map.end()){
                _map[s]=Data(l1[i].l,l2[j].l,t);
            }
            else{
                Data tmp=_map[s];
                if(t<tmp.t){
                    _map[s]=Data(l1[i].l,l2[j].l,t);
                }
            }
        }
    }
    int _min=INF,tmp,aa1,ab1,aa2,ab2;
    for(int i=0;i<c3;++i){
        for(int j=0;j<c4;++j){
            LL s=(LL)l3[i].l*l4[j].l;
            int t=l3[i].t+l4[j].t;
            if(_map.find(s)==_map.end())
                continue;
            else{
                Data tmpd=_map[s];
                int tmp=t+tmpd.t;
                if(tmp<_min){
                    _min=tmp;
                    aa1=tmpd.l;
                    ab1=tmpd.w;
                    aa2=l3[i].l;
                    ab2=l4[j].l;
                }
            }
        }
    }
    if(_min==INF) puts("-1");
    else{
    printf("%d\n",_min);
    printf("%d %d\n",aa1,ab1);
    printf("%d %d\n",aa2,ab2);
    }
    return 0;
}
