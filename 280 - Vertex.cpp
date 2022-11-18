#include<bits/stdc++.h>
using namespace std;
int visit[1005];
struct Node
{
    int data;
    struct Node* child;
};

Node *push(Node *head, int data)
{
    Node* newnode= NULL;
    newnode= (struct Node*)malloc(sizeof(struct Node));
    newnode->data= data;
    newnode->child=NULL;
    if(head==NULL)
    {
        return newnode;
    }

    Node * temp =head;
    while(temp->child)temp= temp->child;
    temp->child= newnode;

    return head;
}
void dfs(Node *node[], int s)
{
    for(Node * edge = node[s]; edge; edge= edge->child)
    {
        int v= edge->data;
        if(!visit[v])
        {
            visit[v]=1;
            dfs(node, v);
        }
    }
}
int main()
{

    int n;
    while(cin>>n  && n)
    {

        int s;
        Node* node[n+1]={NULL};

        while(cin>>s && s)
        {
            int u;
            while(cin>>u && u)
            {
               node[s]=push(node[s], u);
            }
        }
        int m;
        cin>>m;
        while(m--)
        {
            cin>>s;
            memset(visit, 0, sizeof(visit));
            dfs(node, s);

            int cnt =0;
            for(int i=1;i<=n;i++)
                if(visit[i]==0)cnt++;

            cout<<cnt;
            for(int i=1;i<=n;i++)
                if(!visit[i])cout<<" "<<i;
            cout<<endl;
        }
    }
    return 0;
}
