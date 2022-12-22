#include<iostream>
#include<cstdio>
#include<cmath>
#include<limits.h>
using namespace std;

struct Node
{
    int u, v, w;
};
bool flag =true;
long long int dis[1005];
 void bellmanford(Node node[], int s,int n,int m)
{

    for(int i=1;i<=n;i++) dis[i]=INT_MAX;
    dis[s]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(dis[node[j].u]!=INT_MAX && dis[node[j].v]> dis[node[j].u]+node[j].w)
                dis[node[j].v]= dis[node[j].u] + node[j].w;
        }
    }

    for(int j=1;j<=m;j++)
        {

            if(dis[node[j].v]!=INT_MAX && dis[node[j].v]> dis[node[j].u]+node[j].w)
               {
                    flag= flag;
                    dis[node[j].v]=-INT_MIN;
               }
        }

}
int main()
{
      freopen("input.txt", "r", stdin);
    int t,n, m;
     t=1;
    while(cin>>n)
    {
        int a[2004];
        for(int i=1;i<=n;i++) cin>>a[i];

        int x, y, w;
        Node node[1005];
        flag=true;
        cin>>m;
        for(int i=1;i<=m;i++)
        {
            cin>>x>>y;

            w= (a[y]-a[x])*(a[y]-a[x])*(a[y]-a[x]);

            node[i].u=x;
            node[i].v=y;
            node[i].w=w;
        }

        bellmanford(node, 1,n,m);
        int q;
         cout<<"Set #"<<t++<<endl;
         cin>>q;

         while(q--  && cin>>x)
            {

               if(flag && dis[x]>=3 && dis[x]!=INT_MAX)cout<<dis[x]<<endl;
               else cout<<"?"<<endl;
            }
    }
    return 0;
}

