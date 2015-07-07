//系统自带的反序
#include<algorithm>
int a[10];
int n;
reverse(a,a+n);

//各种好用的stl
//1. 全排列
#include<algorithm>
int a[n];
sort(a,a+n);
print(a);
while(next_permutation(a,a+len)){
	print(a);
}

//2. set set是用红黑树实现的
#include<set>
set<int> _set;
_set.clear();
if(_set.find(tmp)!=_set.end()){
	//元素在_set中
}
else{
	//元素不在_set中
}
_set.insert(x);	//把x插入_set中
//遍历整个set
set<int>::iterator it=_set.begin();
for(;it!=_set.end();it++) cout<<*it<<" ";
//删除
_set.erase(10);
//获取set大小
int sz=_set.size();
//获取指定元素及其前一个元素
set<int>::iterator it=_set.find(10);
cout<<*(--it)<<endl;

//3. map
#include<iostream>
#include<map>
using namespace std;
#define mp make_pair
//map<string,int> _map;
hash_map<string,int> _map;
int main(){
	_map.clear();

	//插入元素的两种方法
	_map.insert(mp("aab",1));
	_map["aaa"]=3;
	_map["zzz"]=1;
	_map["ccc"]=10;

	if(_map.find("aac")!=_map.end()){
		//元素在_map中
		cout<<_map["aaa"]<<endl;
	}
	else{
		//元素不在_map中
		//元素不在，默认值为0
		cout<<_map["aac"]<<endl;
	}
	
	//变量map,按键值排序
	map<string,int>::iterator it;
    for(it=_map.begin();it!=_map.end();++it)
        cout<<"key: "<<it->first<<" value: "<<it->second<<endl;

	//删除
	_map.erase(10);
	
	//大小
	int sz=_map.size();

	//获取指定元素及其前一个元素
	it=_map.find("zzz");
	--it;
	cout<<it->first<<' '<<it->second<<endl;
}

//4.双向队列 deque
#include <deque>
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
	deque<int> ideq(20); //Create a deque ideq with 20 elements of default value 0
	deque<int>::iterator pos;
	int i;

	//使用assign()赋值  assign在计算机中就是赋值的意思
	for (i = 0; i < 20; ++i)
		ideq[i] = i;
	
	//输出deque
	printf("输出deque中数据:\n");
	for (i = 0; i < 20; ++i)
		printf("%d ", ideq[i]);
	putchar('\n');

	//在头尾加入新数据
	printf("\n在头尾加入新数据...\n");
	ideq.push_back(100);
	ideq.push_front(i);

	//获取头尾数据
	cout<<ideq.front()<<' '<<ideq.back()<<endl;
	//输出deque
	printf("\n输出deque中数据:\n");
	for (pos = ideq.begin(); pos != ideq.end(); pos++)
		printf("%d ", *pos);
	putchar('\n');

	//查找
	const int FINDNUMBER = 19;
	printf("\n查找%d\n", FINDNUMBER);
	pos = find(ideq.begin(), ideq.end(), FINDNUMBER);
	if (pos != ideq.end())
		printf("find %d success\n", *pos);
	else
		printf("find failed\n");

	//在头尾删除数据
	printf("\n在头尾删除数据...\n");
	ideq.pop_back();
	ideq.pop_front();

	//输出deque
	printf("\n输出deque中数据:\n");
	for (pos = ideq.begin(); pos != ideq.end(); pos++)
		printf("%d ", *pos);
	putchar('\n');
	return 0;
}

//5.string
string str="123456";
str.substr(2,2);
输出34

//关于java
import java.util.*;
Set<String> hash=new HashSet<String>();
Map<String,Integer> hash=new HashMap<String,Integer>();

String str="123456";
System.out.println(str.substring(2,5));
输出345

vector
push_back();
pop_back();
erase(这里写指向那个元素的迭代器);

unordered_map
#include <string>
#include <tr1/unordered_map>
using namespace std;
using namespace std::tr1;
int main ()
{
  unordered_map<string,int> mp;
  mp["asd"]=1;
  cout<<mp["as"]<<' '<<mp["asd"]<<endl;
  return 0;
}

struct node
{
    int x, y;
    friend bool operator < (node a, node b)
    {
        return a.x > b.x; //结构体中，x小的优先级高
    }
};
priority_queue<node>q;//定义方法
//在该结构中，y为值, x为优先级。
//通过自定义operator<操作符来比较元素中的优先级。
//在重载"<"时，最好不要重载">"，可能会发生编译错误

//位图
#include<iostream>
#include<bitset>
using namespace std;
int main(){
	bitset<100> bits,tmp;
	bits[1]=1;
	tmp[10]=1;
	cout<<bits<<endl;
	cout<<tmp<<endl;
	cout<<(bits | tmp)<<endl;
	cout<<(bits & tmp)<<endl;
	return 0;
}

