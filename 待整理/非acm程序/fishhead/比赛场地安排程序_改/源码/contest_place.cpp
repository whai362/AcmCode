#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <windows.h>
using namespace std;

int main()
{
	//l表示横向,w表示纵向
	const int bas_l=640,bas_w=178*2;        //场的大小
	char ctr=0,str[10];
	int l,w;				  //一张桌子的大小
	int l1,w1;                //桌子与场地的边界
	int l2,w2;				  //桌子与桌子的边界	
	int count,i,j;
	while(ctr!=27)
	{
		system("cls");
		cout<<"输入桌子长度(精确到5cm): ";
		cin>>l;
		cout<<"输入桌子宽度(精确到5cm): ";
		cin>>w;
		cout<<"输入桌子与场地边界的横向距离(精确到5cm): ";
		cin>>l1;
		cout<<"输入桌子与场地边界的纵向距离(精确到5cm): ";
		cin>>w1;
		cout<<"输入桌子与桌子边界的横向距离(精确到5cm): ";
		cin>>l2;
		cout<<"输入桌子与桌子边界的纵向距离(精确到5cm): ";
		cin>>w2;
		l=l/5;
		w=w/5;
		l1=l1/5;
		w1=w1/5;
		l2=l2/5;
		w2=w2/5;
		count=0;
		initgraph(bas_l+10,bas_w+80);
		setcolor(RED);
		rectangle(0,0,bas_l,bas_w);
		setcolor(YELLOW);
		rectangle(l1,w1,bas_l-l1,bas_w-w1);
		setcolor(WHITE);

		for (i=l1;i+l+l1<=bas_l;i+=l+2*l2)
		{
			for (j=w1;j+2*w+w1<=bas_w;j+=2*w+2*w2)
			{
				rectangle(i,j,i+l,j+2*w);
				count+=2;
			}
			if (j+w+w1<=bas_w)
			{
				rectangle(i,j,i+l,j+w);
				count++;
			}
		}
		if (i+w+l1<=bas_l)
		{
			for (j=w1;j+l+w1<=bas_w;j+=l+2*w2)
			{
				rectangle(i,j,i+w,j+l);
				count++;
			}
		}
		sprintf(str,"%d",count);
		outtextxy(10,bas_w+10,"桌子数为");
		outtextxy(75,bas_w+10,str);
		outtextxy(10,bas_w+30,"红框为篮球场，黄框为比赛场地，白框为桌子。");
		rectangle(10,bas_w+50,10+24,bas_w+50+2*12);
		outtextxy(10+24+5,bas_w+50,"为两张桌子，");
		rectangle(135,bas_w+50,135+24,bas_w+50+12);
		outtextxy(135+24+5,bas_w+50,"为一张桌子，");
		getch();
		closegraph();
		cout<<"按esc退出,按其他键继续。"<<endl;
		ctr=getch();
	}
	return 0;
}

