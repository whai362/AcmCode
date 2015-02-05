import java.util.*;
class Main{
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		int i,b,e,f1,f2;
		char[] s=new char[205];
		String str;
		while(true){
			b=in.nextInt();
			e=in.nextInt();
			if(b==-1 && e==-1) break;
			str=in.nextLine();
			str=str.substring(1,str.length());
			s=str.toCharArray();
			stack op=new stack();
			stack cl=new stack();
			f1=f2=-1;
			for(i=0;i<b;++i){
				if(s[i]=='<') f1=i;
				else if(f1!=-1 && s[i]=='>') f2=i;
				if(f1!=-1 && f2!=-1){
					if(s[f1+1]=='/'){
						op.pop();
						cl.pop();
					}
					else{
						op.push(str.substring(f1+1,f2));
						cl.push(str.substring(f1+1,f2));
					}
					f1=f2=-1;
				}
			}
			f1=f2=-1;
			for(i=b;i<e;++i){
				if(s[i]=='<') f1=i;
				else if(f1!=-1 && s[i]=='>') f2=i;
				if(f1!=-1 && f2!=-1){
					if(s[f1+1]=='/')
						cl.pop();
					else
						cl.push(str.substring(f1+1,f2));
					f1=f2=-1;
				}
				
			}
			for(i=0;i<=op.top;++i){
				System.out.print("<"+op.data[i]+">");
			}
			for(i=b;i<e;++i)
				System.out.print(s[i]);
			while(!cl.empty()){
				System.out.print("</"+cl.pop()+">");
			}
			System.out.print("\n");
		}
	}
}
class stack{
	int top;
	String[] data=new String[205];
	stack(){
		top=-1;
	}
	boolean empty(){
		if(top==-1) return true;
		return false;
	}
	void push(String s){
		data[++top]=s;
	}
	String pop(){
		return data[top--];
	}
}
