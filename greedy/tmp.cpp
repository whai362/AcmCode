#include<iostream>
//#include<cstring>
using namespace std;
struct Data{
	int x,y;
	Data(){
		x=0;
		y=1;
	}
	//Data(int _x,int _y){
	//	x=_x;
	//	y=_y;
	//}
};
int vis[10];
int main(){
	//memset(vis,0,sizeof(vis));
	fill(vis,vis+10,23);
	cout<<vis[9]<<endl;
	//Data a=Data(1,2);
	//cout<<a.x<<' '<<a.y<<endl;
}
