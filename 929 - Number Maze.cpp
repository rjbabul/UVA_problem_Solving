#include<bits/stdc++.h>
using namespace std;
int mn=INT_MAX;
int a[1000][1000];
int visit[1000][1000];
void call(int r , int c, int n,int m,int sum)
{

    if(r==n && c==m) mn=min(mn, sum);


}
int main()
{
    freopen("input.txt", "r", stdin);
    int n, m, t;
    cin>>t;
    while(t-- && cin>>n>>m)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                  cin>>a[i][j];
            }

        }
         mn=INT_MAX;

        call(1,1,n,m,a[1][1]);
        cout<<mn<<endl;

    }
    return 0;
}
