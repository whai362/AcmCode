#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	int n,t,flag;
	char s[100],fin[100],a[100],b[100],c[100],ans[100];
	scanf("%d",&t);
	while (t--)
	{
		scanf("%s",s);
		flag=0;
		int l=strlen(s),l2=0;
		for (int i=0;i<l;i++) if ((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
		{
			fin[l2]=s[i];
			l2++;
		}
		fin[l2]='\0';
		for (int i=1;i<=l2/3;i++)
			for (int j=1;j<=l2/2;j++) if (3*i+2*j>l2) break;
				else
				{
					for (int k=0;k<i;k++) a[k]=fin[k];
					a[i]='\0';
					for (int k=i;k<i+j;k++) b[k-i]=fin[k];
					b[j]='\0';
					if (strcmp(a,b)==0) continue;
					for (int k=0;k<i;k++) ans[k]=a[k];
					for (int k=i;k<i+j;k++) ans[k]=b[k-i];
					for (int k=i+j;k<2*i+j;k++) ans[k]=a[k-i-j];
					for (int k=2*i+j;k<2*i+2*j;k++) ans[k]=b[k-2*i-j];
					for (int k=2*i+2*j;k<3*i+2*j;k++) ans[k]=a[k-2*i-2*j];
					ans[3*i+2*j]='\0';
					if (strcmp(ans,fin)==0) flag=1;
				}
		for (int i=1;i<=l2/3;i++)
			for (int j=1;j<=l2/2;j++)
				for (int k=1;k<=l2;k++) if (3*i+3*j+k>l2) break;
				else {
					for (int x=0;x<i;x++) a[x]=fin[x];
					a[i]='\0';
					for (int x=i;x<i+j;x++) b[x-i]=fin[x];
					b[j]='\0';
					for (int x=2*i+2*j;x<2*i+2*j+k;x++) c[x-2*i-2*j]=fin[x];
					c[k]='\0';
					if (strcmp(a,b)==0||strcmp(a,c)==0||strcmp(b,c)==0) continue;
					for (int x=0;x<i;x++) ans[x]=a[x];
					for (int x=i;x<i+j;x++) ans[x]=b[x-i];
					for (int x=i+j;x<2*i+j;x++) ans[x]=a[x-i-j];
					for (int x=2*i+j;x<2*i+2*j;x++) ans[x]=b[x-2*i-j];
					for (int x=2*i+2*j;x<2*i+2*j+k;x++) ans[x]=c[x-2*i-2*j];
					for (int x=2*i+2*j+k;x<3*i+2*j+k;x++) ans[x]=a[x-2*i-2*j-k];
					for (int x=3*i+2*j+k;x<3*i+3*j+k;x++) ans[x]=b[x-3*i-2*j-k];
					ans[3*i+3*j+k]='\0';
					if (strcmp(ans,fin)==0) flag=1;
				}
		if (flag==1) printf("Yes\n"); else printf("No\n");
	}
	return 0;
}
