#include<bits/stdc++.h>
using namespace std;
int visit[500009];
int mat[500009];

int dfs(int node[ ][1], int s)
{
    int ans=0;
    visit[s]=1;
    if(node[s][0]!=-1 &&  !visit[node[s][0]])
        ans+= 1+ dfs(node, node[s][0]);
     visit[s]=0;
    return mat[s]=ans;
}
int main()
{
    ///freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int test,u,v;
    cin>>test;

    for(int t=1; t<=test; t++)
    {
        cin>>n;

        int node[50009][1];
        for(int i=0;i<=n;i++)node[i][0]=-1;
        for(int i=0;i<n;i++)
        {
            cin>>u>>v;
            node[u][0]=v;
        }


        memset(mat, -1, sizeof(mat));
        int best=0, ans=0;

        for(int i=1;i<=n;i++)
        {
            if(mat[i]==-1)
            {
                mat[i]= dfs(node, i);
            }
            if(mat[i]>best)
            {
                best=mat[i];
                ans=i;
            }
        }
        cout<<"Case "<<t<<": "<<ans<<endl;
    }
    return 0;
}
