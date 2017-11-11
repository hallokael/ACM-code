//dijkstra
/********************************************************************
*   created:	21:10:2015   15:45
*********************************************************************/
#include<string.h>
#include<cstdio>
#include<cmath>
#include<set>
#include<map>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define INF 1000000000  
using namespace std;
struct point
{
 int c , r , t1 , t2 ;
}p[301] ;
int mp[301][301] ;
int color( int i , int t , int &tt )
{
 int r = p[i].r ;    
 int t1 = p[i].t1 ;
 int t2 = p[i].t2 ;
 int c = p[i].c ;
 tt = r - t ;
 if( t < r )
  return c ;
 t -= r ;
 t = t%( t1 + t2 ) ;
 if( t < t2 )
 {
  tt = t2 - t ;
  return !c ;
 }
 else
 {
  tt = t1 + t2 - t ;
  return c ;
 }
}
int wait( int i , int j , int t )
{
 int t1 , t2 ;
 int tt = 0 ;
 for(int k = 0 ; k < 3 ; k ++ )
 {
  if( color( i , t + tt , t1 ) == color( j , t + tt , t2 ) )
   return tt ;
  tt += min( t1 , t2 ) ;
 }
 return INF ;
}
int d[301] ;
int n , m ;
bool used[301] ;
void dijkstra( int s )
{
 for(int i = 1 ; i <= n ; i ++ )
  d[i] = INF ;
 d[s] = 0 ;
 while( true )
 {
  int v =  - 1 ;
  for(int u = 1 ; u <= n ; u ++ )
  {
   if( !used[u] && ( v ==  - 1 || d[u] < d[v] ) )
    v = u ;
  }
  if( v ==  - 1 )
   break;
  used[v] = true ;
  for(int u = 1 ; u <= n ; u ++ )
  {
   d[u] = min( d[u] , d[v] + mp[v][u] + wait( u , v , d[v] ) ) ;
  }
 }
}
int main()
{
 int st , en ;
 scanf( "%d%d" , &st , &en ) ;
 scanf( "%d%d" , &n , &m ) ;
 for(int i = 1 ; i <= n ; i ++ )
 {
  for(int j = 1 ; j <= n ; j ++ )
  {
   mp[i][j] = INF ;
  }
 }
 for(int i = 1 ; i <= n ; i ++ )
  mp[i][i] = 0 ;
 for(int i = 1 ; i <= n ; i ++ )
 {
  getchar() ;
  char c ;
  scanf( "%c%d%d%d" , &c , &p[i].r , &p[i].t1 , &p[i].t2 ) ;
  if( c == 'P' )
  {
   p[i].c = 1 ;
   swap( p[i].t1 , p[i].t2 ) ;
  }
 }
 for(int i = 1 ; i <= m ; i ++ )
 {
  int j , k , t ;
  scanf( "%d%d%d" , &j , &k , &t ) ;
  mp[j][k] = t ;
  mp[k][j] = t ;
 }
 dijstra( st ) ;
 if( d[en] >= INF )
  d[en] = 0 ;
 printf( "%d\n" , d[en] );
 return 0;
}