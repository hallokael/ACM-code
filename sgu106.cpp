//看了题解又半抄半写的，逻辑挺复杂
//扩展欧几里得
/********************************************************************
*   created:	22:10:2015   20:13
*********************************************************************/
#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<set>
#include<map>
#include<vector>
#include<cstring>
#include<stack>
#include<cmath>
#include<queue>
using namespace std;
#define CL(x,v); memset(x,v,sizeof(x));
#define INF 0x3f3f3f3f
#define LL long long
#define ll long long
void exgcd(LL a,LL b,LL &d,LL &x,LL &y)
{
 if(!b){d=a;x=1;y=0;}
 else{exgcd(b,a%b,d,y,x);y-=x*(a/b);}
}
int main()
{
 ll a , b , c , x1 , x2 , y1 , y2 ;
 scanf( "%lld%lld%lld%lld%lld%lld%lld" , &a , &b , &c , &x1 , &x2 , &y1 , &y2 ) ;
 if( a == 0||b == 0 )
 {
  if( a == 0 && b )
  {
   if( c%b || c / b < y1 || c / b > y2 )
   {
    printf( "0\n" );
    return 0 ;
   }
   else
   {
    printf( "%I64d\n" , x2 - x1 + 1 );
    return 0 ;
   }
  }
  if( b == 0 && a )
  {
   if( c%a || c / a < x1 || c / a > x2 )
   {
    printf( "0\n" );
    return 0 ;
   }
   else
   {
    printf( "%I64d\n" , y2 - y1 + 1 );
    return 0 ;
   }
  }
  if( c == 0 )
   printf( "%I64d\n" , ( x2 - x1 + 1 )*( y2 - y1 + 1 ) );
  else
   printf( "0\n" );
  return 0 ;
 }
 if( c < 0 )
  c =  - c ;
 else
  b =  - b , a =  - a ;
 if( a < 0 )
  a =  - a , x1 =  - x1 , x2 =  - x2 , swap( x1 , x2 ) ;
 if( b < 0 )
  b =  - b , y1 =  - y1 , y2 =  - y2 , swap( y1 , y2 ) ;
 ll d , x , y ;
 if( a < b )
  exgcd( b , a , d , y , x ) ;
 else
  exgcd( a , b , d , x , y ) ;
 if( c%d )
 {
  printf( "0\n" );
  return 0;
 }
 a /= d ;
 b /= d ;
 c /= d ;
 x *= c , y *= c ;
 ll ans = 0 ;
 while( x <= x2 )
 {
  if( ans )
   break ;
  if( x <= x2 && x >= x1 && y <= y2 && y >= y1 )
   ans ++ ;
  if( ans )
   break ;
  x += b , y -= a ;
 }
 while( x >= x1 )
 {
  if( ans )
   break ;
  if( x <= x2 && x >= x1 && y <= y2 && y >= y1 )
   ans ++ ;
  if( ans )
   break ;
  x -= b , y += a ;
 }
 if( ans )
 {
  ll a1 = ( x2 - x ) / b ;
  ll b1 = ( y - y1 ) / a ;
  ans += min( a1 , b1 ) ;
  a1 = ( x - x1 ) / b ;
  b1 = ( y2 - y ) / a ;
  ans += min( a1 , b1 ) ;
 }
 printf( "%I64d\n" , ans );
 return 0 ;
}