#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *child;
};

Node *push(Node *head, int data)
{
    Node* newnode = NULL;
    newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data =data;
    newnode->child= NULL;

    if(head==NULL) return newnode;

    Node* temp = head;
    while(temp->child) temp = temp->child;
    temp->child = newnode;
    return head;
}

int rem=0;
int vis=0;
int visit[200005];
int level[200004];
void dfs(Node *node[], int cnt, int s)
{
     Node *qu =NULL;
     qu = (struct Node*) malloc(sizeof(struct Node));
     qu= push(qu, s);
     level[s]=0;
     vis++;
     visit[s]=1;

     while(qu)
     {
         s= qu->data;
         for(Node *edge= node[s]; edge; edge= edge->child)
         {
             int v= edge->data;
             if(!visit[v] && level[s]+1<=cnt)
             {
                 level[v]= level[s]+1;
                 visit[v]=1;
                 vis++;
                 qu = push(qu, v);
             }

         }
         qu= qu->child;
     }
}

int main()
{

    int n;
    int case_=1;
    //freopen("input.txt", "r", stdin);
    while(cin>>n && n)
    {
        Node *node[200005]={NULL};
        int nd[200004]={0};
        int u, v;
        rem =0;


        for(int i=0;i<n;i++)
        {
            cin>>u>>v;
            node[u] = push(node[u], v);
            node[v] = push(node[v], u);
            if(!nd[u]){ nd[u]=1;rem++;}
            if(!nd[v]){ nd[v]=1;rem++;}
        }

       int q, s, t;

       while(cin>>s>>t)
       {
           if(s==0 && t==0)break;
           vis =0;
           dfs(node, t, s);
           memset(visit, 0 , sizeof(visit));
           memset(level, 0, sizeof(level));
           cout<<"Case "<<case_++<<": "<<rem-vis<<" nodes not reachable from node "<<s<<" with TTL = "<<t<<"."<<endl;
       }

    }

    return 0;
}
