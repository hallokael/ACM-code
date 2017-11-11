//÷±Ω”≈∑¿≠
/********************************************************************
*   created:	6:10:2015   22:12
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
int euler(int n){
 int res=n,a=n;  
 for(int i=2;i*i<=a;i++){  
  if(a%i==0){  
   res=res/i*(i-1);
   while(a%i==0) a/=i;  
  }  
 }  
 if(a>1) res=res/a*(a-1);  
 return res;  
}  
int main()
{
 int n ;
 scanf( "%d" , &n ) ;
 printf( "%d\n" , euler( n ) );
 return 0;
}