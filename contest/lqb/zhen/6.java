import java.util.*;
class Main{
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		char[] c1=new char[1005],c2=new char[1005];
		int cnt=0,i,l;
		String s1,s2;
		s1=in.next();
		s2=in.next();
		l=s1.length();
		c1=s1.toCharArray();
		c2=s2.toCharArray();
		for(i=0;i<l;++i){
			if(c1[i]!=c2[i]){
				if(c2[i]=='*') c2[i]='o';
				else c2[i]='*';
				if(c2[i+1]=='*') c2[i+1]='o';
				else c2[i+1]='*';
				++cnt;
			}
		}
		System.out.println(cnt);
	}
}
