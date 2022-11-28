#include<bits/stdc++.h>
using namespace std;
int dis[20005];
int wa[20005];
int s0[20005];
int n=0;
struct Node
{
    int w,  v;
    struct Node* child;
};

void heapify(int at, int n)
{
    int mx= at;
    int l = at*2+1;
    int r = at*2+2;

    if( l<n && wa[l]<wa[mx]) mx=l;
    if( r<n && wa[r]<wa[mx]) mx=r;

    if(mx!=at)
    {
        swap(wa[mx], wa[at]);
        swap(s0[mx], s0[at]);
        heapify(mx, n);
    }
}

void push( int s, int w)
{
    wa[n]=w;
    s0[n]= s;
    n+=1;
    for(int i=n/2-1;i>=0;i--)
    {
        heapify(i,n);
    }
}

void pop()
{
    swap(wa[0], wa[n-1]);
    swap(s0[0], s0[n-1]);
    n-=1;
    heapify(0, n);
}

Node* push(Node*head, int v,int w)
{
    Node* newnode =NULL;
    newnode = (struct Node*)malloc(sizeof(struct Node));

    newnode->w= w;
    newnode->v= v;
    newnode->child = NULL;

    if(head==NULL) return newnode;

    Node*temp= head;
    while(temp->child) temp= temp->child;
    temp->child= newnode;

    return head;
}

void dijkstra(Node *node[], int s)
{
    n=0;
    dis[s]=0;
    push(s, 0);

   while(n>=0)
   {
      s= s0[0];
      pop();

      for(Node*edge = node[s]; edge; edge= edge->child)
      {
          int v = edge->v;
          int cost= edge->w;
          if(dis[v]==-1 || cost+dis[s]<dis[v])
          {
              dis[v]= dis[s]+cost;
              push(v, dis[v]);
          }
      }
   }
}

int main()
{
    int t;
    int n, m, s, d,u,v,w;
    freopen("input.txt", "r", stdin);
    cin>>t;
    for(int test=1; test<=t;test++)
    {

        Node *node[20002]={NULL};
        memset(dis, -1, sizeof(dis));

        cin>>n>>m>>s>>d;
        for(int i=0;i<m;i++)
        {
            cin>>u>>v>>w;
            node[u]= push(node[u], v, w);
            node[v]= push(node[v], u, w);
        }
        dijkstra(node, s);

        cout<<"Case #"<<test<<": ";
        if(dis[d]==-1)
            cout<<"unreachable"<<endl;
        else cout<<dis[d]<<endl;
    }
    return 0;
}
