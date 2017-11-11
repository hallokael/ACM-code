¼òÃ÷Ëã·¨WA
//date 2016/03/10 20:08
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
#define CL(x,v); memset(x,v,sizeof(x));
#define INF 0x3f3f3f3f
#define ll long long
int x[23333];
int p[23333];

int main()
{
    int n;
    scanf_s("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf_s("%d%d", &x[i], &p[i]);
    int ans=x[1]; 
    ll minnum = 0;
    ll num = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            num += (abs(x[i] - x[j])*p[j]);
        if (minnum == 0)
            minnum = num; 
        if (num <= minnum)
        {
            minnum = num;
            ans = i;
        }
        num = 0; 
    }
    printf("%d", x[ans]);
    return 0;
}