import java.util.*;
class Main{
	static char[] tmp=new char[10];
	static char[][] _map=new char[5][5],st=new char[5][5];
	static void dfs(int x,int y,
	public static void main(String []){
		Scanner in=new Scanner(System.in);
		int i,j,cnt;
		String s1,s2;
		s1=in.next();
		s2=in.next();
		tmp=s1.toCharArray();
		cnt=0;
		for(i=0;i<3;++i){
			for(j=0;j<3;++j){
				_map[i][j]=tmp[cnt++];
			}
		}
		tmp=s2.toCharArray();
		cnt=0;
		for(i=0;i<3;++i){
			for(j=0;j<3;++j){
				st[i][j]=tmp[cnt++];
			}
		}
	}
}
