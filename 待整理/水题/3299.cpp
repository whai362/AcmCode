#include<stdio.h>
#include<math.h>
#define E 2.718281828459
int main(){
	double d,e,h,H,t,tmp1,tmp2;
	char s1[5],s2[5];
	while(scanf("%s",s1)&&s1[0]!='E'){
		scanf("%lf%s%lf",&tmp1,s2,&tmp2);
		if(s1[0]=='T'&&s2[0]=='D'||s2[0]=='T'&&s1[0]=='D'){
			if(s1[0]=='T'&&s2[0]=='D') t=tmp1,d=tmp2;
			else t=tmp2,d=tmp1;
			e=6.11*pow(E,(5417.7530*(1.0/273.16-1/(d+273.16))));
			h=0.5555*(e-10.0);
			H=t+h;
		}
		else if(s1[0]=='T'&&s2[0]=='H'||s2[0]=='T'&&s1[0]=='H'){
			if(s1[0]=='T'&&s2[0]=='H') t=tmp1,H=tmp2;
			else t=tmp2,H=tmp1;
			h=H-t;
			e=h/0.5555+10.0;
			d=1.0/(1.0/273.16-log(e/6.11)/log(E)/5417.7530)-273.16;
		}
		else if(s1[0]=='D'&&s2[0]=='H'||s2[0]=='D'&&s1[0]=='H'){
			if(s1[0]=='D'&&s2[0]=='H') d=tmp1,H=tmp2;
			else d=tmp2,H=tmp1;
			e=6.11*pow(E,(5417.7530*(1.0/273.16-1/(d+273.16))));
			h=0.5555*(e-10.0);
			t=H-h;
		}
		printf("T %.1f D %.1f H %.1f\n",t,d,H);
	}
	return 0;
}
