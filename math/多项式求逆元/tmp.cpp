#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define MX 3000000
#define FOR( A, B, C ) for ( register int A = B, _end_ = C; A <= _end_; A++ )
#define ROF( A, B, C ) for ( register int A = B, _end_ = C; A >= _end_; A-- )
#define ll long long

struct number {
#define MAX 2100
 int num[ MAX + 1 ], fir;
    number( int k = 0 ) { FOR ( i, 0, MAX ) { num[ i ] = 0; } for ( fir = MAX; k; num[ fir-- ] = k & 1, k >>= 1 ); fir++; fir = min( fir, MAX ); }
    int & operator [] ( const int &x ) { return num[ x ]; }
};

int w[ 2 ][ MX + 10 ], tmp[ MX + 10 ], P = 1004535809, K, invK, m, f[ MX + 10 ], invf[ MX + 10 ], E[ MX + 10 ], M0[ MX + 10 ], type, k, x1[ MX + 10 ], l, INP[ MX + 10 ], revf[ MX + 10 ], x2[ MX + 10 ], D[ MX + 10 ], R[ MX + 10 ], invB[ MAX ][ MAX ], B[ MAX ][ MAX ], d[ MAX ][ MAX ], r[ MAX ][ MAX ], tmpf[ MAX ], tmpM0[ MAX ], ttt[ MAX ], rec[ MAX ][ MAX ], TT1[ MAX + 10 ], TT2[ MAX + 10 ];

int fpm( int F, int FF, int P ) {
    int ans = 1;
    for ( ; FF; FF >>= 1, F = (ll)F * F % P )
        if ( FF & 1 ) ans = (ll)ans * F % P;
    return ans;
}

void MOD2( int &x ) { if ( x > 3000000 ) x = ( P - x ) & 1; else x = x & 1; }

inline void inc( int &x, int dat ) { x += dat; if ( x >= P ) x -= P; }

inline void dec( int &x, int dat ) { x -= dat; if ( x < 0 ) x += P; }

void FFT( int X[], int k, int v ) {
    for ( register int i = 0, j = 0; i < k; i++ ) {
        if ( i < j ) swap( X[ i ], X[ j ] );
        for ( register int l = k >> 1; ( j ^= l ) < l; l >>= 1 );
    }
    for ( register int i = 2; i <= k; i <<= 1 )
        for ( register int j = 0; j < k; j += i )
            for ( register int l = 0; l < i >> 1; l++ ) {
                int q = j + l + ( i >> 1 );
                int t = (ll)X[ q ] * w[ v ][ K / i * l ] % P;
                X[ q ] = X[ j + l ]; dec( X[ q ], t );
                inc( X[ j + l ], t );
            }
}

void GetInv( int A1[], int A[], int t ) {
    if ( t == 1 ) { A1[ 0 ] = fpm( A[ 0 ], P - 2, P ); return; }
    GetInv( A1, A, ( t + 1 ) >> 1 );
    int K = 1; for ( ; K < t + 3; K <<= 1 ); int invK = fpm( K, P - 2, P );
    FFT( A1, K, 0 );
    FOR ( i, 0, K - 1 ) { A1[ i ] = (ll)A1[ i ] * A1[ i ] % P; }
    FFT( A1, K, 1 );
    FOR ( i, 0, t - 1 ) { A1[ i ] = (ll)A1[ i ] * invK % P; MOD2( A1[ i ] ); } FOR ( i, t, K - 1 ) { A1[ i ] = 0; }
    K = 1; for ( ; K < 2 * t + 3; K <<= 1 ); invK = fpm( K, P - 2, P );
    memcpy( tmp, A, t << 2 ); memset( tmp + t, 0, ( K - t ) << 2 );
    FFT( A1, K, 0 ); FFT( tmp, K, 0 );
    FOR ( i, 0, K - 1 ) { A1[ i ] = (ll)A1[ i ] * tmp[ i ] % P; }
    FFT( A1, K, 1 );
    FOR ( i, 0, t - 1 ) { A1[ i ] = (ll)A1[ i ] * invK % P; MOD2( A1[ i ] ); } memset( A1 + t, 0, ( K - t ) << 2 );
}
void Init() {
    for ( K = 1; K < 2 * m; K <<= 1 ); invK = fpm( K, P - 2, P );
    w[ 0 ][ 0 ] = 1; int G = fpm( 3, ( P - 1 ) / K, P );
    FOR ( i, 1, K ) { w[ 0 ][ i ] = (ll)w[ 0 ][ i - 1 ] * G % P; }
    FOR ( i, 0, K ) { w[ 1 ][ i ] = w[ 0 ][ K - i ]; }
    
    FOR ( i, 0, m ) { revf[ i ] = f[ m - i ]; }
    GetInv( invf, revf, m + 1 );
    FOR ( i, 0, min( m, MAX - 10 ) ) { tmpf[ i ] = f[ i ]; }
    FFT( f, K, 0 ); FFT( invf, K, 0 );
}
int a[10],b[10];
int main() {
    b[0]=1;
	b[1]=1;
	b[2]=0;
	b[3]=0;
	b[4]=1;
	b[5]=0;
	b[6]=1;
	m=6;
	Init();
	GetInv(a,b,7);
	for(int i=0;i<=6;++i){
		cout<<a[i]<<' ';
	}
	cout<<endl;
}
