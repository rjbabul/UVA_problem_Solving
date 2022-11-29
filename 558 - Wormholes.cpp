#include<iostream>
#include<cstdio>

using namespace std;

struct Node
{
    int u, v, w;
};
bool bellmanford(Node node[], int s,int n,int m)
{

    int dis[100005]={100000009};
    dis[s]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(dis[node[j].v]> dis[node[j].u]+node[j].w)
                dis[node[j].v]= dis[node[j].u] + node[j].w;
        }
    }
     for(int j=0;j<m;j++)
        {
            if(dis[node[j].v]> dis[node[j].u]+node[j].w)
                 return true;
        }
    return false;
}
int main()
{
   // freopen("input.txt", "r", stdin);
    int t,n, m;
    cin>>t;
    while(t-- && cin>>n>>m)
    {
        int x, y, w;
        Node node[100005];
        for(int i=0;i<m;i++)
        {
            cin>>x>>y>>w;
            node[i].u=x;
            node[i].v=y;
            node[i].w=w;
        }

        if(bellmanford(node, 0,n,m))
            cout<<"possible"<<endl;
        else
            cout<<"not possible"<<endl;
    }
    return 0;
}
