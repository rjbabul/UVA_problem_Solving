#include<bits/stdc++.h>
using namespace std;
int mx =0,d;
int visit[25002], level[25002],emp[25002];
struct Node
{
    int data;
    struct Node *child;
};

Node *push(Node *head, int data)
{
    Node *newnode = NULL;
    newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->child= NULL;

    if(head ==NULL) return newnode;

    Node* temp = head;
    while(temp->child)temp= temp->child;
    temp->child= newnode;

    return head;
}

void bfs(Node *node[], int s)
{

    Node * qu = NULL;
    //qu= (struct Node*)malloc(sizeof(struct Node));
    qu =push(qu, s);
    level[s]=0;

    visit[s]=1;
    mx=0;
    while(qu)
    {
        s = qu->data;
        for(Node *edge =node[s]; edge ; edge= edge->child)
        {
            int v= edge->data;
            if(!visit[v])
            {
                level[v]=level[s]+1;
                emp[level[v]]+=1;

                if(emp[level[v]]>mx)
                {
                    mx= emp[level[v]];
                    d= level[v];
                }
                visit[v]=1;
                qu  =push(qu, v);
            }
        }

        qu= qu->child;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n,m,x;
    while(cin>>n)
    {
        Node *node[25002]={NULL};
        int i;
        for(i=0;i<n;i++)
        {
            cin>>m;

            while(m-- && cin>>x)
            {
                node[i]= push(node[i],x);
            }
        }
        cin>>m;
        while(m-- && cin>>x)
        {
            memset(visit, 0, sizeof(visit));
            memset(emp, 0, sizeof(emp));
            memset(level , 0, sizeof(level));
            mx=0;
            bfs(node, x);
            if(mx==0)cout<<mx<<endl;
            else cout<<mx<<" "<<d<<endl;
        }
    }
    return 0;
}
