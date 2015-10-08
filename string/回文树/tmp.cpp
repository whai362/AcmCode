
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std ;

typedef long long LL ;

#define rep( i , a , b ) for ( int i = ( a ) ; i <  ( b ) ; ++ i )
#define For( i , a , b ) for ( int i = ( a ) ; i <= ( b ) ; ++ i )
#define rev( i , a , b ) for ( int i = ( a ) ; i >= ( b ) ; -- i )
#define clr( a , x ) memset ( a , x , sizeof a )

const int MAXN = 2000005 ;
const int mod = 51123987 ;
const int N = 26 ;

struct Palindromic_Tree {
	int next[MAXN][N] ;
	int fail[MAXN] ;
	int cnt2[MAXN] ;
	int cnt[MAXN] ;
	int len[MAXN] ;
	int S[MAXN] ;
	int last ;
	int n ;
	int p ;

	int newnode ( int l ) {
		rep ( i , 0 , N ) next[p][i] = 0 ;
		cnt[p] = 0 ;
		cnt2[p] = 0 ;
		len[p] = l ;
		return p ++ ;
	}

	void init () {
		p = 0 ;
		newnode (  0 ) ;
		newnode ( -1 ) ;
		last = 0 ;
		n = 0 ;
		S[0] = -1 ;
		fail[0] = 1 ;
	}

	int get_fail ( int x ) {
		while ( S[n - len[x] - 1] != S[n] ) x = fail[x] ;
		return x ;
	}

	int add ( int c ) {
		c -= 'a' ;
		S[++ n] = c ;
		int cur = get_fail ( last ) ;
		if ( !next[cur][c] ) {
			int now = newnode ( len[cur] + 2 ) ;
			fail[now] = next[get_fail ( fail[cur] )][c] ;
			next[cur][c] = now ;
			cnt2[now] = cnt2[fail[now]] + 1 ;
		}
		last = next[cur][c] ;
		cnt[last] ++ ;
		return cnt2[last] ;
	}

	int count ( int ans = 0 ) {
		for(int i = p - 1; i > 0; --i) {
			cout<<fail[i]<<' '<<cnt[i]<<endl;
			cnt[fail[i]] = ( cnt[fail[i]] + cnt[i] ) % mod ;
			ans = ( ans + cnt[i] ) % mod ;
		}
		return ans ;
	}
} ;

Palindromic_Tree T ;
char s[MAXN] ;
int suffix[MAXN] ;
int n ;

void solve () {
	int ans = 0 ;
	T.init () ;
	suffix[n] = 0 ;
	rev ( i , n - 1 , 0 ) suffix[i] = ( suffix[i + 1] + T.add ( s[i] ) ) % mod ;
	for(int i = 0; i < n; ++i) {
		cout<<suffix[i]<<' ';
	}
	cout<<endl;
	T.init () ;
	rep ( i , 0 , n ) ans = ( ans + ( LL ) T.add ( s[i] ) * suffix[i + 1] ) % mod ;
	int tot = T.count () ;
	cout<<tot<<endl;
	tot = ( ( LL ) tot * ( tot - 1 ) / 2 ) % mod ;
	printf ( "%d\n" , ( ( tot - ans ) % mod + mod ) % mod ) ;
}

int main () {
	while ( ~scanf ( "%d%s" , &n , s ) ) solve () ;
	return 0 ;
}
