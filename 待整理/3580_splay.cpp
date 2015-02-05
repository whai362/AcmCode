/*【题目大意】
   给定一组数(n<=100000)，有m(m<=100000)个操作：
   1.ADD.给区间[l,r]的数都加上d；
   2.REVERSE.翻转一个区间[l,r]；
   3.REVOLVE.把一个区间[l,r]转动k次（每转动一次最右边的数来到最左边）；
   4.INSERT.在某个位置x后插入一个数；
   5.DELETE.删除某个位置x上的数；
   6.MIN.求区间[l,r]的最小值。

【分析】
   这题中涉及的操作十分强大，线段树只能完成操作1和6，Treap只能完成操作4和5，只有伸展树splay能解决所有问题。
   由于这题是模板题，除编写外就没有什么好注意的了。于是我们来看程序和注释（该程序经缩行后在poj中是最短的，其中的伸展树模板比较简洁，大家可以学习一下）：*/

//1.伸展树类型：
struct tree {
   int par , ch[2] , dir; //父亲、左右孩子、该节点是其父亲的左节点(0)还是右节点(1)。
   int data , size , mins , mark; //数字、子树大小、子树中数字的最小值、字树被中的数都要加上mark。
   bool rev; //子树是否被翻转。
};
tree node[maxn];

//2.连接操作：
void link( int par , int t , int dir ) { //把节点par的dir儿子设为t。
   node[par].ch[dir] = t;
   node[t].par = par; //t也要维护其父亲的信息。
   node[t].dir = dir;
}

//3.传递与维护：
void release( int t ) {
   if ( node[t].rev ) { //如果该子树需要翻转。
       swap( node[t].ch[0] , node[t].ch[1] ); //交换左右儿子（下两句也是必须的）。
       link( t , node[t].ch[0] , 0 );
       link( t , node[t].ch[1] , 1 );
       node[t].rev = false; //取消t的标记。
       if ( node[t].ch[0] != 0 ) node[node[t].ch[0]].rev ^= true; //传递标记。
       if ( node[t].ch[0] != 1 ) node[node[t].ch[1]].rev ^= true;
   }
   if ( node[t].mark != 0 ) { //如果该子树都被加上的一个数。
       node[t].data += node[t].mark; //该点的数字加上这个数。
       node[t].mins += node[t].mark; //该子树的最小值也加上这个数。
       if ( node[t].ch[0] != 0 ) node[node[t].ch[0]].mark += node[t].mark;
       if ( node[t].ch[0] != 1 ) node[node[t].ch[1]].mark += node[t].mark;
       node[t].mark = 0; //取消t的标记。
   }
}

void update( int t ) { //维护t的信息。
   if ( node[t].ch[0] != 0 ) release( node[t].ch[0] ); //释放儿子的标记使其信息正确。
   if ( node[t].ch[1] != 0 ) release( node[t].ch[1] );
   node[t].size = node[node[t].ch[0]].size + node[node[t].ch[1]].size + 1; //维护子树大小。
   node[t].mins = min( node[t].data , min( node[node[t].ch[0]].mins , node[node[t].ch[1]].mins ) ); //维护子树数字最小值。
}

//4.伸展操作：
void rotate( int t ) { //旋转操作，把节点t往上旋转。
   int par = node[t].par;
   release( par ); //传递标记。
   release( t );
   int dir = node[t].dir; //弄清父亲的方向。
   link( node[par].par , t , node[par].dir ); //旋转。
   link( par , node[t].ch[!dir] , dir );
   link( t , par , !dir );
   update( par ); //维护信息。
}

void splay( int anc , int t ) { //伸展节点t使其父亲为anc（想使t为根时anc=0）。
   release( t ); //传递标记。
   while ( node[t].par != anc ) {
       int par = node[t].par;
       if ( node[par].par != anc ) { //判断旋转方式。
           if ( node[t].dir == node[par].dir ) rotate( par );
               else rotate( t );
       }
       rotate( t );
   }
   update( t ); //维护信息。
}

