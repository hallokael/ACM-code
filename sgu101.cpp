/*
����ŵ����
ÿ���������棬д���������֣���ĿҪ�����������Ϲ��ƣ�ʹ������Ե����������ͬ��
�������ַ�Χ0~6
��ÿ�����ƿ���һ������ߣ��������Ϊһ�����رߵ�ŷ����·���������⣬ֱ��dfs���ɡ�
*/
/********************************************************************
*   created:	6:10:2015   19:16
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

using namespace std;
int ma[7][7] ;
int x[105] ;
int y[105] ;
int d[105] ;
int wayx[105] ;
int wayy[105] ;
int n ; 
int cnt ; 
int st ; 
void Init()
{
 scanf( "%d" , &n ) ;
 for(int i = 1 ; i <= n ; i ++ )
 {
  int u , v ; 
  scanf( "%d%d" , &u , &v ) ;
  ma[u][v] ++ ; 
  ma[v][u] ++ ; 
  d[u] ++ ; 
  d[v] ++ ; 
  x[i] = u ; 
  y[i] = v ; 
 }
}
void DFS( int u )
{
 for( int v = 0 ; v <= 6 ; v ++ )
 {
  if( ma[u][v] )
  {
   ma[u][v] -- ; 
   ma[v][u] -- ; 
   DFS( v ) ; 
   cnt ++ ; 
   wayx[cnt] = u ; 
   wayy[cnt] = v ; 

  }
 }
}
void work()
{
 for(int i = 0 ; i <= 6 ; i ++ )
  if( d[i]&1 == 1 )
  {
   cnt ++ ; 
   st = i ; 
  }
  else if( !st && d[i] )
  {
   st = i ; 
  }
  if( cnt > 2 )
  {
   printf( "No solution\n" );
   return ; 
  }
  cnt = 0 ; 
  DFS( st ) ;
  if( cnt < n )
  {
   printf( "No solution\n" );
   return ; 
  }
  for(int i = cnt ; i ; i -- )
  {
   for(int j = 1 ; j <= n ; j ++ )
   {
    if( wayx[i] == x[j] && wayy[i] == y[j] )
    {
     printf( "%d +\n" , j );
     x[j] =  - 1 ; 
     break ; 
    }
    else if( wayx[i] == y[j] && wayy[i] == x[j] )
    {
     printf( "%d -\n" , j );
     x[j] =  - 1 ; 
     break ; 
    }
   }
  }
}
int main()
{
 Init() ; 
 work() ; 
 return 0;
}
