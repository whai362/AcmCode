import java.util.*;
class Main{
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		int n;
		int cnt,i,j,k,t1,t2;
		int[] f=new int[10005];
		char[] s1=new char[10],s2=new char[10];
		while(in.hasNext()){
		n=in.nextInt();
		if(n==0) break;
		for(i=n+1;;++i){
			cnt=0;
			t1=(int)Math.sqrt(i);
			t2=i;
			for(j=2;j<=t1;++j){
				if(t2%j==0){
					t2/=j;
					f[cnt++]=j;
					--j;
				}
			}
			if(cnt==0) continue;
			//System.out.println(i+" "+t1+":");
			/*for(j=0;j<cnt;++j){
				System.out.print(f[j]+" ");
			}
			System.out.print("\n");*/
			if(t2>1) f[cnt++]=t2;
			int left=0,right=0,l1,l2;
			s1=Integer.toString(i).toCharArray();
			l1=s1.length;
			for(j=0;j<l1;++j){
				left+=s1[j]-'0';
			}
			for(j=0;j<cnt;++j){
				s2=Integer.toString(f[j]).toCharArray();
				l2=s2.length;
				for(k=0;k<l2;++k){
					right+=s2[k]-'0';
				}
			}
			if(left==right){
				System.out.println(i);
				break;
			}
		}
	}
	}
}