//5.寻找第k个位置的节点：
int rank( int t , int k ) { //寻找以t为根的树中第k个位置的节点。
   while ( true ) {
       release( t ); //记得要传递标记，因为它可能使左右儿子互换。
       int tmp = node[node[t].ch[0]].size + 1;
       if ( k == tmp ) break; //找到了。
       if ( k < tmp ) t = node[t].ch[0]; //判断该点在哪棵子树。
           else {
               k -= tmp;
               t = node[t].ch[1];
           }
   }
   return t;
}

//6.把区间(l,r)的元素集中在一棵子树上（注意是开区间）：
int draw( int l , int r ) {
   splay( 0 , 1 );
   int root = rank( 1 , l ) , t = rank( 1 , r );
   splay( 0 , root ); //把第l位元素旋转到根，记成root。
   splay( root , t ); //把第r位元素旋转为root的右儿子，记成t。
   return t; //返回t。此时区间(l,r)的元素集中在以node[t].ch[0]为根的子树上。
}

//7.利用splay解决本题：
void solve() {
   tot = 2; //虚拟出两个节点，点1一定在第一个位值，点2一定在第二个位置。如果我们需要用draw操作集中区间[l,r]，就要用到点l-1和点r+1。虚构出点1点2使得l=1或r=n时draw操作无需特判。
   node[1].size = node[2].size = 1;
   node[0].mins = node[1].mins = node[2].mins = Inf; //无实际意义的点的data和mins都是无限大。
   node[0].data = node[1].data = node[2].data = Inf;
   
   scanf( "%d" , &n ); //读入时把它们从左上到右下连起来，最后splay一下叶子以维护信息。
   for ( int i = 1 ; i <= n ; i++ ) {
       node[++tot].size = 1;
       scanf( "%d" , &node[tot].data );
       if ( i == 1 ) link( 1 , tot , 1 );
           else link( tot - 1 , tot , 1 );
   }
   link( tot , 2 , 1 );
   splay( 0 , 2 );
   
   scanf( "%d" , &m );
   for ( int i = 1 ; i <= m ; i++ ) {
       string str; cin >> str;
       if ( str == "ADD" ) {
           int l , r , d; scanf( "%d%d%d" , &l , &r , &d );
           int t = node[draw( l , r + 2 )].ch[0]; //提取出区间[l,r]。由于点1的存在于最左边，使得该区间应右移一位变成[l+1,r+1]=(l,r+2)，下同不解释、
           node[t].mark += d; //给该区间的数字都加上d。
           splay( 0 , t ); //把信息改变过的点伸展一下一维护整棵树的信息。下同不解释。
       } else
       if ( str == "REVERSE" ) {
           int l , r; scanf( "%d%d" , &l , &r );
           int t = node[draw( l , r + 2 )].ch[0];
           node[t].rev ^= true; //基本同ADD操作，只是这里修改的信息不同。
           splay( 0 , t );
       } else
       if ( str == "REVOLVE" ) {
           int l , r , k; scanf( "%d%d%d" , &l , &r , &k );
           int w = r - l + 1;
           k = ( k % w + w ) % w; //k对区间长度取模。
           if ( k == 0 ) continue; //k=0等于没转动过，否则相当于把该区间的右边k个数移到左边来。
           int t = draw( r - k + 1 , r + 2 ) , nt = node[t].ch[0];
           link( t , 0 , 0 ); //切掉右边k个数（以nt为根的子树）。
           splay( 0 , t );
           t = draw( l , l + 1 );
           link( t , nt , 0 ); //把这k个数接在区间的左边。
           splay( 0 , nt );
       } else`	
       if ( str == "INSERT" ) {
           node[++tot].size = 1;
           int x; scanf( "%d%d" , &x , &node[tot].data );
           int t = draw( x + 1 , x + 2 ); //此时根是该数字前的节点，t是它后面的节点。
           link( t , tot , 0 ); //于是这个数字就插在它们中间，成为t的左儿子。
           splay( 0 , tot );
       } else
       if ( str == "DELETE" ) {
           int x; scanf( "%d" , &x );
           int t = draw( x , x + 2 );
           link( t , 0 , 0 ); //切断这个节点。
           splay( 0 , t );
       } else
       if ( str == "MIN" ) {
           int l , r; scanf( "%d%d" , &l , &r );
           int t = node[draw( l , r + 2 )].ch[0];
           printf( "%d\n" , node[t].mins ); //基本同ADD操作，而这里是获取最小值的信息。
       }
   }
}

