#include<iostream>
#include<tr1/unordered_map>
using namespace std;
using namespace std::tr1;
struct Dt{
	int x,y;
	Dt(){}
	Dt(int _x,int _y){
		x=_x;
		y=_y;
	}
	bool operator < (const Dt a) const{
		if(x==a.x) return y<a.y;
		return x<a.x;
	}
};
int main(){
	Dt a=Dt(1,1);
	unordered_map<Dt,int> mp;
	mp[a]=1;
	return 0;
}
