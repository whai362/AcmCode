//手写哈希表
const int HASH_MOD=1876543;	//看题目，调大小
LL key[HASH_MOD], val[HASH_MOD];
int head[HASH_MOD], nxt[HASH_MOD];	//next为系统关键字
struct Hash{
    int tot;
    void init(){
        memset(head, -1, sizeof(head));
        tot = 0;
    }
    LL insert(LL x, LL y){
        int k = (x % HASH_MOD + HASH_MOD) % HASH_MOD;
        key[tot] = x;
        val[tot] = y;
        nxt[tot] = head[k];
        head[k] = tot++;
    }
    LL find(LL x){
        int k = (x % HASH_MOD + HASH_MOD) % HASH_MOD;
        for(int i = head[k]; i != -1; i = nxt[i])
            if(key[i] == x)
                return val[i];
        return -1;
    }
}hs;

//c++中的hash
//unordered_map 在某些oj上不能用
#include <string>
#include <tr1/unordered_map>
using namespace std;
using namespace std::tr1;
int main (){
  unordered_map<string,int> mp;
  mp["asd"]=1;
  cout<<mp["as"]<<' '<<mp["asd"]<<endl;
  return 0;
}

//java中的hash
import java.io.*;
import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		Map<String, Integer> mp=new HashMap<String, Integer>();
		mp.put("aaa", 1);
		System.out.println(mp.get("aaa"));
	}
}
