#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	vector<int> vec1;
	vector<int> vec2;
	vector<int> vec12;
	for(int i=0;i<=4;++i)
		vec1.push_back(4-i);
	for(int i=3;i<=5;++i)
		vec2.push_back(i);
	sort(vec1.begin(),vec1.end());
	sort(vec2.begin(),vec2.end());
	set_intersection(vec1.begin(),vec1.end(),
			vec2.begin(),vec2.end(),
			inserter(vec12,vec12.begin()));	//要另外开一个vector
	for(int i=0;i<vec12.size();++i)
		cout<<vec12[i]<<' ';
	cout<<endl;
	return 0;
}
