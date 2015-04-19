#include<iostream>
#include<cstdio>
using namespace std;
double cal(int x){
	
}
void sf(){
	double left,right;
	double mid,midmid;
	double mid_value,midmid_value;
	left=MIN;
	right=MAX;
	while(left+EPS<right){
		mid=(left+right)/2;
		midmid=(mid+right)/2;
		mid_area=cal(mid);
		midmid_area=cal(midmid);
		if(mid_area>=midmid_area) right=midmid;
		else left=mid;
	}
}
